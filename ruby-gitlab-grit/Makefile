# $NetBSD$

DISTNAME=	gitlab-grit-2.8.1
CATEGORIES=	devel

MAINTAINER=	timshel@fluentdevelopment.com.au
HOMEPAGE=	https://gitlab.com/gitlab-org/gitlab-grit
COMMENT=	A simple, Git-powered wiki with a sweet API and local frontend
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-charlock_holmes>=0.6<1:../../wip/ruby-charlock_holmes
DEPENDS+=	${RUBY_PKGPREFIX}-diff-lcs>=1.1<2:../../textproc/ruby-diff-lcs
DEPENDS+=	${RUBY_PKGPREFIX}-mime-types2>=1.16<3:../../mail/ruby-mime-types2
DEPENDS+=	${RUBY_PKGPREFIX}-posix-spawn>=0.3<1:../../devel/ruby-posix-spawn

RUBY_RDOC_REQD=	3.0

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
