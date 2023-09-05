/*
 * Copyright (c) 2016 PrivatBank IT <acsk@privatbank.ua>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */

#ifndef CRYPTONITE_MATH_INT_H
#define CRYPTONITE_MATH_INT_H

#include <stdbool.h>

#include "word_internal.h"
#include "prng.h"

#define WORD_MASK (word_t)(-1)
#define MAX_WORD (dword_t)((dword_t)WORD_MASK + 1)

#ifdef  __cplusplus
extern "C" {
#endif

typedef struct Dword_st {
    word_t lo;
    word_t hi;
} Dword;

/**
 * Перевіряє рівність нулю великого цілого числа.
 *
 * @param a велике ціле число
 *
 * @return true - число рівне нулю, false - число не рівне нулю
 */
bool int_is_zero(const WordArray *a);

/**
 * Перевіряє рівність одиниці великого цілого числа
 *
 * @param a велике ціле число
 *
 * @return true — число рівно одиниці, false - число не рівно одиниці
 */
bool int_is_one(const WordArray *a);

/**
 * Перевіряє рівність двох великих цілих чисел
 *
 * @param a велике ціле число
 * @param b велике ціле число
 *
 * @return true — числа рівні, false — числа не равні
 */
bool int_equals(const WordArray *a, const WordArray *b);

/**
 * Порівнює два великих цілих числа
 *
 * @param a велике ціле число
 * @param b велике ціле число
 *
 * @return 0 - якщо a = b, -1 - якщо a < b, 1 - якщо a > b
 */
int int_cmp(const WordArray *a, const WordArray *b);

/**
 * Обчисолює суму двох великих цілих чисел
 * out = a + b.
 *
 * @param a велике ціле число довжиною n
 * @param b велике ціле число довжиною n
 * @param out буфер для суми двох великих цілих чисел довжиною n
 * @return перенос післе додавання: 0 або 1
 */
word_t int_add(const WordArray *a, const WordArray *b, WordArray *out);

/**
 * Обчислює разность двух больших целых чисел.
 * out = a - b.
 *
 * @param a велике ціле число довжини n
 * @param b велике ціле число довжини n
 * @param out буфер для разности двух больших целых чисел довжини n
 * @return займ после вычитания: 0 або -1
 */
int int_sub(const WordArray *a, const WordArray *b, WordArray *out);

/**
 * повертає довжину большого целого числа у словах без ведущих нулей.
 *
 * @param a велике ціле число
 * @return довжина большого целого числа у словах без ведущих нулей
 */
size_t int_word_len(const WordArray *a);

/**
 * повертає довжину у бітах большого целого числа.
 *
 * @param a велике ціле число
 * @return довжина большого целого у бітах
 */
size_t int_bit_len(const WordArray *a);

/**
 * Виконує обрізання великого цілого числа до заданого числа біт.
 *
 * @param a велике ціле число
 * @param bit_len число оставляемых біт
 * @return код помилки
 */
void int_truncate(WordArray *a, size_t bit_len);

/**
 * Повертає заданий біт великого цілого числа.
 *
 * @param a велике ціле число
 * @param bit_num номер біта
 * @return заданный біт числа
 */
int int_get_bit(const WordArray *a, size_t bit_num);

/**
 * Зсуває велике ціле на задане число біт вліво.
 *
 * @param a велике ціле число
 * @param shift величина зсуву у бітах
 * @param out буфер для результату зсуву
 */
void int_lshift(const WordArray *a, size_t shift, WordArray *out);

/**
 * Зсуває велике ціле на заданное число біт вправо
 *
 * @param a_hi старше слово від "a"
 * @param a велике ціле число
 * @param shift величина зсуву у бітах
 * @param out буфер для результату зсуву
 */
void int_rshift(word_t a_hi, const WordArray *a, size_t shift, WordArray *out);

/**
 * Обчислює добуток двох великих цілих чисел.
 *
 * @param a перше велике число довжини n
 * @param b друге велике число довжини n
 * @param out буфер для результату добутку довжини 2n
 */
void int_mul(const WordArray *a, const WordArray *b, WordArray *out);

/**
 * Обчислює кводрат великоого цілого числа.
 *
 * @param a первое велике число довжини n
 * @param out буфер для результата добутку довжини 2n
 */
void int_sqr(const WordArray *a, WordArray *out);

/**
 * Обчислює частку і залишок від ділення великих цілих чисел.
 * a = q * b + r
 *
 * @param a ділене довжини 2n
 * @param b ділитель довжини n
 * @param q буфер для частки довжини 2n або NULL
 * @param r буфер для залишка довжини n або NULL
 */
void int_div(const WordArray *a, const WordArray *b, WordArray *q, WordArray *r);

/**
 * Обчислює цілу частину квадратного кореня.
 * Використовується алгоритм Нʼютона.
 *
 * @param in велике ціле число
 * @param out ціла частина квадратного кореня від in
 */
void int_sqrt(const WordArray *in, WordArray *out);

int int_rand(PrngCtx *prng, const WordArray *in, WordArray *out);
int int_prand(const WordArray *in, WordArray *out);

int int_is_prime(WordArray *a, bool *is_prime);

int int_rabin_miller_primary_test(WordArray *num, bool *is_prime);

int int_fermat_primary_test(WordArray *num, bool *is_prime);

void factorial(int n, WordArray *fac);

/**
 * Обчислює a * b / c.
 *
 * Необхідно щоб b <= c.
 *
 * @param a велике ціле довжини n
 * @param b ціле
 * @param c ціле
 * @param n розмір a в словах
 * @param abc масив для результату довжини n
 *
 * @return код помилки у випадку помилки алокації памʼяті
 */
int int_mult_and_div(const WordArray *a, word_t b, word_t c, int n, WordArray *abc);

int int_get_naf(const WordArray *in, int width, int **out);

int int_get_naf_extra_add(const WordArray *in, const int *naf, int width, int *extra_addition);

int int_gen_prime(const size_t bits, PrngCtx *prng, WordArray **out);

#ifdef  __cplusplus
}
#endif

#endif
