# $NetBSD$

DISTNAME=	kramdown-1.9.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/kramdown/kramdown19/}
CATEGORIES=	textproc

MAINTAINER=	timshel@fluentdevelopment.com.au
HOMEPAGE=	http://kramdown.gettalong.org/
COMMENT=	Pure-Ruby Markdown-superset parser and converter
LICENSE=	mit

RUBYGEM_OPTIONS+=	--format-executable

OVERRIDE_GEMSPEC+= :executables kramdown=kramdown19 \
		:files  bin/kramdown=bin/kramdown19

pre-configure:
	cd ${WRKSRC}/bin && ${MV} kramdown kramdown19


.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
