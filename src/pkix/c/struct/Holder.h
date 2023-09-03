/*
 * Copyright (c) 2016 PrivatBank IT <acsk@privatbank.ua>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */

#ifndef    _Holder_H_
#define    _Holder_H_


#include "asn_application.h"

/* Including external dependencies */
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct IssuerSerial;
struct GeneralNames;
struct ObjectDigestInfo;

/* Holder */
typedef struct Holder {
    struct IssuerSerial    *baseCertificateID    /* OPTIONAL */;
    struct GeneralNames    *entityName    /* OPTIONAL */;
    struct ObjectDigestInfo    *objectDigestInfo    /* OPTIONAL */;

    /* Context for parsing across buffer boundaries */
    asn_struct_ctx_t _asn_ctx;
} Holder_t;

/* Implementation */
extern asn_TYPE_descriptor_t Holder_desc;
CRYPTONITE_EXPORT asn_TYPE_descriptor_t *get_Holder_desc(void);

#ifdef __cplusplus
}
#endif

#endif
