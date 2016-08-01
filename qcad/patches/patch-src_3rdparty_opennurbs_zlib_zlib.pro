$NetBSD$

fix build for pkgsrc, by allowing qmake to link binaries in situ
and create an install target

--- src/3rdparty/opennurbs/zlib/zlib.pro.orig	2016-07-01 07:13:14.000000000 +0000
+++ src/3rdparty/opennurbs/zlib/zlib.pro
@@ -27,7 +27,8 @@ HEADERS += \

 TARGET = zlib
 TEMPLATE = lib
-CONFIG += staticlib
+CONFIG += plugin
+INSTALLS += target
 #win32 {
 #    LIBS += -lRpcrt4 -lAdvapi32
 #}
