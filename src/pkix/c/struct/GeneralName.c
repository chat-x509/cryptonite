/*
 * Copyright (c) 2016 PrivatBank IT <acsk@privatbank.ua>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */

#include "GeneralName.h"

#include "asn_internal.h"

#undef FILE_MARKER
#define FILE_MARKER "pkix/struct/GeneralName.c"

static asn_TYPE_member_t asn_MBR_GeneralName_1[] = {
    {
        ATF_NOFLAGS, 0, offsetof(struct GeneralName, choice.otherName),
        (ASN_TAG_CLASS_CONTEXT | (0 << 2)),
        -1,    /* IMPLICIT tag at current level */
        &OtherName_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "otherName"
    },
    {
        ATF_NOFLAGS, 0, offsetof(struct GeneralName, choice.rfc822Name),
        (ASN_TAG_CLASS_CONTEXT | (1 << 2)),
        -1,    /* IMPLICIT tag at current level */
        &IA5String_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "rfc822Name"
    },
    {
        ATF_NOFLAGS, 0, offsetof(struct GeneralName, choice.dNSName),
        (ASN_TAG_CLASS_CONTEXT | (2 << 2)),
        -1,    /* IMPLICIT tag at current level */
        &IA5String_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "dNSName"
    },
    {
        ATF_NOFLAGS, 0, offsetof(struct GeneralName, choice.x400Address),
        (ASN_TAG_CLASS_CONTEXT | (3 << 2)),
        -1,    /* IMPLICIT tag at current level */
        &ORAddress_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "x400Address"
    },
    {
        ATF_NOFLAGS, 0, offsetof(struct GeneralName, choice.directoryName),
        (ASN_TAG_CLASS_CONTEXT | (4 << 2)),
        +1,    /* EXPLICIT tag at current level */
        &Name_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "directoryName"
    },
    {
        ATF_NOFLAGS, 0, offsetof(struct GeneralName, choice.ediPartyName),
        (ASN_TAG_CLASS_CONTEXT | (5 << 2)),
        -1,    /* IMPLICIT tag at current level */
        &EDIPartyName_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "ediPartyName"
    },
    {
        ATF_NOFLAGS, 0, offsetof(struct GeneralName, choice.uniformResourceIdentifier),
        (ASN_TAG_CLASS_CONTEXT | (6 << 2)),
        -1,    /* IMPLICIT tag at current level */
        &IA5String_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "uniformResourceIdentifier"
    },
    {
        ATF_NOFLAGS, 0, offsetof(struct GeneralName, choice.iPAddress),
        (ASN_TAG_CLASS_CONTEXT | (7 << 2)),
        -1,    /* IMPLICIT tag at current level */
        &OCTET_STRING_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "iPAddress"
    },
    {
        ATF_NOFLAGS, 0, offsetof(struct GeneralName, choice.registeredID),
        (ASN_TAG_CLASS_CONTEXT | (8 << 2)),
        -1,    /* IMPLICIT tag at current level */
        &OBJECT_IDENTIFIER_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "registeredID"
    },
};
static const asn_TYPE_tag2member_t asn_MAP_GeneralName_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* otherName */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* rfc822Name */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* dNSName */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 }, /* x400Address */
    { (ASN_TAG_CLASS_CONTEXT | (4 << 2)), 4, 0, 0 }, /* directoryName */
    { (ASN_TAG_CLASS_CONTEXT | (5 << 2)), 5, 0, 0 }, /* ediPartyName */
    { (ASN_TAG_CLASS_CONTEXT | (6 << 2)), 6, 0, 0 }, /* uniformResourceIdentifier */
    { (ASN_TAG_CLASS_CONTEXT | (7 << 2)), 7, 0, 0 }, /* iPAddress */
    { (ASN_TAG_CLASS_CONTEXT | (8 << 2)), 8, 0, 0 } /* registeredID */
};
static asn_CHOICE_specifics_t asn_SPC_GeneralName_specs_1 = {
    sizeof(struct GeneralName),
    offsetof(struct GeneralName, _asn_ctx),
    offsetof(struct GeneralName, present),
    sizeof(((struct GeneralName *)0)->present),
    asn_MAP_GeneralName_tag2el_1,
    9,    /* Count of tags in the map */
    0,
    -1    /* Extensions start */
};
asn_TYPE_descriptor_t GeneralName_desc = {
    "GeneralName",
    "GeneralName",
    CHOICE_free,
    CHOICE_print,
    CHOICE_constraint,
    CHOICE_decode_ber,
    CHOICE_encode_der,
    CHOICE_decode_xer,
    CHOICE_encode_xer,
    0, 0,    /* No PER support, use "-gen-PER" to enable */
    CHOICE_outmost_tag,
    0,    /* No effective tags (pointer) */
    0,    /* No effective tags (count) */
    0,    /* No tags (pointer) */
    0,    /* No tags (count) */
    0,    /* No PER visible constraints */
    asn_MBR_GeneralName_1,
    9,    /* Elements count */
    &asn_SPC_GeneralName_specs_1    /* Additional specs */
};

asn_TYPE_descriptor_t *get_GeneralName_desc(void)
{
    return &GeneralName_desc;
}
