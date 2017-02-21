# $NetBSD$

DISTNAME=	sssd-1.11.7
CATEGORIES=	wip
MASTER_SITES=	https://fedorahosted.org/released/sssd/
MASTER_SITES+=	http://mirrors.rit.edu/zi/

MAINTAINER=	timshel@fluentdevelopment.com.au
HOMEPAGE=	https://fedorahosted.org/sssd/
COMMENT=	System Security Services Daemon
LICENSE=	gnu-gpl-v3

MAKE_ENV+=      LINGUAS="bg de eu es fr hu id it ja nb nl pl pt ru sv tg tr uk zh_CN zh_TW"


WRKSRC=			${WRKDIR} # More than one possibility -- please check manually.
USE_TOOLS+=		pkg-config
USE_TOOLS+=		gnutar
USE_PKGLOCALEDIR=	yes

PKGCONFIG_OVERRIDE+=	sssd-1.11.7/src/providers/ipa/PaxHeaders.14471/ipa_hbac.pc.in
PKGCONFIG_OVERRIDE+=	sssd-1.11.7/src/providers/ipa/ipa_hbac.pc.in
PKGCONFIG_OVERRIDE+=	sssd-1.11.7/src/lib/idmap/PaxHeaders.14471/sss_idmap.pc.in
PKGCONFIG_OVERRIDE+=	sssd-1.11.7/src/lib/idmap/sss_idmap.pc.in
PKGCONFIG_OVERRIDE+=	sssd-1.11.7/src/sss_client/idmap/PaxHeaders.14471/sss_nss_idmap.pc.in
PKGCONFIG_OVERRIDE+=	sssd-1.11.7/src/sss_client/idmap/sss_nss_idmap.pc.in

.include "../../mk/bsd.pkg.mk"
