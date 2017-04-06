# $NetBSD$

DISTNAME=	gollum-grit_adapter-1.0.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/grit_adapter/grit_adapter1/}
CATEGORIES=	www

MAINTAINER=	timshel@fluentdevelopment.com.au
HOMEPAGE=	https://github.com/gollum/grit_adapter
COMMENT=	Adapter for gollum to use Grit at the backend
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-gitlab-grit>=2.7.1<3:../../wip/ruby-gitlab-grit

RUBY_RDOC_REQD=	3.0

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
