# $NetBSD$

DISTNAME=	bcolz-0.12.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=b/bcolz/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/Blosc/bcolz
COMMENT=	Columnar and compressed data containers
LICENSE=	modified-bsd

USE_LANGUAGES=	c c++

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/egg.mk"
BUILDLINK_API_DEPENDS.py-numpy+=	${PYPKGPREFIX}-numpy>=1.7
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
