# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/01/12 05:53:43 phonohawk Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
PARSEC_BUILDLINK3_MK:=	${PARSEC_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	parsec
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nparsec}
BUILDLINK_PACKAGES+=	parsec
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}parsec

.if ${PARSEC_BUILDLINK3_MK} == "+"
BUILDLINK_DEPMETHOD.parsec?=	build
BUILDLINK_API_DEPENDS.parsec+=	parsec>=3.0.0
BUILDLINK_PKGSRCDIR.parsec?=	../../wip/parsec
.endif	# PARSEC_BUILDLINK3_MK

.include "../../wip/hs-mtl/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
