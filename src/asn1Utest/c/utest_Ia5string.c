/*
 * Copyright (c) 2016 PrivatBank IT <acsk@privatbank.ua>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */

#include "test_utils.h"
#include "utest_asn1.h"

static IA5String_t *test_ia5string_create(void)
{
    uint8_t encode[15] = {
        0x16, 0x0d,
        0x54, 0x65, 0x73, 0x74,
        0x20, 0x6d, 0x65, 0x73,
        0x73, 0x61, 0x67, 0x65,
        0x2e
    };

    IA5String_t *ia5string = NULL;

    ASN_EXECUTE(ber_decode(0, &IA5String_desc, (void *)&ia5string, encode, sizeof(encode)));
    ASSERT_NOT_NULL(ia5string);
cleanup:
    return ia5string;
}

void test_ia5string_alloc_free(void)
{
    IA5String_t *ia5string = NULL;

    ASSERT_ASN_ALLOC(ia5string);
    ASSERT_NOT_NULL(ia5string);
cleanup:
    ASN_FREE(&IA5String_desc, ia5string);
}

void test_ia5string_der_encode(void)
{
    ByteArray *actual = NULL;
    ByteArray *expected = NULL;
    uint8_t exp[15] = {
        0x16, 0x0d,
        0x54, 0x65, 0x73, 0x74,
        0x20, 0x6d, 0x65, 0x73,
        0x73, 0x61, 0x67, 0x65,
        0x2e
    };

    IA5String_t *ia5string = NULL;

    ia5string = test_ia5string_create();
    ASSERT_NOT_NULL(ia5string);
    ASSERT_NOT_NULL(expected = ba_alloc_from_uint8(exp, sizeof(exp)));

    ASSERT_RET_OK(asn_encode_ba(&IA5String_desc, ia5string, (void *)&actual));
    ASSERT_NOT_NULL(actual);

    ASSERT_EQUALS_BA(expected, actual);
cleanup:
    BA_FREE(expected, actual);
    ASN_FREE(&IA5String_desc, ia5string);
}

void test_ia5string_uper_encode(void)
{
    asn_enc_rval_t ret;
    uint8_t actual[99] = {0};
    uint8_t expected[99] = {
        0x0d,
        0xa9, 0x97, 0x9f, 0x44, 0x1b, 0x72, 0xf3, 0xe7,
        0x87, 0x3e, 0x55, 0xc0, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00
    };

    IA5String_t *ia5string = NULL;

    ia5string = test_ia5string_create();
    ASSERT_NOT_NULL(ia5string);

    ret = uper_encode_to_buffer(&IA5String_desc, ia5string, (void *)actual, sizeof(actual));
    ASSERT_NOT_NULL(actual);

    ASSERT_TRUE(sizeof(expected) == ret.encoded);
    ASSERT_EQUALS(expected, actual, sizeof(expected));
cleanup:
    ASN_FREE(&IA5String_desc, ia5string);
}

void test_ia5string_uper_decode(void)
{
    uint8_t encode[99] = {
        0x0d,
        0xa9, 0x97, 0x9f, 0x44, 0x1b, 0x72, 0xf3, 0xe7,
        0x87, 0x3e, 0x55, 0xc0, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00
    };

    IA5String_t *actual = NULL;
    IA5String_t *expected = NULL;
    asn_dec_rval_t ret;

    expected = test_ia5string_create();
    ASSERT_NOT_NULL(expected);

    ret = uper_decode(0, &IA5String_desc, (void *)&actual, encode, sizeof(encode), 0, 0);

    ASSERT_TRUE(ret.code == RET_OK);
    ASSERT_NOT_NULL(actual);

    ASSERT_TRUE(asn_equals(&IA5String_desc, expected, actual));
cleanup:
    ASN_FREE(&IA5String_desc, expected);
    ASN_FREE(&IA5String_desc, actual);
}

void test_ia5string_xer_decode(void)
{
    uint8_t encode[36] = {
        0x3c, 0x49, 0x41, 0x35, 0x53, 0x74, 0x72, 0x69,
        0x6e, 0x67, 0x3e, 0x54, 0x65, 0x73, 0x74, 0x20,
        0x6d, 0x65, 0x73, 0x73, 0x61, 0x67, 0x65, 0x2e,
        0x3c, 0x2f, 0x49, 0x41, 0x35, 0x53, 0x74, 0x72,
        0x69, 0x6e, 0x67, 0x3e
    };

    IA5String_t *actual = NULL;
    IA5String_t *expected = NULL;
    asn_dec_rval_t ret;

    expected = test_ia5string_create();
    ASSERT_NOT_NULL(expected);

    ret = xer_decode(0, &IA5String_desc, (void *)&actual, encode, sizeof(encode));

    ASSERT_TRUE(ret.code == RET_OK);
    ASSERT_NOT_NULL(actual);

    ASSERT_TRUE(asn_equals(&IA5String_desc, expected, actual));
cleanup:
    ASN_FREE(&IA5String_desc, expected);
    ASN_FREE(&IA5String_desc, actual);
}

void utest_ia5string(void)
{
    PR("%s\n", __FILE__);

    test_ia5string_alloc_free();
    test_ia5string_uper_encode();
    test_ia5string_der_encode();
    test_ia5string_uper_decode();
    test_ia5string_xer_decode();
}
