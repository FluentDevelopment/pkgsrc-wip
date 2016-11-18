# $NetBSD$

DISTNAME=	gollum-grit_adapter-2.0.0
CATEGORIES=	www

MAINTAINER=	timshel@fluentdevelopment.com.au
HOMEPAGE=	https://github.com/gollum/grit_adapter
COMMENT=	Adapter for gollum to use Grit at the backend
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-gitlab-grit>=2.8.1<2.9:../../wip/ruby-gitlab-grit
DEPENDS+=	${RUBY_PKGPREFIX}-rspec>=3.4.0<3.5:../../devel/ruby-rspec

RUBY_RDOC_REQD=	3.0

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
