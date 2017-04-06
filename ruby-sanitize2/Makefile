# $NetBSD$

DISTNAME=	sanitize-2.1.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/sanitize/sanitize2/}
CATEGORIES=	textproc

MAINTAINER=	timshel@fluentdevelopment.com.au
HOMEPAGE=	https://github.com/rgrove/sanitize/
COMMENT=	Sanitize is a whitelist-based HTML and CSS sanitizer
LICENSE=	mit

DEPENDS+=       ${RUBY_PKGPREFIX}-nokogiri16>=1.4.4:../../wip/ruby-nokogiri16

RUBY_RDOC_REQD=	3.0

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
