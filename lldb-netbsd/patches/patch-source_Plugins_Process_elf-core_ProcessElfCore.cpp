$NetBSD$

--- source/Plugins/Process/elf-core/ProcessElfCore.cpp.orig	2017-04-07 18:27:43.000000000 +0000
+++ source/Plugins/Process/elf-core/ProcessElfCore.cpp
@@ -19,6 +19,7 @@
 #include "lldb/Core/PluginManager.h"
 #include "lldb/Core/Section.h"
 #include "lldb/Core/State.h"
+#include "lldb/Host/StringConvert.h"
 #include "lldb/Target/DynamicLoader.h"
 #include "lldb/Target/MemoryRegionInfo.h"
 #include "lldb/Target/Target.h"
@@ -27,6 +28,7 @@
 #include "lldb/Utility/DataBufferLLVM.h"
 #include "lldb/Utility/Log.h"
 
+#include "llvm/ADT/StringRef.h"
 #include "llvm/Support/ELF.h"
 #include "llvm/Support/Threading.h"
 
@@ -219,7 +221,7 @@ Status ProcessElfCore::DoLoadCore() {
   ArchSpec core_arch(m_core_module_sp->GetArchitecture());
   target_arch.MergeFrom(core_arch);
   GetTarget().SetArchitecture(target_arch);
- 
+
   SetUnixSignals(UnixSignals::Create(GetArchitecture()));
 
   // Ensure we found at least one thread that was stopped on a signal.
@@ -373,7 +375,8 @@ size_t ProcessElfCore::DoReadMemory(lldb
   lldb::addr_t bytes_left =
       0; // Number of bytes available in the core file from the given address
 
-  // Don't proceed if core file doesn't contain the actual data for this address range.
+  // Don't proceed if core file doesn't contain the actual data for this address
+  // range.
   if (file_start == file_end)
     return 0;
 
@@ -458,9 +461,14 @@ enum {
 
 namespace NETBSD {
 
-enum { NT_PROCINFO = 1, NT_AUXV, NT_AMD64_REGS = 33, NT_AMD64_FPREGS = 35 };
+enum { NT_PROCINFO = 1, NT_PROCINFO_SIZE = 160, NT_AUXV = 2 };
+
+namespace AMD64 {
+enum { NT_REGS = 33, NT_FPREGS = 35 };
 }
 
+} // namespace NETBSD
+
 // Parse a FreeBSD NT_PRSTATUS note - see FreeBSD sys/procfs.h for details.
 static void ParseFreeBSDPrStatus(ThreadData &thread_data, DataExtractor &data,
                                  ArchSpec &arch) {
@@ -497,15 +505,29 @@ static void ParseFreeBSDThrMisc(ThreadDa
   thread_data.name = data.GetCStr(&offset, 20);
 }
 
-static void ParseNetBSDProcInfo(ThreadData &thread_data, DataExtractor &data) {
+static Status ParseNetBSDProcInfo(DataExtractor &data, uint32_t &cpi_nlwps,
+                                 uint32_t &cpi_signo, uint32_t &cpi_siglwp) {
   lldb::offset_t offset = 0;
 
-  int version = data.GetU32(&offset);
+  uint32_t version = data.GetU32(&offset);
   if (version != 1)
-    return;
+    return Status(
+        "Status parsing NetBSD core(5) notes: Unsupported procinfo version");
 
-  offset += 4;
-  thread_data.signo = data.GetU32(&offset);
+  uint32_t cpisize = data.GetU32(&offset);
+  if (cpisize != NETBSD::NT_PROCINFO_SIZE)
+    return Status(
+        "Status parsing NetBSD core(5) notes: Unsupported procinfo size");
+
+  cpi_signo = data.GetU32(&offset); /* killing signal */
+
+  offset += 108;
+  cpi_nlwps = data.GetU32(&offset); /* number of LWPs */
+
+  offset += 32;
+  cpi_siglwp = data.GetU32(&offset); /* LWP target of killing signal */
+
+  return Status();
 }
 
 static void ParseOpenBSDProcInfo(ThreadData &thread_data, DataExtractor &data) {
@@ -524,12 +546,28 @@ static void ParseOpenBSDProcInfo(ThreadD
 /// 1) A PT_NOTE segment is composed of one or more NOTE entries.
 /// 2) NOTE Entry contains a standard header followed by variable size data.
 ///   (see ELFNote structure)
-/// 3) A Thread Context in a core file usually described by 3 NOTE entries.
+Status ProcessElfCore::ParseThreadContextsFromNoteSegment(
+    const elf::ELFProgramHeader *segment_header, DataExtractor segment_data) {
+
+  assert(segment_header && segment_header->p_type == llvm::ELF::PT_NOTE);
+
+  switch (GetArchitecture().GetTriple().getOS()) {
+  case llvm::Triple::NetBSD:
+    return ParseThreadContextsFromNoteSegmentNetBSD(segment_header,
+                                                    segment_data);
+  default:
+    return ParseThreadContextsFromNoteSegmentGeneric(segment_header,
+                                                     segment_data);
+  }
+}
+
+/// Generic (Linux, Android, FreeBSD, ...) Thread context from PT_NOTE segment
+/// 1) A Thread Context in a core file usually described by 3 NOTE entries.
 ///    a) NT_PRSTATUS - Register context
 ///    b) NT_PRPSINFO - Process info(pid..)
 ///    c) NT_FPREGSET - Floating point registers
-/// 4) The NOTE entries can be in any order
-/// 5) If a core file contains multiple thread contexts then there is two data
+/// 2) The NOTE entries can be in any order
+/// 3) If a core file contains multiple thread contexts then there is two data
 /// forms
 ///    a) Each thread context(2 or more NOTE entries) contained in its own
 ///    segment (PT_NOTE)
@@ -540,8 +578,9 @@ static void ParseOpenBSDProcInfo(ThreadD
 ///        new thread when it finds NT_PRSTATUS or NT_PRPSINFO NOTE entry.
 ///    For case (b) there may be either one NT_PRPSINFO per thread, or a single
 ///    one that applies to all threads (depending on the platform type).
-Status ProcessElfCore::ParseThreadContextsFromNoteSegment(
+Status ProcessElfCore::ParseThreadContextsFromNoteSegmentGeneric(
     const elf::ELFProgramHeader *segment_header, DataExtractor segment_data) {
+
   assert(segment_header && segment_header->p_type == llvm::ELF::PT_NOTE);
 
   lldb::offset_t offset = 0;
@@ -607,21 +646,6 @@ Status ProcessElfCore::ParseThreadContext
       default:
         break;
       }
-    } else if (note.n_name.substr(0, 11) == "NetBSD-CORE") {
-      // NetBSD per-thread information is stored in notes named
-      // "NetBSD-CORE@nnn" so match on the initial part of the string.
-      m_os = llvm::Triple::NetBSD;
-      if (note.n_type == NETBSD::NT_PROCINFO) {
-        ParseNetBSDProcInfo(*thread_data, note_data);
-      } else if (note.n_type == NETBSD::NT_AUXV) {
-        m_auxv = DataExtractor(note_data);
-      } else if (arch.GetMachine() == llvm::Triple::x86_64 &&
-                 note.n_type == NETBSD::NT_AMD64_REGS) {
-        thread_data->gpregset = note_data;
-      } else if (arch.GetMachine() == llvm::Triple::x86_64 &&
-                 note.n_type == NETBSD::NT_AMD64_FPREGS) {
-        thread_data->fpregset = note_data;
-      }
     } else if (note.n_name.substr(0, 7) == "OpenBSD") {
       // OpenBSD per-thread information is stored in notes named
       // "OpenBSD@nnn" so match on the initial part of the string.
@@ -659,7 +683,7 @@ Status ProcessElfCore::ParseThreadContext
         // The result from FXSAVE is in NT_PRXFPREG for i386 core files
         if (arch.GetCore() == ArchSpec::eCore_x86_64_x86_64)
           thread_data->fpregset = note_data;
-        else if(arch.IsMIPS())
+        else if (arch.IsMIPS())
           thread_data->fpregset = note_data;
         break;
       case NT_PRPSINFO:
@@ -717,6 +741,136 @@ Status ProcessElfCore::ParseThreadContext
   return error;
 }
 
+/// NetBSD specific Thread context from PT_NOTE segment
+///
+/// NetBSD ELF core files use notes to provide information about
+/// the process's state.  The note name is "NetBSD-CORE" for
+/// information that is global to the process, and "NetBSD-CORE@nn",
+/// where "nn" is the lwpid of the LWP that the information belongs
+/// to (such as register state).
+///
+/// NetBSD uses the following note identifiers:
+///
+///      ELF_NOTE_NETBSD_CORE_PROCINFO (value 1)
+///             Note is a "netbsd_elfcore_procinfo" structure.
+///      ELF_NOTE_NETBSD_CORE_AUXV     (value 2; since NetBSD 8.0)
+///             Note is an array of AuxInfo structures.
+///
+/// NetBSD also uses ptrace(2) request numbers (the ones that exist in
+/// machine-dependent space) to identify register info notes.  The
+/// info in such notes is in the same format that ptrace(2) would
+/// export that information.
+///
+/// For more information see /usr/include/sys/exec_elf.h
+///
+Status ProcessElfCore::ParseThreadContextsFromNoteSegmentNetBSD(
+    const elf::ELFProgramHeader *segment_header, DataExtractor segment_data) {
+
+  assert(segment_header && segment_header->p_type == llvm::ELF::PT_NOTE);
+
+  lldb::offset_t offset = 0;
+  ArchSpec arch = GetArchitecture();
+  m_os = llvm::Triple::NetBSD;
+
+  /*
+   * To be extracted from struct netbsd_elfcore_procinfo
+   * Used to sanity check of the LWPs of the process
+   */
+  uint32_t nlwps = 0;
+  uint32_t signo;  /* killing signal */
+  uint32_t siglwp; /* LWP target of killing signal */
+
+  while (offset < segment_header->p_filesz) {
+    ELFNote note = ELFNote();
+    note.Parse(segment_data, &offset);
+
+    size_t note_start, note_size;
+    note_start = offset;
+    note_size = llvm::alignTo(note.n_descsz, 4);
+
+    // Store the NOTE information in the current thread
+    DataExtractor note_data(segment_data, note_start, note_size);
+    note_data.SetAddressByteSize(
+        m_core_module_sp->GetArchitecture().GetAddressByteSize());
+
+    llvm::StringRef name = note.n_name;
+
+    if (name == "NetBSD-CORE") {
+      if (note.n_type == NETBSD::NT_PROCINFO) {
+        Status error = ParseNetBSDProcInfo(note_data, nlwps, signo, siglwp);
+        if (error.Fail())
+          return error;
+      } else if (note.n_type == NETBSD::NT_AUXV) {
+        m_auxv = DataExtractor(note_data);
+      }
+    } else if (name.consume_front("NetBSD-CORE@")) {
+      lldb::tid_t tid;
+      if (name.getAsInteger(10, tid))
+        return Status("Status parsing NetBSD core(5) notes: Cannot convert "
+                     "LWP ID to integer");
+
+      switch (arch.GetMachine()) {
+      case llvm::Triple::x86_64: {
+        /* Assume order PT_GETREGS, PT_GETFPREGS */
+        if (note.n_type == NETBSD::AMD64::NT_REGS) {
+          m_thread_data.push_back(ThreadData());
+          m_thread_data.back().gpregset = note_data;
+          m_thread_data.back().tid = tid;
+        } else if (note.n_type == NETBSD::AMD64::NT_FPREGS) {
+          if (m_thread_data.empty() || tid != m_thread_data.back().tid)
+            return Status("Error parsing NetBSD core(5) notes: Unexpected order "
+                         "of NOTEs PT_GETFPREG before PT_GETREG");
+          m_thread_data.back().fpregset = note_data;
+        } else {
+          return Status(
+              "Error parsing NetBSD core(5) notes: Unsupported AMD64 NOTE");
+        }
+      } break;
+      default:
+        return Status(
+            "Error parsing NetBSD core(5) notes: Unsupported architecture");
+      }
+    } else {
+      return Status("Error parsing NetBSD core(5) notes: Unrecognized note");
+    }
+
+    offset += note_size;
+  }
+
+  if (m_thread_data.empty())
+    return Status("Error parsing NetBSD core(5) notes: No threads information "
+                 "specified in notes");
+
+  if (m_thread_data.size() != nlwps)
+    return Status("rror parsing NetBSD core(5) notes: Mismatch between the "
+                 "number of LWPs in netbsd_elfcore_procinfo and the number of "
+                 "LWPs specified by MD notes");
+
+  /* The whole process signal */
+  if (siglwp == 0) {
+    for (auto &data : m_thread_data)
+      data.signo = signo;
+  }
+  /* Signal destinated for a particular LWP */
+  else {
+    bool passed = false;
+
+    for (auto &data : m_thread_data) {
+      if (data.tid == siglwp) {
+        data.signo = signo;
+        passed = true;
+        break;
+      }
+    }
+
+    if (!passed)
+      return Status(
+          "Error parsing NetBSD core(5) notes: Signal passed to unknown LWP");
+  }
+
+  return Status();
+}
+
 uint32_t ProcessElfCore::GetNumThreadContexts() {
   if (!m_thread_data_valid)
     DoLoadCore();
@@ -730,7 +884,7 @@ ArchSpec ProcessElfCore::GetArchitecture
   core_file->GetArchitecture(arch);
 
   ArchSpec target_arch = GetTarget().GetArchitecture();
-  
+
   if (target_arch.IsMIPS())
     return target_arch;
 
