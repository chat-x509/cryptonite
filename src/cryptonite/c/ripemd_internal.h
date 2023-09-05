/*
 * Copyright (c) 2016 PrivatBank IT <acsk@privatbank.ua>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */

#ifndef CRYPTONITE_RIPEMD_H
#define CRYPTONITE_RIPEMD_H

#include "byte_array.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    RIPEMD_VARIANT_128,
    RIPEMD_VARIANT_160
} RipemdVariant;

/**
 * Контекст RIPEMD.
 */
typedef struct RipemdCtx_st RipemdCtx;

/**
 * Виділення памʼяті для режиму RIPEMD128.
 *
 * @return повертає указатель на выделенную память.
 */
RipemdCtx *ripemd_alloc(RipemdVariant mode);

/**
 * Видалення даних з контексту RIPEMD.
 *
 * @param ctx контекст RIPEMD.
 */
void ripemd_free(RipemdCtx *ctx);

/**
 * Добавление даних для геширования.
 *
 * @param ctx контекст RIPEMD.
 * @param data дані, які потрібно загешувати.
 * @return  - 1 у випадку успіху і код помилки в оберненому.
 */
int ripemd_update(RipemdCtx *ctx, const ByteArray *data);

/**
 * Отримання геша від даних.
 *
 * @param ctx контекст RIPEMD.
 * @param hash_code геш даних.
 * @return код помилки
 */
int ripemd_final(RipemdCtx *ctx, ByteArray **hash_code);




#ifdef __cplusplus
}
#endif

#endif /* CRYPTONITE_RIPEMD_H */

