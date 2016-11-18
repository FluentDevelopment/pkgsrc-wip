# $NetBSD$

DISTNAME=	sanitize-4.4.0
CATEGORIES=	textproc

MAINTAINER=	timshel@fluentdevelopment.com.au
HOMEPAGE=	https://github.com/github/markup
COMMENT=	Sanitize is a whitelist-based HTML and CSS sanitizer
LICENSE=	mit

DEPENDS+=       ${RUBY_PKGPREFIX}-crass>=1.0.2<1.1:../../wip/ruby-crass
DEPENDS+=       ${RUBY_PKGPREFIX}-nokogiri>=1.6.7.2<1.7:../../textproc/ruby-nokogiri
DEPENDS+=       ${RUBY_PKGPREFIX}-nokogumbo>=1.4.10<1.5:../../wip/ruby-nokogumbo

RUBY_RDOC_REQD=	3.0

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
