# $NetBSD$

DISTNAME=	gollum-4.0.1
CATEGORIES=	www

MAINTAINER=	timshel@fluentdevelopment.com.au
HOMEPAGE=	https://github.com/gollum/gollum/wiki
COMMENT=	A simple, Git-powered wiki with a sweet API and local frontend
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-gollum-lib>=4.0.1<5:../../wip/ruby-gollum-lib
DEPENDS+=	${RUBY_PKGPREFIX}-kramdown>=1.8<2:../../textproc/ruby-kramdown
DEPENDS+=	${RUBY_PKGPREFIX}-mustache>=0.99.8:../../wip/ruby-mustache
DEPENDS+=	${RUBY_PKGPREFIX}-sinatra>=1.4.4:../../www/ruby-sinatra
DEPENDS+=	${RUBY_PKGPREFIX}-useragent>=0.14.0:../../wip/ruby-useragent

RUBY_RDOC_REQD=	3.0

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
