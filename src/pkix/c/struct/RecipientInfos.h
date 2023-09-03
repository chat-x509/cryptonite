/*
 * Copyright (c) 2016 PrivatBank IT <acsk@privatbank.ua>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */

#ifndef    _RecipientInfos_H_
#define    _RecipientInfos_H_


#include "asn_application.h"

/* Including external dependencies */
#include "asn_SET_OF.h"
#include "constr_SET_OF.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct RecipientInfo;

/* RecipientInfos */
typedef struct RecipientInfos {
    A_SET_OF(struct RecipientInfo) list;

    /* Context for parsing across buffer boundaries */
    asn_struct_ctx_t _asn_ctx;
} RecipientInfos_t;

/* Implementation */
extern asn_TYPE_descriptor_t RecipientInfos_desc;
CRYPTONITE_EXPORT asn_TYPE_descriptor_t *get_RecipientInfos_desc(void);

#ifdef __cplusplus
}
#endif

#endif
