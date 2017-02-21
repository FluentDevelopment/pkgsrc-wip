# $NetBSD$

DISTNAME=	sssd-1.11.7
CATEGORIES=	wip
MASTER_SITES=	https://fedorahosted.org/released/sssd/
MASTER_SITES+=	http://mirrors.rit.edu/zi/

MAINTAINER=	timshel@fluentdevelopment.com.au
HOMEPAGE=	https://fedorahosted.org/sssd/
COMMENT=	System Security Services Daemon
LICENSE=	gnu-gpl-v3

BUILD_DEPENDS+=		libxml2-[0-9]*:../../textproc/libxml2 # for xmlcatalog
BUILD_DEPENDS+=		docbook-xsl-[0-9]*:../../textproc/docbook-xsl
BUILD_DEPENDS+=		docbook-xsl-[0-9]*:../../textproc/docbook-xsl
BUILD_DEPENDS+=		xmlcatmgr-[0-9]*:../../textproc/xmlcatmgr
BUILD_DEPENDS+=		libxslt-[0-9]*:../../textproc/libxslt # for xsltproc
BUILD_DEPENDS+=		bind>=9.10<9.11:../../net/bind910 # for nsupdate

EXTRACT_USING=		gtar
GNU_CONFIGURE=          yes
WRKSRC=			${WRKDIR} # More than one possibility -- please check manually.
USE_TOOLS+=		gmake pkg-config
USE_PKGLOCALEDIR=	yes

PKGCONFIG_OVERRIDE+=	sssd-1.11.7/src/providers/ipa/PaxHeaders.14471/ipa_hbac.pc.in
PKGCONFIG_OVERRIDE+=	sssd-1.11.7/src/providers/ipa/ipa_hbac.pc.in
PKGCONFIG_OVERRIDE+=	sssd-1.11.7/src/lib/idmap/PaxHeaders.14471/sss_idmap.pc.in
PKGCONFIG_OVERRIDE+=	sssd-1.11.7/src/lib/idmap/sss_idmap.pc.in
PKGCONFIG_OVERRIDE+=	sssd-1.11.7/src/sss_client/idmap/PaxHeaders.14471/sss_nss_idmap.pc.in
PKGCONFIG_OVERRIDE+=	sssd-1.11.7/src/sss_client/idmap/sss_nss_idmap.pc.in

CONFIGURE_ARGS+=	--with-selinux=no
CONFIGURE_ARGS+=	--with-semanage=no
CONFIGURE_ARGS+=	--with-ldb-lib-dir=${LOCALBASE}/lib/shared-modules/ldb
CONFIGURE_ARGS+=	--with-xml-catalog-path=${LOCALBASE}/share/xml/catalog
CONFIGURE_ARGS+=	--with-libnl=no
CONFIGURE_ARGS+=	--with-init-dir=no
CONFIGURE_ARGS+=	--datadir=${DATADIR}
CONFIGURE_ARGS+=	--docdir=${DOCSDIR}
CONFIGURE_ARGS+=	--with-pid-path=/var/run
CONFIGURE_ARGS+=	--localstatedir=/var
CONFIGURE_ARGS+=	--enable-pammoddir=${PREFIX}/lib
CONFIGURE_ARGS+=	--with-db-path=/var/db/sss
CONFIGURE_ARGS+=	--with-pipe-path=/var/run/sss
CONFIGURE_ARGS+=	--with-pubconf-path=/var/run/sss
CONFIGURE_ARGS+=	--with-mcache-path=/var/db/sss_mc
CONFIGURE_ARGS+=	--with-unicode-lib=libunistring
CONFIGURE_ARGS+=	--with-autofs=no
CONFIGURE_ARGS+=	--disable-cifs-idmap-plugin
CONFIGURE_ARGS+=	--disable-config-lib

MAKE_ENV+=      LINGUAS="bg de eu es fr hu id it ja nb nl pl pt ru sv tg tr uk zh_CN zh_TW"

.include "../../devel/popt/buildlink3.mk"
.include "../../devel/talloc/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../databases/tdb/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../textproc/libunistring/buildlink3.mk"
.include "../../devel/nss/buildlink3.mk"
.include "../../security/cyrus-sasl/buildlink3.mk"
.include "../../devel/libinotify/buildlink3.mk"

.include "../../mk/krb5.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
