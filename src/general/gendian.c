/******************************************************************************/
// Bullfrog Engine Emulation Library - for use to remake classic games like
// Syndicate Wars, Magic Carpet, Genewars or Dungeon Keeper.
/******************************************************************************/
/** @file gendian.c
 *     Integer endianness convert function, and bit setting.
 * @par Purpose:
 *     Allows to read integers at given endianness.
 *     Also includes bit flags setting functions.
 * @par Comment:
 *     A set of simple, self-containing routines.
 * @author   Tomasz Lis
 * @date     12 Nov 2008 - 05 Nov 2021
 * @par  Copying and copyrights:
 *     This program is free software; you can redistribute it and/or modify
 *     it under the terms of the GNU General Public License as published by
 *     the Free Software Foundation; either version 2 of the License, or
 *     (at your option) any later version.
 */
/******************************************************************************/
#include "bfendian.h"

u32 blong (unsigned char *p)
{
    u32 n;
    n = p[0];
    n = (n << 8) + p[1];
    n = (n << 8) + p[2];
    n = (n << 8) + p[3];
    return n;
}

u32 llong (unsigned char *p)
{
    u32 n;
    n = p[3];
    n = (n << 8) + p[2];
    n = (n << 8) + p[1];
    n = (n << 8) + p[0];
    return n;
}

u32 bword (unsigned char *p)
{
    u32 n;
    n = p[0];
    n = (n << 8) + p[1];
    return n;
}

u32 lword (unsigned char *p)
{
    u32 n;
    n = p[1];
    n = (n << 8) + p[0];
    return n;
}

void toggle_flag_byte(unsigned char *flags, unsigned char mask)
{
  if ((*flags & mask) == 0)
    *flags |= mask;
  else
    *flags ^= mask;
}

void toggle_flag_dword(u32 *flags, u32 mask)
{
  if ((*flags & mask) == 0)
    *flags |= mask;
  else
    *flags ^= mask;
}

void set_flag_word(unsigned short *flags, unsigned short mask, short value)
{
  if (value)
    *flags |= mask;
  else
    *flags ^= *flags & mask;
}

void set_flag_byte(unsigned char *flags, unsigned char mask, short value)
{
  if (value)
    *flags |= mask;
  else
    *flags ^= *flags & mask;
}

void set_flag_dword(u32 *flags, u32 mask, short value)
{
  if (value)
    *flags |= mask;
  else
    *flags ^= *flags & mask;
}

int number_of_set_bits(u32 i)
{
    i = i - ((i >> 1) & 0x55555555); // add pairs of bits
    i = (i & 0x33333333) + ((i >> 2) & 0x33333333);  // quads
    i = (i + (i >> 4)) & 0x0F0F0F0F; // groups of 8
    i *= 0x01010101; // horizontal sum of bytes
    // return just that top byte (after truncating to 32-bit even when int is wider)
    return  i >> 24;
}
/******************************************************************************/
