/*
 * Copyright (c) 2016 PrivatBank IT <acsk@privatbank.ua>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */

#ifndef    _CertBag_H_
#define    _CertBag_H_


#include "asn_application.h"

/* Including external dependencies */
#include "OBJECT_IDENTIFIER.h"
#include "ANY.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* CertBag */
typedef struct CertBag {
    OBJECT_IDENTIFIER_t     certId;
    ANY_t     certValue;

    /* Context for parsing across buffer boundaries */
    asn_struct_ctx_t _asn_ctx;
} CertBag_t;

/* Implementation */
extern asn_TYPE_descriptor_t CertBag_desc;
CRYPTONITE_EXPORT asn_TYPE_descriptor_t *get_CertBag_desc(void);

#ifdef __cplusplus
}
#endif

#endif
