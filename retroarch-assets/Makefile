# $NetBSD$

DISTNAME=		retroarch-assets-20170508
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_GITHUB:=libretro/}
COMMENT=		Assets for RetroArch
#LICENSE=		cc-by-v4.0

GITHUB_TAG=		92c58f06ce92e5bb5df17b1dc8ab4844eb839fd5

USE_LANGUAGES=		# none
NO_BUILD=		yes

RA_ASSET_DIRS+=		branding
RA_ASSET_DIRS+=		glui
RA_ASSET_DIRS+=		xmb
RA_ASSET_DIRS+=		xmb/dot-art
RA_ASSET_DIRS+=		xmb/dot-art/png
RA_ASSET_DIRS+=		xmb/flatui
RA_ASSET_DIRS+=		xmb/flatui/png
RA_ASSET_DIRS+=		xmb/monochrome
RA_ASSET_DIRS+=		xmb/monochrome/png
RA_ASSET_DIRS+=		xmb/neoactive
RA_ASSET_DIRS+=		xmb/neoactive/png
RA_ASSET_DIRS+=		xmb/pixel
RA_ASSET_DIRS+=		xmb/pixel/png
RA_ASSET_DIRS+=		xmb/retroactive
RA_ASSET_DIRS+=		xmb/retroactive/png
RA_ASSET_DIRS+=		xmb/systematic
RA_ASSET_DIRS+=		xmb/systematic/png

.for i in ${RA_ASSET_DIRS}
INSTALLATION_DIRS+=	share/retroarch/assets/${i}
.endfor

do-install:
.for dir in ${RA_ASSET_DIRS}
.for type in ttf png
	if ${LS} -1 ${WRKSRC}/${dir} | ${GREP} -q .${type}$$; then \
		${INSTALL_DATA} ${WRKSRC}/${dir}/*.${type} \
		    ${DESTDIR}${PREFIX}/share/retroarch/assets/${dir}; fi
.endfor
.endfor

.include "../../mk/bsd.pkg.mk"
