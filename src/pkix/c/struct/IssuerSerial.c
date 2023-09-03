/*
 * Copyright (c) 2016 PrivatBank IT <acsk@privatbank.ua>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */

#include "IssuerSerial.h"

#include "asn_internal.h"

#undef FILE_MARKER
#define FILE_MARKER "pkix/struct/IssuerSerial.c"

static asn_TYPE_member_t asn_MBR_IssuerSerial_1[] = {
    {
        ATF_NOFLAGS, 0, offsetof(struct IssuerSerial, issuer),
        (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)),
        0,
        &GeneralNames_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "issuer"
    },
    {
        ATF_NOFLAGS, 0, offsetof(struct IssuerSerial, serialNumber),
        (ASN_TAG_CLASS_UNIVERSAL | (2 << 2)),
        0,
        &CertificateSerialNumber_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "serialNumber"
    },
    {
        ATF_POINTER, 1, offsetof(struct IssuerSerial, issuerUID),
        (ASN_TAG_CLASS_UNIVERSAL | (3 << 2)),
        0,
        &UniqueIdentifier_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "issuerUID"
    },
};
static const ber_tlv_tag_t IssuerSerial_desc_tags_1[] = {
    (ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_IssuerSerial_tag2el_1[] = {
    { (ASN_TAG_CLASS_UNIVERSAL | (2 << 2)), 1, 0, 0 }, /* serialNumber */
    { (ASN_TAG_CLASS_UNIVERSAL | (3 << 2)), 2, 0, 0 }, /* issuerUID */
    { (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)), 0, 0, 0 } /* issuer */
};
static asn_SEQUENCE_specifics_t asn_SPC_IssuerSerial_specs_1 = {
    sizeof(struct IssuerSerial),
    offsetof(struct IssuerSerial, _asn_ctx),
    asn_MAP_IssuerSerial_tag2el_1,
    3,    /* Count of tags in the map */
    0, 0, 0,    /* Optional elements (not needed) */
    -1,    /* Start extensions */
    -1    /* Stop extensions */
};
asn_TYPE_descriptor_t IssuerSerial_desc = {
    "IssuerSerial",
    "IssuerSerial",
    SEQUENCE_free,
    SEQUENCE_print,
    SEQUENCE_constraint,
    SEQUENCE_decode_ber,
    SEQUENCE_encode_der,
    SEQUENCE_decode_xer,
    SEQUENCE_encode_xer,
    0, 0,    /* No PER support, use "-gen-PER" to enable */
    0,    /* Use generic outmost tag fetcher */
    IssuerSerial_desc_tags_1,
    sizeof(IssuerSerial_desc_tags_1)
    / sizeof(IssuerSerial_desc_tags_1[0]), /* 1 */
    IssuerSerial_desc_tags_1,    /* Same as above */
    sizeof(IssuerSerial_desc_tags_1)
    / sizeof(IssuerSerial_desc_tags_1[0]), /* 1 */
    0,    /* No PER visible constraints */
    asn_MBR_IssuerSerial_1,
    3,    /* Elements count */
    &asn_SPC_IssuerSerial_specs_1    /* Additional specs */
};

asn_TYPE_descriptor_t *get_IssuerSerial_desc(void)
{
    return &IssuerSerial_desc;
}
