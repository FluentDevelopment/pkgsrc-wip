$NetBSD$

--- content/public/common/renderer_preferences.h.orig	2017-02-02 02:02:54.000000000 +0000
+++ content/public/common/renderer_preferences.h
@@ -139,7 +139,7 @@ struct CONTENT_EXPORT RendererPreference
   // Country iso of the mobile network for content detection purpose.
   std::string network_contry_iso;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   std::string system_font_family_name;
 #endif
 
