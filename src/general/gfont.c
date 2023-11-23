/******************************************************************************/
// Bullfrog Engine Emulation Library - for use to remake classic games like
// Syndicate Wars, Magic Carpet, Genewars or Dungeon Keeper.
/******************************************************************************/
/** @file gfont.c
 *     Handling of sprite fonts on single character level.
 * @par Purpose:
 *     Provides basics for drawing text on screen.
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
#include "bffont.h"
#include "bfsprite.h"
#include "bfscreen.h"
#include "bftext.h"
#include "bfline.h"
#include "bfanywnd.h"

#define DOUBLE_UNDERLINE_BOUND 16

s32 LbGetJustifiedCharPosX(s32 startx, s32 all_chars_width,
  s32 spr_width, s32 mul_width, ushort fdflags)
{
    s32 justifyx;
    if ((fdflags & Lb_TEXT_HALIGN_LEFT) != 0)
    {
        return startx;
    } else
    if ((fdflags & Lb_TEXT_HALIGN_RIGHT) != 0)
    {
        justifyx = lbTextJustifyWindow.x - lbTextClipWindow.x;
        return startx + (lbTextJustifyWindow.width + justifyx +
          mul_width*spr_width - all_chars_width);
    } else
    if ((fdflags & Lb_TEXT_HALIGN_CENTER) != 0)
    {
        justifyx = lbTextJustifyWindow.x - lbTextClipWindow.x;
        return startx + (lbTextJustifyWindow.width + justifyx +
          mul_width*spr_width - all_chars_width) / 2;
    } else
    if ((fdflags & Lb_TEXT_HALIGN_JUSTIFY) != 0)
    {
        return startx;
    }
    return startx;
}

s32 LbGetJustifiedCharPosY(s32 starty, s32 all_lines_height,
  s32 spr_height, ushort fdflags)
{
    // No vertical justification supported - so the decision is simple
    return starty;
}

s32 LbGetJustifiedCharWidth(s32 all_chars_width, s32 spr_width,
  s32 words_count, int units_per_px, ushort fdflags)
{
    s32 justifyx;
    s32 space_width;
    if ((fdflags & Lb_TEXT_HALIGN_JUSTIFY) != 0)
    {
        space_width = LbTextCharWidth(' ') * units_per_px / 16;
        justifyx = lbTextJustifyWindow.x - lbTextClipWindow.x;
        if (words_count > 0)
            return spr_width + (lbTextJustifyWindow.width + justifyx +
              space_width - all_chars_width) / words_count;
        return spr_width;
    }
    return spr_width;
}

s32 LbGetJustifiedCharHeight(s32 all_lines_height, s32 spr_height,
  s32 lines_count, ushort fdflags)
{
    // No vertical justification supported - so the decision is simple
    return spr_height;
}

void LbDrawCharUnderline(s32 pos_x, s32 pos_y, s32 width, s32 height,
  TbPixel draw_colr, TbPixel shadow_colr)
{
    s32 w,h;
    h = height;
    w = width;
    // Draw shadow
    if ((lbDisplay.DrawFlags & Lb_TEXT_UNDERLNSHADOW) != 0) {
        s32 shadow_x;
        shadow_x = pos_x+1;
        if (height > 2*DOUBLE_UNDERLINE_BOUND)
            shadow_x++;
        LbDrawHVLine(shadow_x, pos_y+h, shadow_x+w, pos_y+h, shadow_colr);
        h--;
        if (height > DOUBLE_UNDERLINE_BOUND) {
            LbDrawHVLine(shadow_x, pos_y+h, shadow_x+w, pos_y+h, shadow_colr);
            h--;
        }
    }
    // Draw underline
    LbDrawHVLine(pos_x, pos_y+h, pos_x+w, pos_y+h, draw_colr);
    h--;
    if (height > DOUBLE_UNDERLINE_BOUND) {
        LbDrawHVLine(pos_x, pos_y+h, pos_x+w, pos_y+h, draw_colr);
        h--;
    }
}

s32 LbTextLineHeight(void)
{
    return LbSprFontCharHeight(lbFontPtr, ' ');
}

s32 LbTextHeight(const char *text)
{
    return LbSprFontCharHeight(lbFontPtr, ' ');
}

s32 LbTextCharWidth(const u32 chr)
{
    return LbSprFontCharWidth(lbFontPtr,(ubyte)chr);
}

s32 LbTextCharHeight(const u32 chr)
{
    return LbSprFontCharHeight(lbFontPtr,(ubyte)chr);
}

s32 LbSprFontCharWidth(const struct TbSprite *font, const u32 chr)
{
    const struct TbSprite *spr;

    spr = LbFontCharSprite(font, chr);
    if (spr == NULL)
        return 0;
    return spr->SWidth;
}

s32 LbSprFontCharHeight(const struct TbSprite *font, const u32 chr)
{
  const struct TbSprite *spr;
  spr = LbFontCharSprite(font, chr);
  if (spr == NULL)
    return 0;
  return spr->SHeight;
}

const struct TbSprite *LbFontCharSprite(const struct TbSprite *font,
  const u32 chr)
{
    if (font == NULL)
        return NULL;
    if ((chr >= 31) && (chr < 256))
        return &font[(chr-31)];
    return NULL;
}

/******************************************************************************/
