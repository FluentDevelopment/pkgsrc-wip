# $NetBSD: Makefile,v 1.29 2017/01/21 20:06:45 ryoon Exp $

DISTNAME=	qtmultimedia-opensource-src-${QTVERSION}
PKGNAME=	qt5-qtmultimedia-${QTVERSION}
COMMENT=	Qt5 module for multimedia

BUILD_TARGET=		sub-src
MAKE_ENV+=		QTDIR=${QTDIR}
INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}
INSTALLATION_DIRS+=	lib/pkgconfig

.include "../../wip/qt5-qtbase58/Makefile.common"

.if ${OPSYS} != "Darwin"
MAKE_ENV+=		LFLAGS=${COMPILER_RPATH_FLAG}${PREFIX}/lib/pulseaudio
.endif

post-install:
.for i in Qt5Multimedia.pc Qt5MultimediaQuick_p.pc Qt5MultimediaWidgets.pc
	cd ${DESTDIR}${PREFIX}/lib/pkgconfig && \
	ln -f -s ${QTPREFIX}/lib/pkgconfig/${i} ${i}
.endfor

PLIST_VARS+=		alsa
.if ${OPSYS} == "Linux"
.include "../../audio/alsa-lib/buildlink3.mk"
PLIST.alsa=		yes
.endif

.if ${OPSYS} != "Darwin"
.include "../../audio/openal-soft/buildlink3.mk"
.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.endif
.include "../../wip/qt5-qtdeclarative58/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
