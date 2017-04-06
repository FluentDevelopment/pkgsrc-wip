# $NetBSD$

DISTNAME=	gollum-4.1.0
CATEGORIES=	www

MAINTAINER=	timshel@fluentdevelopment.com.au
HOMEPAGE=	https://github.com/gollum/gollum/wiki
COMMENT=	A simple, Git-powered wiki with a sweet API and local frontend
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-gemojione2>=2<3:../../wip/ruby-gemojione2
DEPENDS+=	${RUBY_PKGPREFIX}-gollum-lib>=4.0.1<5:../../wip/ruby-gollum-lib
DEPENDS+=	${RUBY_PKGPREFIX}-kramdown19>=1.9<1.10:../../wip/ruby-kramdown19
DEPENDS+=	${RUBY_PKGPREFIX}-mustache099>=0.99.5<1:../../wip/ruby-mustache099
DEPENDS+=	${RUBY_PKGPREFIX}-sinatra>=1.4.4<1.5:../../www/ruby-sinatra
DEPENDS+=	${RUBY_PKGPREFIX}-useragent>=0.16.0<0.17:../../wip/ruby-useragent

RUBY_RDOC_REQD=	3.0

OVERRIDE_GEMSPEC+= :executables gollum=${GOLLUMBIN} \
		:files bin/gollum=bin/${GOLLUMBIN}

GOLLUMBIN?=	gollum${RUBY_SUFFIX}

pre-configure:
	cd ${WRKSRC}/bin && ${MV} gollum ${GOLLUMBIN}

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
