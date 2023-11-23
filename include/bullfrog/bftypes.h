/******************************************************************************/
// Bullfrog Engine Emulation Library - for use to remake classic games like
// Syndicate Wars, Magic Carpet, Genewars or Dungeon Keeper.
/******************************************************************************/
/** @file bftypes.h
 *     Header with basic type definitions.
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
#ifndef BFLIBRARY_GTYPES_H_
#define BFLIBRARY_GTYPES_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>
#include <time.h>

#define DISKPATH_SIZE       144
#define LINEMSG_SIZE        160
#define READ_BUFSIZE        256
#define LOOPED_FILE_LEN    4096
#define COMMAND_WORD_LEN     32
#define MAX_TEXT_LENGTH    4096
#define TEXT_BUFFER_LENGTH 2048
#define LOG_PREFIX_LEN       32

#ifndef HAVE_STDINT_H

#if ((ULONG_MAX) == (UINT_MAX))
typedef          long long          s64; /*   signed 64-bit integer */
typedef unsigned long long          u64; /* unsigned 64-bit integer */
#else
typedef               long          s64; /*   signed 64-bit integer */
typedef      unsigned long          u64; /* unsigned 64-bit integer */
#endif

typedef                int          s32; /*   signed 32-bit integer */
typedef       unsigned int          u32; /* unsigned 32-bit integer */
typedef              short          s16; /*   signed 16-bit integer */
typedef     unsigned short          u16; /* unsigned 16-bit integer */
typedef               char           s8; /*   signed  8-bit integer */
typedef      unsigned char           u8; /* unsigned  8-bit integer */

/** Small, single byte boolean. */
typedef      unsigned char       TbBool; /* unsigned  8-bit boolean */

#ifndef false
# define false 0
#endif
#ifndef true
# define true 1
#endif
#ifndef NULL
# define NULL 0
#endif

#else

#include <stdint.h>
#include <stdbool.h>
#include <sys/time.h>

typedef            int64_t           s64; /*   signed 64-bit integer */
typedef           uint64_t           u64; /* unsigned 64-bit integer */
typedef            int32_t           s32; /*   signed 32-bit integer */
typedef           uint32_t           u32; /* unsigned 32-bit integer */
typedef            int16_t           s16; /*   signed 16-bit integer */
typedef           uint16_t           u16; /* unsigned 16-bit integer */
typedef             int8_t            s8; /*   signed  8-bit integer */
typedef            uint8_t            u8; /* unsigned  8-bit integer */

typedef               bool        TbBool; /*           8-bit boolean */
#endif
typedef             time_t     TbTimeSec; /*  time 32/64-bit integer */
typedef                s64   TbClockMSec; /*   signed 64-bit integer */

/* obsolete definition of ulong  */
/* typedef unsigned long  ulong; */

typedef                u32          uint; /* unsigned 32-bit integer */
typedef                u16        ushort; /* unsigned 16-bit integer */
typedef                 u8         ubyte; /* unsigned  8-bit integer */
typedef                 s8         sbyte; /*   signed  8-bit integer */
typedef      unsigned char         uchar; /* unsigned character type */

typedef             size_t     TbMemSize; /* unsigned 32/64-bit size */

/** Command function result, valid values are of TbErrorCode enumeration. */
typedef                int      TbResult; /*   signed 32-bit integer */

enum TbErrorCode {
    Lb_FAIL                 = -1,
    Lb_OK                   =  0,
    Lb_SUCCESS              =  1,
};

/** Large boolean. */
typedef                u32        DwBool; /* unsigned 32-bit integer */
/** Coordinate on screen. */
typedef                s16 TbScreenCoord; /*   signed 16-bit integer */

/** 8-bit pixel definition.
 * Represents value of one point on the graphics screen.
 */
typedef                 u8       TbPixel; /* unsigned  8-bit integer */      

struct TbTime {
        unsigned char Hour;
        unsigned char Minute;
        unsigned char Second;
        unsigned char HSecond;
};

struct TbDate {
        unsigned char  Day;
        unsigned char  Month;
        unsigned short Year;
        unsigned char  DayOfWeek;
};

struct TbFileFind {
          char Filename[DISKPATH_SIZE];
          char AlternateFilename[14];
          unsigned long Attributes;
          unsigned long Length;
          struct TbDate CreationDate;
          struct TbTime CreationTime;
          struct TbDate LastWriteDate;
          struct TbTime LastWriteTime;
          unsigned long ReservedHandle;
          struct _finddata_t Reserved;
};


enum TbErrorLogFlags {
        Lb_ERROR_LOG_APPEND = 0,
        Lb_ERROR_LOG_NEW    = 1,
};

enum TbLogFlags {
        LbLog_DateInHeader = 0x0010,
        LbLog_TimeInHeader = 0x0020,
        LbLog_DateInLines  = 0x0040,
        LbLog_TimeInLines  = 0x0080,
        LbLog_LoopedFile   = 0x0100,
};

struct TbLog {
        char filename[DISKPATH_SIZE];
        char prefix[LOG_PREFIX_LEN];
        ulong flags;
        TbBool Initialised;
        TbBool Created;
        TbBool Suspended;
        long position;
};


#ifdef __cplusplus
};
#endif

#endif // BFLIBRARY_GTYPES_H_
/******************************************************************************/
