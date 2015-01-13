$NetBSD: patch-js_src_ctypes_typedefs.h,v 1.1 2015/01/09 10:01:41 thomasklausner Exp $

Fix build on NetBSD
https://bugzilla.mozilla.org/show_bug.cgi?id=1113379

--- js/src/ctypes/typedefs.h.orig	2015-01-09 02:12:41.000000000 +0000
+++ js/src/ctypes/typedefs.h
@@ -5,50 +5,32 @@
 
 /**
  * This header contains the builtin types available for arguments and return
- * values, representing their C counterparts. They are listed inside macros
- * that the #includer is expected to #define. Format is:
+ * values, representing their C counterparts. They are used inside higher-order
+ * macros that the user must call, providing a macro that will consume the
+ * arguments provided to it by the higher-order macro. The macros exposed are:
  *
- * DEFINE_X_TYPE(typename, ctype, ffitype)
+ *   CTYPES_FOR_EACH_BOOL_TYPE(macro)
+ *   CTYPES_FOR_EACH_CHAR_TYPE(macro)
+ *   CTYPES_FOR_EACH_CHAR16_TYPE(macro)
+ *   CTYPES_FOR_EACH_INT_TYPE(macro)
+ *   CTYPES_FOR_EACH_WRAPPED_INT_TYPE(macro)
+ *   CTYPES_FOR_EACH_FLOAT_TYPE(macro)
+ *   CTYPES_FOR_EACH_TYPE(macro)
+ *
+ * The macro name provided to any of these macros will then be repeatedly
+ * invoked as
+ *
+ *   macro(typename, ctype, ffitype)
  *
  * where 'typename' is the name of the type constructor (accessible as
  * ctypes.typename), 'ctype' is the corresponding C type declaration (from
  * which sizeof(ctype) and templated type conversions will be derived), and
  * 'ffitype' is the ffi_type to use. (Special types, such as 'void' and the
  * pointer, array, and struct types are handled separately.)
- *
- * This header lacks a #ifndef wrapper because it is deliberately #included
- * multiple times in ctypes/CTypes.h.
  */
 
-// If we're not breaking the types out, combine them together under one
-// DEFINE_TYPE macro. Otherwise, turn off whichever ones we're not using.
-#if defined(DEFINE_TYPE)
-#  define DEFINE_CHAR_TYPE(x, y, z)         DEFINE_TYPE(x, y, z)
-#  define DEFINE_CHAR16_TYPE(x, y, z)       DEFINE_TYPE(x, y, z)
-#  define DEFINE_BOOL_TYPE(x, y, z)         DEFINE_TYPE(x, y, z)
-#  define DEFINE_INT_TYPE(x, y, z)          DEFINE_TYPE(x, y, z)
-#  define DEFINE_WRAPPED_INT_TYPE(x, y, z)  DEFINE_TYPE(x, y, z)
-#  define DEFINE_FLOAT_TYPE(x, y, z)        DEFINE_TYPE(x, y, z)
-#else
-#  ifndef DEFINE_BOOL_TYPE
-#    define DEFINE_BOOL_TYPE(x, y, z)
-#  endif
-#  ifndef DEFINE_CHAR_TYPE
-#    define DEFINE_CHAR_TYPE(x, y, z)
-#  endif
-#  ifndef DEFINE_CHAR16_TYPE
-#    define DEFINE_CHAR16_TYPE(x, y, z)
-#  endif
-#  ifndef DEFINE_INT_TYPE
-#    define DEFINE_INT_TYPE(x, y, z)
-#  endif
-#  ifndef DEFINE_WRAPPED_INT_TYPE
-#    define DEFINE_WRAPPED_INT_TYPE(x, y, z)
-#  endif
-#  ifndef DEFINE_FLOAT_TYPE
-#    define DEFINE_FLOAT_TYPE(x, y, z)
-#  endif
-#endif
+#ifndef ctypes_typedefs_h
+#define  ctypes_typedefs_h
 
 // MSVC doesn't have ssize_t. Help it along a little.
 #ifdef HAVE_SSIZE_T
@@ -71,52 +53,54 @@
 #define CTYPES_FFI_INTPTR_T  (sizeof(uintptr_t) == 4 ? ffi_type_sint32 : ffi_type_sint64)
 #define CTYPES_FFI_UINTPTR_T (sizeof(uintptr_t) == 4 ? ffi_type_uint32 : ffi_type_uint64)
 
-// The meat.
-DEFINE_BOOL_TYPE       (bool,               bool,               CTYPES_FFI_BOOL)
-DEFINE_INT_TYPE        (int8_t,             int8_t,             ffi_type_sint8)
-DEFINE_INT_TYPE        (int16_t,            int16_t,            ffi_type_sint16)
-DEFINE_INT_TYPE        (int32_t,            int32_t,            ffi_type_sint32)
-DEFINE_INT_TYPE        (uint8_t,            uint8_t,            ffi_type_uint8)
-DEFINE_INT_TYPE        (uint16_t,           uint16_t,           ffi_type_uint16)
-DEFINE_INT_TYPE        (uint32_t,           uint32_t,           ffi_type_uint32)
-DEFINE_INT_TYPE        (short,              short,              ffi_type_sint16)
-DEFINE_INT_TYPE        (unsigned_short,     unsigned short,     ffi_type_uint16)
-DEFINE_INT_TYPE        (int,                int,                ffi_type_sint32)
-DEFINE_INT_TYPE        (unsigned_int,       unsigned int,       ffi_type_uint32)
-DEFINE_WRAPPED_INT_TYPE(int64_t,            int64_t,            ffi_type_sint64)
-DEFINE_WRAPPED_INT_TYPE(uint64_t,           uint64_t,           ffi_type_uint64)
-DEFINE_WRAPPED_INT_TYPE(long,               long,               CTYPES_FFI_LONG)
-DEFINE_WRAPPED_INT_TYPE(unsigned_long,      unsigned long,      CTYPES_FFI_ULONG)
-DEFINE_WRAPPED_INT_TYPE(long_long,          long long,          ffi_type_sint64)
-DEFINE_WRAPPED_INT_TYPE(unsigned_long_long, unsigned long long, ffi_type_uint64)
-DEFINE_WRAPPED_INT_TYPE(size_t,             size_t,             CTYPES_FFI_SIZE_T)
-DEFINE_WRAPPED_INT_TYPE(ssize_t,            CTYPES_SSIZE_T,     CTYPES_FFI_SSIZE_T)
-DEFINE_WRAPPED_INT_TYPE(off_t,              off_t,              CTYPES_FFI_OFF_T)
-DEFINE_WRAPPED_INT_TYPE(intptr_t,           intptr_t,           CTYPES_FFI_INTPTR_T)
-DEFINE_WRAPPED_INT_TYPE(uintptr_t,          uintptr_t,          CTYPES_FFI_UINTPTR_T)
-DEFINE_FLOAT_TYPE      (float32_t,          float,              ffi_type_float)
-DEFINE_FLOAT_TYPE      (float64_t,          double,             ffi_type_double)
-DEFINE_FLOAT_TYPE      (float,              float,              ffi_type_float)
-DEFINE_FLOAT_TYPE      (double,             double,             ffi_type_double)
-DEFINE_CHAR_TYPE       (char,               char,               ffi_type_uint8)
-DEFINE_CHAR_TYPE       (signed_char,        signed char,        ffi_type_sint8)
-DEFINE_CHAR_TYPE       (unsigned_char,      unsigned char,      ffi_type_uint8)
-DEFINE_CHAR16_TYPE     (char16_t,           char16_t,           ffi_type_uint16)
-
-#undef CTYPES_SSIZE_T
-#undef CTYPES_FFI_BOOL
-#undef CTYPES_FFI_LONG
-#undef CTYPES_FFI_ULONG
-#undef CTYPES_FFI_SIZE_T
-#undef CTYPES_FFI_SSIZE_T
-#undef CTYPES_FFI_INTPTR_T
-#undef CTYPES_FFI_UINTPTR_T
-
-#undef DEFINE_TYPE
-#undef DEFINE_CHAR_TYPE
-#undef DEFINE_CHAR16_TYPE
-#undef DEFINE_BOOL_TYPE
-#undef DEFINE_INT_TYPE
-#undef DEFINE_WRAPPED_INT_TYPE
-#undef DEFINE_FLOAT_TYPE
+#define CTYPES_FOR_EACH_BOOL_TYPE(macro) \
+  macro(bool,               bool,               CTYPES_FFI_BOOL)
+
+#define CTYPES_FOR_EACH_INT_TYPE(macro) \
+  macro(int8_t,             int8_t,             ffi_type_sint8) \
+  macro(int16_t,            int16_t,            ffi_type_sint16) \
+  macro(int32_t,            int32_t,            ffi_type_sint32) \
+  macro(uint8_t,            uint8_t,            ffi_type_uint8) \
+  macro(uint16_t,           uint16_t,           ffi_type_uint16) \
+  macro(uint32_t,           uint32_t,           ffi_type_uint32) \
+  macro(short,              short,              ffi_type_sint16) \
+  macro(unsigned_short,     unsigned short,     ffi_type_uint16) \
+  macro(int,                int,                ffi_type_sint32) \
+  macro(unsigned_int,       unsigned int,       ffi_type_uint32)
+
+#define CTYPES_FOR_EACH_WRAPPED_INT_TYPE(macro) \
+  macro(int64_t,            int64_t,            ffi_type_sint64) \
+  macro(uint64_t,           uint64_t,           ffi_type_uint64) \
+  macro(long,               long,               CTYPES_FFI_LONG) \
+  macro(unsigned_long,      unsigned long,      CTYPES_FFI_ULONG) \
+  macro(long_long,          long long,          ffi_type_sint64) \
+  macro(unsigned_long_long, unsigned long long, ffi_type_uint64) \
+  macro(size_t,             size_t,             CTYPES_FFI_SIZE_T) \
+  macro(ssize_t,            CTYPES_SSIZE_T,     CTYPES_FFI_SSIZE_T) \
+  macro(off_t,              off_t,              CTYPES_FFI_OFF_T) \
+  macro(intptr_t,           intptr_t,           CTYPES_FFI_INTPTR_T) \
+  macro(uintptr_t,          uintptr_t,          CTYPES_FFI_UINTPTR_T)
+
+#define CTYPES_FOR_EACH_FLOAT_TYPE(macro) \
+  macro(float32_t,          float,              ffi_type_float) \
+  macro(float64_t,          double,             ffi_type_double) \
+  macro(float,              float,              ffi_type_float) \
+  macro(double,             double,             ffi_type_double)
+
+#define CTYPES_FOR_EACH_CHAR_TYPE(macro) \
+  macro(char,               char,               ffi_type_uint8) \
+  macro(signed_char,        signed char,        ffi_type_sint8) \
+  macro(unsigned_char,      unsigned char,      ffi_type_uint8)
+
+#define CTYPES_FOR_EACH_CHAR16_TYPE(macro) \
+  macro(char16_t,           char16_t,           ffi_type_uint16)
+
+#define CTYPES_FOR_EACH_TYPE(macro) \
+  CTYPES_FOR_EACH_BOOL_TYPE(macro) \
+  CTYPES_FOR_EACH_INT_TYPE(macro) \
+  CTYPES_FOR_EACH_WRAPPED_INT_TYPE(macro) \
+  CTYPES_FOR_EACH_FLOAT_TYPE(macro) \
+  CTYPES_FOR_EACH_CHAR_TYPE(macro) \
+  CTYPES_FOR_EACH_CHAR16_TYPE(macro)
 
+#endif /* ctypes_typedefs_h */