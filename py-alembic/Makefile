# $NetBSD: Makefile,v 1.1 2015/02/22 22:01:11 jihbed Exp $

DISTNAME=	alembic-0.9.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/alembic/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://bitbucket.org/zzzeek/alembic
COMMENT=	Database migration tool for SQLAlchemy
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-editor>=0.3:../../wip/py-editor
DEPENDS+=	${PYPKGPREFIX}-mako>=0.8.1:../../devel/py-mako
DEPENDS+=	${PYPKGPREFIX}-nose>=1.3.0:../../devel/py-nose
DEPENDS+=	${PYPKGPREFIX}-sqlalchemy>=0.9.8:../../databases/py-sqlalchemy

USE_LANGUAGES=	# none

do-test:
	${RUN} cd ${WRKSRC}; ${SETENV} ${TEST_ENV} ${PYTHONBIN} run_tests.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
