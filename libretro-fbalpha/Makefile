# $NetBSD$

DISTNAME=	libretro-fbalpha-20170415
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}
HOMEPAGE=	https://wiki.libretro.com/index.php?title=Final_Burn_Alpha
COMMENT=	Libretro core based on the FB Alpha arcade emulator
LICENSE=	no-commercial-use

GITHUB_PROJECT=	fbalpha
GITHUB_TAG=	v0.2.97.39

USE_TOOLS=	gmake

MAKE_FILE=	makefile.libretro

USE_LANGUAGES=	c c++

.include "../../mk/endian.mk"

.if ${MACHINE_ENDIAN} == "big"
BUILD_MAKE_FLAGS+=	ENDIANNESS_DEFINES=-DWORDS_BIGENDIAN
.endif

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/fbalpha_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/fbalpha_libretro.so

.include "../../mk/bsd.pkg.mk"
