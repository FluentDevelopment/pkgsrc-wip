# $NetBSD: Makefile,v 1.2 2016/12/16 00:01:04 joerg Exp $
#

PKGNAME=	libpthread_dbg-20161124
CATEGORIES=	pkgtools

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=
COMMENT=	POSIX Debug Threads Library
LICENSE=	original-bsd

USE_BSD_MAKEFILE=	yes
USE_TOOLS=		nroff

INSTALLATION_DIRS+=	include lib ${PKGMANDIR}/man3
PKGSRC_LOCKTYPE=	none	# avoid "bootstrapping problem"

do-extract:
	${CP} -R ${FILESDIR} ${WRKSRC}

# XXX: What's wrong with files/Makefile?
post-install:
	${CP} ${WRKSRC}/pthread_dbg.h ${DESTDIR}${PREFIX}/include

.include "../../mk/bsd.pkg.mk"
