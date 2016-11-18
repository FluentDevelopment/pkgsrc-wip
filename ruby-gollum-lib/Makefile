# $NetBSD$

DISTNAME=	gollum-lib-4.2.1
CATEGORIES=	www

MAINTAINER=	timshel@fluentdevelopment.com.au
HOMEPAGE=	https://github.com/gollum/gollum/wiki
COMMENT=	A simple, Git-powered wiki with a sweet API and local frontend
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-github-markup>=1.4.0<1.5:../../wip/ruby-github-markup
DEPENDS+=	${RUBY_PKGPREFIX}-gollum-grit_adapter>=2.0.0<3:../../wip/ruby-gollum-grit_adapter
DEPENDS+=	${RUBY_PKGPREFIX}-nokogiri>=1.6.7.2<1.7:../../textproc/ruby-nokogiri
DEPENDS+=	${RUBY_PKGPREFIX}-rouge>=2.0<3:../../wip/ruby-rouge
DEPENDS+=	${RUBY_PKGPREFIX}-sanitize>=4.4.0<4.5:../../wip/ruby-sanitize
DEPENDS+=	${RUBY_PKGPREFIX}-stringex>=2.5.1<3:../../wip/ruby-stringex

RUBY_RDOC_REQD=	3.0

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
