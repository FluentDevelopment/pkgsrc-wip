# $NetBSD$
#
###########################################################
#                  Generated by fbsd2pkg                  #
#              Sun May  1 07:19:47 CDT 2016               #
###########################################################
# Test new versions with Trinity before upgrading

#DISTVERSIONPREFIX=v

DISTNAME=	rsem-${PORTVERSION}
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=deweylab/}
GITHUB_PROJECT=	RSEM
GITHUB_TAG=	v${PORTVERSION}

MAINTAINER=	bacon4000@gmail.com
HOMEPAGE=	http://deweylab.biostat.wisc.edu/rsem/README.html
COMMENT=	RNA-Seq by Expectation-Maximization
LICENSE=	gnu-gpl-v3

# Test and change if necessary.
# MAKE_JOBS_SAFE=	no

USE_LANGUAGES=	c c++
# Gmake is for bundled samtools, which contains modifications for rsem.
# Should be unbundled in the future.
USE_TOOLS+=	gmake perl:run
REPLACE_PERL=	convert-sam-for-rsem \
                extract-transcript-to-gene-map-from-trinity \
                rsem-calculate-expression \
                rsem-control-fdr \
                rsem-generate-data-matrix \
                rsem-generate-ngvector \
                rsem-plot-transcript-wiggles \
                rsem-prepare-reference \
                rsem-run-ebseq \
                rsem_perl_utils.pm
REPLACE_PYTHON=	rsem-refseq-extract-primary-assembly \
		rsem-gff3-to-gtf

SUBST_CLASSES+=		rscript
SUBST_STAGE.rscript=	post-patch
SUBST_SED.rscript=	-e "s|\#!/usr/bin/env Rscript|${PREFIX}/bin/Rscript|g"
SUBST_FILES.rscript=	rsem-gen-transcript-plots \
			rsem-plot-model

SUBST_CLASSES+=		siteperl
SUBST_STAGE.siteperl=	post-patch
SUBST_SED.siteperl+=	-e 's|use lib $$FindBin::RealBin|use lib "${SITE_PERL}"|'
SUBST_FILES.siteperl+=	${WRKSRC}/rsem*

# Make sure all rsem programs use libexec/rsem/samtools
SUBST_CLASSES+=		samdir
SUBST_STAGE.samdir=	post-patch
SUBST_SED.samdir+=	-e 's|samtools|${PREFIX}/libexec/rsem/samtools|g'
SUBST_FILES.samdir+=	${WRKSRC}/rsem-calculate-expression
SUBST_FILES.samdir+=	${WRKSRC}/rsem-plot-transcript-wiggles

WRKSRC=		${WRKDIR}/RSEM-${PORTVERSION}
MAKE_ENV=	libexecdir=${PREFIX}/libexec \
		perl_mod_dir=${SITE_PERL}

PORTVERSION=	1.2.30
SITE_PERL=	${PREFIX}/share/rsem

post-install:
	${RM} -rf ${DESTDIR}${PREFIX}/bin/samtools-*

.include "../../math/R/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
