/*
 * Copyright (c) 2016 PrivatBank IT <acsk@privatbank.ua>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */

#include "OcspResponsesID.h"

#include "asn_internal.h"

#include "OtherHash.h"
#undef FILE_MARKER
#define FILE_MARKER "pkix/struct/OcspResponsesID.c"

static asn_TYPE_member_t asn_MBR_OcspResponsesID_1[] = {
    {
        ATF_NOFLAGS, 0, offsetof(struct OcspResponsesID, ocspIdentifier),
        (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)),
        0,
        &OcspIdentifier_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "ocspIdentifier"
    },
    {
        ATF_POINTER, 1, offsetof(struct OcspResponsesID, ocspRepHash),
        -1 /* Ambiguous tag (CHOICE?) */,
        0,
        &OtherHash_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "ocspRepHash"
    },
};
static const ber_tlv_tag_t OcspResponsesID_desc_tags_1[] = {
    (ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_OcspResponsesID_tag2el_1[] = {
    { (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)), 0, 0, 1 }, /* ocspIdentifier */
    { (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)), 1, -1, 0 } /* otherHash */
};
static asn_SEQUENCE_specifics_t asn_SPC_OcspResponsesID_specs_1 = {
    sizeof(struct OcspResponsesID),
    offsetof(struct OcspResponsesID, _asn_ctx),
    asn_MAP_OcspResponsesID_tag2el_1,
    2,    /* Count of tags in the map */
    0, 0, 0,    /* Optional elements (not needed) */
    -1,    /* Start extensions */
    -1    /* Stop extensions */
};
asn_TYPE_descriptor_t OcspResponsesID_desc = {
    "OcspResponsesID",
    "OcspResponsesID",
    SEQUENCE_free,
    SEQUENCE_print,
    SEQUENCE_constraint,
    SEQUENCE_decode_ber,
    SEQUENCE_encode_der,
    SEQUENCE_decode_xer,
    SEQUENCE_encode_xer,
    0, 0,    /* No PER support, use "-gen-PER" to enable */
    0,    /* Use generic outmost tag fetcher */
    OcspResponsesID_desc_tags_1,
    sizeof(OcspResponsesID_desc_tags_1)
    / sizeof(OcspResponsesID_desc_tags_1[0]), /* 1 */
    OcspResponsesID_desc_tags_1,    /* Same as above */
    sizeof(OcspResponsesID_desc_tags_1)
    / sizeof(OcspResponsesID_desc_tags_1[0]), /* 1 */
    0,    /* No PER visible constraints */
    asn_MBR_OcspResponsesID_1,
    2,    /* Elements count */
    &asn_SPC_OcspResponsesID_specs_1    /* Additional specs */
};

asn_TYPE_descriptor_t *get_OcspResponsesID_desc(void)
{
    return &OcspResponsesID_desc;
}
