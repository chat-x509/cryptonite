/*
 * Copyright (c) 2016 PrivatBank IT <acsk@privatbank.ua>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */

#include "test_utils.h"
#include "utest_asn1.h"

static uint8_t encode[2] = {0x05, 0x00};

static NULL_t *test_asn1null_create(void)
{
    ByteArray *encode_ba = NULL;
    NULL_t *asn1null = NULL;

    ASSERT_NOT_NULL(encode_ba = ba_alloc_from_uint8(encode, sizeof(encode)));
    ASSERT_NOT_NULL(asn1null = asn_decode_ba_with_alloc(&NULL_desc, encode_ba));

cleanup:
    ba_free(encode_ba);
    return asn1null;
}

void test_asn1null_alloc_free(void)
{
    NULL_t *asn1null = NULL;

    ASSERT_ASN_ALLOC(asn1null);
    ASSERT_NOT_NULL(asn1null);
cleanup:
    ASN_FREE(&NULL_desc, asn1null);
}

void test_asn1null_encode(void)
{
    size_t expected_len = 2;
    ByteArray *actual = NULL;

    NULL_t *asn1null = NULL;

    asn1null = test_asn1null_create();
    ASSERT_NOT_NULL(asn1null);

    ASSERT_RET_OK(asn_encode_ba(&NULL_desc, asn1null, &actual));
    ASSERT_NOT_NULL(actual);

    ASSERT_TRUE(expected_len == ba_get_len(actual));
    ASSERT_EQUALS(encode, ba_get_buf(actual), expected_len);

cleanup:

    ba_free(actual);
    ASN_FREE(&NULL_desc, asn1null);
}

void test_asn1null_uper_encode(void)
{
    asn_enc_rval_t ret;
    uint8_t actual[50] = {0};

    NULL_t *asn1null = NULL;

    asn1null = test_asn1null_create();
    ASSERT_NOT_NULL(asn1null);

    ret = uper_encode_to_buffer(&NULL_desc, asn1null, actual, sizeof(actual));
    ASSERT_NOT_NULL(actual);

    ASSERT_TRUE(RET_OK == ret.encoded);
cleanup:
    ASN_FREE(&NULL_desc, asn1null);
}

void test_asn1null_uper_decode(void)
{
    uint8_t encode[216] = {
        0x0d,
        0x00, 0x54, 0x00, 0x65, 0x00, 0x73, 0x00, 0x74,
        0x00, 0x20, 0x00, 0x6d, 0x00, 0x65, 0x00, 0x73,
        0x00, 0x73, 0x00, 0x61, 0x00, 0x67, 0x00, 0x65,
        0x00, 0x2e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };

    NULL_t *actual = NULL;
    NULL_t *expected = NULL;
    asn_dec_rval_t ret;

    expected = test_asn1null_create();
    ASSERT_NOT_NULL(expected);

    ret = uper_decode(0, &NULL_desc, (void *) &actual, encode, sizeof(encode), 0, 0);

    ASSERT_TRUE(ret.code == RET_OK);
    ASSERT_NOT_NULL(actual);

    ASSERT_TRUE(asn_equals(&NULL_desc, expected, actual));
cleanup:
    ASN_FREE(&NULL_desc, expected);
    ASN_FREE(&NULL_desc, actual);
}

void test_asn1null_xer_decode(void)
{
    uint8_t encode[] = {
        0x3c, 0x4e, 0x55, 0x4c,
        0x4c, 0x3e, 0x3c, 0x2f,
        0x4e, 0x55, 0x4c, 0x4c, 0x3e
    };

    NULL_t *actual = NULL;
    NULL_t *expected = NULL;
    asn_dec_rval_t ret;

    expected = test_asn1null_create();
    ASSERT_NOT_NULL(expected);

    ret = xer_decode(0, &NULL_desc, (void *)&actual, encode, sizeof(encode));

    ASSERT_TRUE(ret.code == RET_OK);

    ASSERT_NOT_NULL(actual);

    ASSERT_TRUE(asn_equals(&NULL_desc, expected, actual));
cleanup:
    ASN_FREE(&NULL_desc, expected);
    ASN_FREE(&NULL_desc, actual);
}

void utest_asn1null(void)
{
    PR("%s\n", __FILE__);
    test_asn1null_alloc_free();
    test_asn1null_encode();
    test_asn1null_uper_encode();
    test_asn1null_uper_decode();
    test_asn1null_xer_decode();
}
