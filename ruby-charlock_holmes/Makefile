# $NetBSD$

DISTNAME=	charlock_holmes-0.7.3
CATEGORIES=	textproc

MAINTAINER=	timshel@fluentdevelopment.com.au
HOMEPAGE=	https://github.com/brianmario/charlock_holmes
COMMENT=	Binary and text detection as well as text transcoding using libicu
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-chardet>=0:../../wip/ruby-charlock_holmes
DEPENDS+=	${RUBY_PKGPREFIX}-minitest>=0:../../devel/ruby-minitest
DEPENDS+=	${RUBY_PKGPREFIX}-rake-compiler>=0.7.5:../../wip/ruby-rake-compiler

USE_LANGUAGES+=	c
USE_LANGUAGES+=	c++

RUBY_RDOC_REQD=	3.0

.include "../../textproc/icu/buildlink3.mk"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
