# $NetBSD$

DISTNAME=	mustache-0.99.8
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/mustache/mustache099/}
CATEGORIES=	devel

MAINTAINER=	nils@NetBSD.org
HOMEPAGE=	https://mustache.github.io/
COMMENT=	Logic-less Ruby templates
LICENSE=	mit

INSTALLATION_DIRS+=		${PKGMANDIR}/man1/ ${PKGMANDIR}/man5/

OVERRIDE_GEMSPEC=       :executables mustache=mustache099 \
                        :files bin/mustache=bin/mustache099
RUBYGEM_OPTIONS+=       --format-executable

pre-configure:
	${TEST} -f ${WRKSRC}/bin/mustache099 || \
		${MV} ${WRKSRC}/bin/mustache ${WRKSRC}/bin/mustache099

post-install:
	${LN} -sf ${PREFIX}/${GEM_LIBDIR}/man/mustache.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/mustache099${RUBY_SUFFIX}.1
	${LN} -sf ${PREFIX}/${GEM_LIBDIR}/man/mustache.5 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5/mustache099${RUBY_SUFFIX}.5

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
