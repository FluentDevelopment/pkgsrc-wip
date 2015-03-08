$NetBSD: patch-cmake_BTDocumentation.cmake,v 1.1 2015/02/13 15:18:00 nros Exp $
* install docs in share/doc/${PKGBASE}
--- cmake/BTDocumentation.cmake.orig	2014-07-05 14:29:03.000000000 +0000
+++ cmake/BTDocumentation.cmake
@@ -3,10 +3,10 @@ FILE(GLOB INSTALL_HANDBOOK_IMAGES "${CMA
 FOREACH(HANDBOOK_LOCALE_LANG ${HANDBOOK_LOCALE_LANGS} "en")
     FILE(GLOB INSTALL_HANDBOOK_HTML_FILES_${HANDBOOK_LOCALE_LANG} "${CMAKE_CURRENT_SOURCE_DIR}/docs/handbook/${HANDBOOK_LOCALE_LANG}/html/*.html")
     INSTALL(FILES ${INSTALL_HANDBOOK_HTML_FILES_${HANDBOOK_LOCALE_LANG}}
-        DESTINATION "${BT_SHARE_PATH}/bibletime/docs/handbook/${HANDBOOK_LOCALE_LANG}/"
+        DESTINATION "${BT_SHARE_PATH}/doc/bibletime/handbook/${HANDBOOK_LOCALE_LANG}/"
     )
     INSTALL(FILES ${INSTALL_HANDBOOK_IMAGES}
-        DESTINATION "${BT_SHARE_PATH}/bibletime/docs/handbook/${HANDBOOK_LOCALE_LANG}/"
+        DESTINATION "${BT_SHARE_PATH}/doc/bibletime/handbook/${HANDBOOK_LOCALE_LANG}/"
     )
 ENDFOREACH(HANDBOOK_LOCALE_LANG ${HANDBOOK_LOCALE_LANGS} "en")
 
@@ -14,7 +14,7 @@ ENDFOREACH(HANDBOOK_LOCALE_LANG ${HANDBO
 FOREACH(HOWTO_LOCALE_LANG ${HOWTO_LOCALE_LANGS} "en")
     FILE(GLOB INSTALL_HOWTO_HTML_FILES_${HOWTO_LOCALE_LANG} "${CMAKE_CURRENT_SOURCE_DIR}/docs/howto/${HOWTO_LOCALE_LANG}/html/*.html")
     INSTALL(FILES ${INSTALL_HOWTO_HTML_FILES_${HOWTO_LOCALE_LANG}}
-        DESTINATION "${BT_SHARE_PATH}/bibletime/docs/howto/${HOWTO_LOCALE_LANG}/"
+        DESTINATION "${BT_SHARE_PATH}/doc/bibletime/howto/${HOWTO_LOCALE_LANG}/"
     )
 ENDFOREACH(HOWTO_LOCALE_LANG ${HOWTO_LOCALE_LANGS} "en")
 