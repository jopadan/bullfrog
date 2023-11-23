/******************************************************************************/
// Bullfrog Engine Emulation Library - for use to remake classic games like
// Syndicate Wars, Magic Carpet, Genewars or Dungeon Keeper.
/******************************************************************************/
/** @file bfmath.h
 *     Header file for arctan.c, gtrig.cpp, sqroot.asm.
 * @par Purpose:
 *     Unknown.
 * @par Comment:
 *     None.
 * @author   Tomasz Lis
 * @date     12 Nov 2008 - 05 Nov 2021
 * @par  Copying and copyrights:
 *     This program is free software; you can redistribute it and/or modify
 *     it under the terms of the GNU General Public License as published by
 *     the Free Software Foundation; either version 2 of the License, or
 *     (at your option) any later version.
 */
/******************************************************************************/
#ifndef BFLIBRARY_BFMATH_H_
#define BFLIBRARY_BFMATH_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "bftypes.h"

extern s32 lbSinTable[];

#define LbFPMath_PI 1024
#define LbFPMath_TAU 2048
#define LbFPMath_AngleMask 0x7FF
/** Amount of fractional bits in resulting values of trigonometric operations. */
#define LbFPMath_TrigmBits 16

#define CEILING_POS(X) ((X-(int)(X)) > 0 ? (int)(X+1) : (int)(X))
#define CEILING_NEG(X) ((X-(int)(X)) < 0 ? (int)(X-1) : (int)(X))
#define CEILING(X) ( ((X) > 0) ? CEILING_POS(X) : CEILING_NEG(X) )

enum MathOperator {
    MOp_UNDEFINED                      =  0,
    MOp_EQUAL                          =  1,
    MOp_NOT_EQUAL                      =  2,
    MOp_SMALLER                        =  3,
    MOp_GREATER                        =  4,
    MOp_SMALLER_EQ                     =  5,
    MOp_GREATER_EQ                     =  6,
    MOp_LOGIC_AND                      =  7,
    MOp_LOGIC_OR                       =  8,
    MOp_LOGIC_XOR                      =  9,
    MOp_BITWS_AND                      = 10,
    MOp_BITWS_OR                       = 11,
    MOp_BITWS_XOR                      = 12,
    MOp_SUM                            = 13,
    MOp_SUBTRACT                       = 14,
    MOp_MULTIPLY                       = 15,
    MOp_DIVIDE                         = 16,
    MOp_MODULO                         = 17,
};

/** Computes square root of given 32-bit integer.
 * Works like sqrt(x), but is way faster. The input value is treated as unsigned.
 */
s32 LbSqrL(u32 x);

/** Computes angle between negative Y axis and the line that crosses (0,0) and given (x,y).
 *  Uses arctan(x/y) with proper shift to get the angle.
 *  Returning 0 means direction towards negative y; 512 is towards positive x;
 *  1024 towards positive y, and 1536 towards negative x. Output range is between 0 (=0 rad)
 *  and 2048 (=2*pi rad), zero included.
 *  Value of the angle is properly rounded, up or down.
 *
 * @param x
 * @param y
 * @return
 */
s32 LbArcTanAngle(s32 x,s32 n);

struct Proportion { // sizeof = 8
    s32 field_0;
    s32 distance_ratio;
};

#define LB_RANDOM(range,seed) LbRandomSeries(range, seed, __func__, __LINE__, "lb")
//extern struct Proportion proportions[513];

s32 LbSinL(s32 x);
s32 LbCosL(s32 x);
s32 LbSqrL(s32 x);
s32 LbArcTanL(s32 arg);
s32 LbArcTanAngle(s32 x,s32 n);
s32 LbMathOperation(unsigned char opkind, s32 val1, s32 val2);
u32 LbRandomSeries(u32 range, u32 *seed, const char *func_name, u32 place, const char *tag);
TbBool LbNumberSignsSame(s32 num_a, s32 num_b);
char LbCompareMultiplications(s32 mul1a, s32 mul1b, s32 mul2a, s32 mul2b);
s32 LbDiagonalLength(s32 a, s32 b);
float lerp(float a, float b, float f);
s32 lerp_angle(s32 from, s32 to, float weight);
double fastPow(double a, double b);

/******************************************************************************/
#ifdef __cplusplus
};
#endif

#endif // BFLIBRARY_BFMATH_H_
/******************************************************************************/
