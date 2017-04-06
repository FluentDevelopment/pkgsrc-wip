# $NetBSD$

DISTNAME=	gollum-lib-4.2.3
CATEGORIES=	www

MAINTAINER=	timshel@fluentdevelopment.com.au
HOMEPAGE=	https://github.com/gollum/gollum/wiki
COMMENT=	A simple, Git-powered wiki with a sweet API and local frontend
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-gemojione>=3.2<4:../../wip/ruby-gemojione
DEPENDS+=	${RUBY_PKGPREFIX}-github-markup>=1.6<2:../../wip/ruby-github-markup
DEPENDS+=	${RUBY_PKGPREFIX}-gollum-grit_adapter1>=1<2:../../wip/ruby-gollum-grit_adapter1
DEPENDS+=	${RUBY_PKGPREFIX}-nokogiri16>=1.6.4<1.7:../../wip/ruby-nokogiri16
DEPENDS+=	${RUBY_PKGPREFIX}-rouge>=2.0<3:../../wip/ruby-rouge
DEPENDS+=	${RUBY_PKGPREFIX}-sanitize2>=2.1<3:../../wip/ruby-sanitize2
DEPENDS+=	${RUBY_PKGPREFIX}-stringex>=2.6<3:../../wip/ruby-stringex

RUBY_RDOC_REQD=	3.0

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
