# $NetBSD: Makefile,v 1.9 2013/06/17 12:45:11 thomasklausner Exp $
#

DISTNAME=	gnome-keyring-sharp-1.0.0
PKGREVISION=	2
CATEGORIES=	security
MASTER_SITES=	http://ftp.novell.com/pub/mono/sources/gnome-keyring-sharp/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc.gnome@gmail.com
#http://andrew.jorgensenfamily.us/2008/08/gnome-keyring-sharp/
HOMEPAGE=	http://ftp.novell.com/pub/mono/sources/gnome-keyring-sharp/
COMMENT=	Mono implementation of libgnome-keyring

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake pkg-config
USE_LANGUAGES=	# none


PKGCONFIG_OVERRIDE+=	src/gnome-keyring-sharp-1.0.pc.in

CONFIGURE_ARGS+=	--disable-monodoc

.include "options.mk"

.include "../../lang/mono2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
