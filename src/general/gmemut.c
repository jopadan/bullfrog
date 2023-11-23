/******************************************************************************/
// Bullfrog Engine Emulation Library - for use to remake classic games like
// Syndicate Wars, Magic Carpet, Genewars or Dungeon Keeper.
/******************************************************************************/
/** @file gmemut.c
 *     Memory related utility functions.
 * @par Purpose:
 *     Provides custom wrappers to memory routines, helpful for debug.
 * @par Comment:
 *     Wrappers to standard C memory handling.
 * @author   Tomasz Lis
 * @date     12 Nov 2008 - 05 Nov 2021
 * @par  Copying and copyrights:
 *     This program is free software; you can redistribute it and/or modify
 *     it under the terms of the GNU General Public License as published by
 *     the Free Software Foundation; either version 2 of the License, or
 *     (at your option) any later version.
 */
/******************************************************************************/
#include "bfmemut.h"
#include <string.h>

void * LbMemoryCopy(void *in_dst, const void *in_src, TbMemSize size)
{
    return memcpy(in_dst, in_src, size);
}

void * LbMemoryMove(void *in_dst, const void *in_src, TbMemSize size)
{
    return memmove(in_dst, in_src, size);
}

void * LbMemorySet(void *dst, unsigned char c, TbMemSize size)
{
    return memset(dst, c, size);
}

int LbMemoryCompare(void *ptr1, void *ptr2, TbMemSize size)
{
    return memcmp(ptr1, ptr2, size);
}
/******************************************************************************/
