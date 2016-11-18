# $NetBSD$

DISTNAME=	gitlab-grit-2.8.1
CATEGORIES=	devel

MAINTAINER=	timshel@fluentdevelopment.com.au
HOMEPAGE=	https://gitlab.com/gitlab-org/gitlab-grit
COMMENT=	A simple, Git-powered wiki with a sweet API and local frontend
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-rspec>=3.4<4:../../devel/ruby-rspec

RUBY_RDOC_REQD=	3.0

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
