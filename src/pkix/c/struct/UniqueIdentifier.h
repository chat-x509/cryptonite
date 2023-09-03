/*
 * Copyright (c) 2016 PrivatBank IT <acsk@privatbank.ua>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */

#ifndef    _UniqueIdentifier_H_
#define    _UniqueIdentifier_H_


#include "asn_application.h"

/* Including external dependencies */
#include "BIT_STRING.h"

#ifdef __cplusplus
extern "C" {
#endif

/* UniqueIdentifier */
typedef BIT_STRING_t     UniqueIdentifier_t;

/* Implementation */
extern asn_TYPE_descriptor_t UniqueIdentifier_desc;
CRYPTONITE_EXPORT asn_TYPE_descriptor_t *get_UniqueIdentifier_desc(void);
asn_struct_free_f UniqueIdentifier_free;
asn_struct_print_f UniqueIdentifier_print;
asn_constr_check_f UniqueIdentifier_constraint;
ber_type_decoder_f UniqueIdentifier_decode_ber;
der_type_encoder_f UniqueIdentifier_encode_der;
xer_type_decoder_f UniqueIdentifier_decode_xer;
xer_type_encoder_f UniqueIdentifier_encode_xer;

#ifdef __cplusplus
}
#endif

#endif
