# $NetBSD: Makefile,v 1.5 2016/06/15 20:10:50 rumko Exp $
#

DISTNAME=	bullet-2.86.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=bulletphysics/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://bulletphysics.org/wordpress/
COMMENT=	Collision detection, soft body and rigid body dynamics library
LICENSE=	mit

GITHUB_PROJECT=	bullet3
GITHUB_TAG=	2.86.1

USE_TOOLS+=	pkg-config
USE_CMAKE=	yes
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	bullet.pc.in
CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE:STRING=Release
CMAKE_ARGS+=	-DBUILD_SHARED_LIBS:BOOL=on
# doesn't install anything without this
CMAKE_ARGS+=	-DINSTALL_LIBS:BOOL=on

CMAKE_ARGS+=	-DBUILD_BULLET2_DEMOS:BOOL=off
CMAKE_ARGS+=	-DBUILD_CPU_DEMOS:BOOL=off
CMAKE_ARGS+=	-DBUILD_OPENGL3_DEMOS:BOOL=off
CMAKE_ARGS+=	-DBUILD_UNIT_TESTS:BOOL=off

.include "../../graphics/glut/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
