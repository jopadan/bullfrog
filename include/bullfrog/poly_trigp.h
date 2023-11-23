/******************************************************************************/
// Bullfrog Engine Emulation Library - for use to remake classic games like
// Syndicate Wars, Magic Carpet, Genewars or Dungeon Keeper.
/******************************************************************************/
/** @file poly_trigp.h
 *     Header file for poly_trigp.c.
 * @par Purpose:
 *     Textured 2D triangle rendring, clipping and preparation.
 * @par Comment:
 *     To be used internally; to draw a triangle, use API from `poly.h`.
 * @author   Tomasz Lis
 * @date     12 Nov 2008 - 05 Nov 2021
 * @par  Copying and copyrights:
 *     This program is free software; you can redistribute it and/or modify
 *     it under the terms of the GNU General Public License as published by
 *     the Free Software Foundation; either version 2 of the License, or
 *     (at your option) any later version.
 */
/******************************************************************************/
#ifndef POLY_TRIGP_H_
#define POLY_TRIGP_H_

#include "poly.h"

#ifdef __cplusplus
extern "C" {
#endif

#pragma pack(1)

enum RenderingStartType {
    RendStart_NO = 0,
    RendStart_LL,
    RendStart_RL,
    RendStart_FB,
    RendStart_FT,
};

struct TrigLocals {
    u32 zero0;// dummy, to make no offset 0
    unsigned char var_24;// 4+
    unsigned char var_25; // 5+
    union {
        unsigned short flag_26; // 6+
    struct {
        unsigned char byte_26a;
        unsigned char byte_26b;
    };
    };
    u32 var_28; // 8+
    u32 var_2C; // unused
    // These are DWORDs
    u32 var_30; // 0x10+
    u32 var_34; // 0x14
    s32 var_38; // -0x18
    u32 var_3C; // 0x1C
    u32 var_40; // 0x20
    u32 var_44; // 0x24
    u32 var_48; // 0x28
    u32 delta_e; // 0x2C
    union {
    u32 var_50; // 0x30
    struct {
        unsigned short word_50a;
        unsigned short word_50b;
    };
    };
    u32 var_54; // 0x34
    u32 delta_d; // 0x38
    u32 var_5C; // 0x3C
    u32 var_60; // 0x40
    u32 delta_c; // 0x44
    u32 var_68; // 0x48
    u32 var_6C; // 0x4C
    u32 var_70; // 0x50
    u32 var_74; // 0x54
    u32 var_78; // 0x58
    u32 var_7C; // 0x5C
    u32 var_80; // 0x60
    u32 delta_b; // 0x64
    u32 delta_a; // 0x68
    unsigned char *var_8C; // 0x6C
};


/* State transferred from trig_??_start() functions to trig_render_md??().
 * Only a part of it is probably required - to be simplified or removed
 * when everything is remade in C.
 */
struct TrigLocalPrep {
    s32 var_28;
    s32 var_2C;
    s32 var_30;
    s32 trig_height_top; // counter to loop over first part of polyscans array
    s32 var_38;
    s32 trig_height_bottom; // counter to loop over second part of polyscans array
    s32 var_3C;
    s32 var_40;
    s32 var_4C;
    s32 var_50;
    s32 var_58;
    s32 var_5C;
    s32 var_64;
    s32 var_68;
    s32 var_6C;
    s32 var_78;
    ubyte var_8A;
    TbBool hide_bottom_part;
    ubyte var_8C;
};

struct TrigLocalRend {
    ubyte *var_24;
    s32 var_44;
    s32 var_48;
    s32 var_54;
    s32 var_60;
};

#pragma pack()

ubyte trig_reorder_input_points(struct PolyPoint **opt_a,
  struct PolyPoint **opt_b, struct PolyPoint **opt_c);
int trig_ll_start(struct TrigLocalPrep *tlp, struct TrigLocalRend *tlr, const struct PolyPoint *opt_a,
  const struct PolyPoint *opt_b, const struct PolyPoint *opt_c);
int trig_rl_start(struct TrigLocalPrep *tlp, struct TrigLocalRend *tlr, const struct PolyPoint *opt_a,
  const struct PolyPoint *opt_b, const struct PolyPoint *opt_c);
int trig_fb_start(struct TrigLocalPrep *tlp, struct TrigLocalRend *tlr, const struct PolyPoint *opt_a,
  const struct PolyPoint *opt_b, const struct PolyPoint *opt_c);
int trig_ft_start(struct TrigLocalPrep *tlp, struct TrigLocalRend *tlr, const struct PolyPoint *opt_a,
  const struct PolyPoint *opt_b, const struct PolyPoint *opt_c);


#ifdef __cplusplus
};
#endif

#endif // POLY_TRIGP_H_
/******************************************************************************/
