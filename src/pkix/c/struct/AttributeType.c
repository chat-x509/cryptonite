/*
 * Copyright (c) 2016 PrivatBank IT <acsk@privatbank.ua>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */

#include "AttributeType.h"

#include "asn_internal.h"

#undef FILE_MARKER
#define FILE_MARKER "pkix/struct/AttributeType.c"

int
AttributeType_constraint(asn_TYPE_descriptor_t *td, const void *sptr,
        asn_app_constraint_failed_f *ctfailcb, void *app_key)
{
    /* Replace with underlying type checker */
    td->check_constraints = OBJECT_IDENTIFIER_desc.check_constraints;
    return td->check_constraints(td, sptr, ctfailcb, app_key);
}

/*
 * This type is implemented using OBJECT_IDENTIFIER,
 * so here we adjust the DEF accordingly.
 */
static void
AttributeType_1_inherit_TYPE_descriptor(asn_TYPE_descriptor_t *td)
{
    td->free_struct    = OBJECT_IDENTIFIER_desc.free_struct;
    td->print_struct   = OBJECT_IDENTIFIER_desc.print_struct;
    td->check_constraints = OBJECT_IDENTIFIER_desc.check_constraints;
    td->ber_decoder    = OBJECT_IDENTIFIER_desc.ber_decoder;
    td->der_encoder    = OBJECT_IDENTIFIER_desc.der_encoder;
    td->xer_decoder    = OBJECT_IDENTIFIER_desc.xer_decoder;
    td->xer_encoder    = OBJECT_IDENTIFIER_desc.xer_encoder;
    td->uper_decoder   = OBJECT_IDENTIFIER_desc.uper_decoder;
    td->uper_encoder   = OBJECT_IDENTIFIER_desc.uper_encoder;
    if (!td->per_constraints) {
        td->per_constraints = OBJECT_IDENTIFIER_desc.per_constraints;
    }
    td->elements       = OBJECT_IDENTIFIER_desc.elements;
    td->elements_count = OBJECT_IDENTIFIER_desc.elements_count;
    td->specifics      = OBJECT_IDENTIFIER_desc.specifics;
}

void
AttributeType_free(asn_TYPE_descriptor_t *td,
        void *struct_ptr, int contents_only)
{
    AttributeType_1_inherit_TYPE_descriptor(td);
    td->free_struct(td, struct_ptr, contents_only);
}

int
AttributeType_print(asn_TYPE_descriptor_t *td, const void *struct_ptr,
        int ilevel, asn_app_consume_bytes_f *cb, void *app_key)
{
    AttributeType_1_inherit_TYPE_descriptor(td);
    return td->print_struct(td, struct_ptr, ilevel, cb, app_key);
}

asn_dec_rval_t
AttributeType_decode_ber(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
        void **structure, const void *bufptr, size_t size, int tag_mode)
{
    AttributeType_1_inherit_TYPE_descriptor(td);
    return td->ber_decoder(opt_codec_ctx, td, structure, bufptr, size, tag_mode);
}

asn_enc_rval_t
AttributeType_encode_der(asn_TYPE_descriptor_t *td,
        void *structure, int tag_mode, ber_tlv_tag_t tag,
        asn_app_consume_bytes_f *cb, void *app_key)
{
    AttributeType_1_inherit_TYPE_descriptor(td);
    return td->der_encoder(td, structure, tag_mode, tag, cb, app_key);
}

asn_dec_rval_t
AttributeType_decode_xer(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
        void **structure, const char *opt_mname, const void *bufptr, size_t size)
{
    AttributeType_1_inherit_TYPE_descriptor(td);
    return td->xer_decoder(opt_codec_ctx, td, structure, opt_mname, bufptr, size);
}

asn_enc_rval_t
AttributeType_encode_xer(asn_TYPE_descriptor_t *td, void *structure,
        int ilevel, enum xer_encoder_flags_e flags,
        asn_app_consume_bytes_f *cb, void *app_key)
{
    AttributeType_1_inherit_TYPE_descriptor(td);
    return td->xer_encoder(td, structure, ilevel, flags, cb, app_key);
}

static const ber_tlv_tag_t AttributeType_desc_tags_1[] = {
    (ASN_TAG_CLASS_UNIVERSAL | (6 << 2))
};
asn_TYPE_descriptor_t AttributeType_desc = {
    "AttributeType",
    "AttributeType",
    AttributeType_free,
    AttributeType_print,
    AttributeType_constraint,
    AttributeType_decode_ber,
    AttributeType_encode_der,
    AttributeType_decode_xer,
    AttributeType_encode_xer,
    0, 0,    /* No PER support, use "-gen-PER" to enable */
    0,    /* Use generic outmost tag fetcher */
    AttributeType_desc_tags_1,
    sizeof(AttributeType_desc_tags_1)
    / sizeof(AttributeType_desc_tags_1[0]), /* 1 */
    AttributeType_desc_tags_1,    /* Same as above */
    sizeof(AttributeType_desc_tags_1)
    / sizeof(AttributeType_desc_tags_1[0]), /* 1 */
    0,    /* No PER visible constraints */
    0, 0,    /* No members */
    0    /* No specifics */
};

asn_TYPE_descriptor_t *get_AttributeType_desc(void)
{
    return &AttributeType_desc;
}
