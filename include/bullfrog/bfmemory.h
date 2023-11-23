/******************************************************************************/
// Bullfrog Engine Emulation Library - for use to remake classic games like
// Syndicate Wars, Magic Carpet, Genewars or Dungeon Keeper.
/******************************************************************************/
/** @file bfmemory.h
 *     Header file for smemory.cpp.
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
#ifndef BFLIBRARY_BFMEMORY_H_
#define BFLIBRARY_BFMEMORY_H_

#include "bftypes.h"

#ifdef __cplusplus
extern "C" {
#endif

//TODO change to build system param
// Enable defining list of memory blocks and arenas within the library,
// rather than relying on standard C memory allocation interface.
// Using the arenas, basically changes LbMemoryAlloc() into sub-allocator
// which returns parts of a larger memory area designated for the app.
#define LB_MEMORY_ARENAS 1

/** Type for storing memory allocation routine
 */
typedef void * (*MemAllocFunc)(TbMemSize);


/** Allocates low (below 1MB) memory block.
 *
 * Can allocate the block anywhere when running on linear memory model.
 */
void * LbMemoryAllocLow(TbMemSize size);

/** Allocates high (above 1MB) memory block.
 *
 * Can allocate the block anywhere when running on linear memory model.
 */
void * LbMemoryAlloc(TbMemSize size);

/** Frees memory block.
 */
TbResult LbMemoryFree(void *mem_ptr);

/** Check used and available memory.
 */
TbResult LbMemoryCheck(void);

/** Sets up the memory allocation support.
 */
TbResult LbMemorySetup(void);

/** Finishes the memory allocation support.
 */
TbResult LbMemoryReset(void);

/** Enlarge previously allocated memory block.
 *  The size of the memory block pointed to by the ptr parameter is
 *  changed to the size bytes, expanding the amount of memory available
 *  in the block. A pointer to the reallocated memory block is written
 *  to the ptr, which may be either unchanged address or a new location.
 *  If the function failed to allocate the requested block of memory,
 *  a NULL pointer is returned.
 *
 * @param ptr Double pointer to the previously allocated memory block.
 * @param size New size of the block.
 */
TbResult LbMemoryGrow(void **ptr, TbMemSize size);

/** Reduce previously allocated memory block.
 *  The size of the memory block pointed to by the ptr parameter is
 *  changed to the size bytes, reducing the amount of memory available
 *  in the block. A pointer to the reallocated memory block is written
 *  to the ptr, which usually is the same as the ptr argument.
 *
 * @param ptr Double pointer to the previously allocated memory block.
 * @param size New size of the block.
 */
TbResult LbMemoryShrink(void **ptr, TbMemSize size);

#ifdef __cplusplus
};
#endif

#endif // BFLIBRARY_BFMEMORY_H_
/******************************************************************************/
