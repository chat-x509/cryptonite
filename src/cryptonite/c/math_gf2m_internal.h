/*
 * Copyright (c) 2016 PrivatBank IT <acsk@privatbank.ua>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */

#ifndef CRYPTONITE_MATH_GF2M_H
#define CRYPTONITE_MATH_GF2M_H

#include <stdbool.h>
#include "word_internal.h"

# ifdef  __cplusplus
extern "C" {
# endif

typedef struct Gf2mCtx_st {
    int *f;
    WordArray *f_ext;
    size_t len;
} Gf2mCtx;

Gf2mCtx *gf2m_alloc(const int *f, size_t f_len);

/**
 * Виконує додавання в полі GF(2^m).
 * out = a + b
 *
 * @param a пеший доданок
 * @param b другий доданок
 * @param out буфер для результату
 */
void gf2m_mod_add(const WordArray *a, const WordArray *b, WordArray *out);

/**
 * Виконує піднесення у квадрат в полі GF(2^m).
 * out = (a * a) mod p
 *
 * @param ctx параметри GF(2^m)
 * @param a елемент поля
 * @param out буфер для a^2
 */
void gf2m_mod_sqr(const Gf2mCtx *ctx, const WordArray *a, WordArray *out);

/**
 * Виконує множення в поле GF(2^m).
 * out = (a * b) mod p
 *
 * @param ctx параметри GF(2^m)
 * @param a перший множник
 * @param b другий множник
 * @param out буфер для добутку
 */
void gf2m_mod_mul(const Gf2mCtx *ctx, const WordArray *a, const WordArray *b, WordArray *out);

/**
 * Обчислює зворотній елемент в полі GF(2^m).
 *
 * @param ctx параметри GF(2^m)
 * @param a елемент поля
 * @param out буфер для оберненого елемента від a
 */
void gf2m_mod_inv(const Gf2mCtx *ctx, const WordArray *a, WordArray *out);

/**
 * Виконує пошук найбільшого спільного дільника двох многочленів.
 *
 * @param a многочлен
 * @param b многочлен
 * @param gcd буфер для наибільшого спільного дільника або NULL
 * @param ka буфер для множника при g або NULL
 * @param kb буфер для множника при h або NULL
 */
void gf2m_mod_gcd(const WordArray *a, const WordArray *b, WordArray *gcd, WordArray *ka, WordArray *kb);

/**
 * Обчислює слід елементу в полі GF(2^m).
 *
 * @param ctx параметри GF(2^m)
 * @param a елемент поля
 *
 * @return слід елементу
 */
int gf2m_mod_trace(const Gf2mCtx *ctx, const WordArray *a);

/**
 * Знаходить корінь квадратного рівняння x^2 + x = a в полі GF(2^m).
 *
 * @param ctx параметри GF(2^m)
 * @param a вільний член
 * @param out буфер для кореня розміру n
 *
 * @return true — рівняння має розвʼязок, false — рівняння немає розвʼязку.
 */
bool gf2m_mod_solve_quad(const Gf2mCtx *ctx, const WordArray *a, WordArray *out);

/**
 * Знаходить квадратний корінь елементу в полі GF(2^m).
 *
 * @param ctx параметри GF(2^m)
 * @param a елемент поля
 * @param out буфер для квадратного кореня розміру n
 */
void gf2m_mod_sqrt(const Gf2mCtx *ctx, const WordArray *a, WordArray *out);

/**
 * Створює копію контексту параметрів GF(2^m).
 *
 * @param ctx параметри GF(2^m)
 * @return копія контексту
 */
Gf2mCtx *gf2m_copy_with_alloc(const Gf2mCtx *ctx);

/**
 * Очищує контекст параметрів GF(2^m).
 *
 * @param ctx параметри GF(2^m)
 */
void gf2m_free(Gf2mCtx *ctx);


#ifdef  __cplusplus
}
#endif

#endif
