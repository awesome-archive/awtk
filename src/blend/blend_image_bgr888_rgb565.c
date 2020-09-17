﻿/**
 * File:   blend_image_bgr888_rbg56.c
 * Author: AWTK Develop Team
 * Brief:  blend rbg56 on bgr888
 *
 * Copyright (c) 2018 - 2020  Guangzhou ZHIYUAN Electronics Co.,Ltd.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * License file for more details.
 *
 */

/**
 * History:
 * ================================================================
 * 2018-10-10 Generated by gen.sh(DONT MODIFY IT)
 *
 */
#include "tkc/rect.h"
#include "base/pixel.h"
#include "base/bitmap.h"
#include "base/pixel_pack_unpack.h"

#define pixel_dst_t pixel_bgr888_t
#define pixel_dst_format pixel_bgr888_format
#define pixel_dst_to_rgba pixel_bgr888_to_rgba
#define pixel_dst_from_rgb pixel_bgr888_from_rgb
#define pixel_dst_from_rgba pixel_bgr888_from_rgba

#define pixel_src_t pixel_rgb565_t
#define pixel_src_format pixel_rgb565_format
#define pixel_src_to_rgba pixel_rgb565_to_rgba

#define pixel_t pixel_dst_t
#define pixel_from_rgb pixel_dst_from_rgb
#define pixel_from_rgba pixel_dst_from_rgba
#define pixel_to_rgba pixel_dst_to_rgba

#include "pixel_ops.inc"
#include "blend_image.inc"

ret_t blend_image_bgr888_rgb565(bitmap_t* dst, bitmap_t* src, const rect_t* dst_r, const rect_t* src_r,
                                uint8_t a) {
  return_value_if_fail(dst != NULL && src != NULL && src_r != NULL && dst_r != NULL,
                       RET_BAD_PARAMS);
  return_value_if_fail(dst->format == BITMAP_FMT_BGR888 && src->format == BITMAP_FMT_RGB565,
                       RET_BAD_PARAMS);

  if (a > 0xf8) {
    return blend_image_without_alpha(dst, src, dst_r, src_r);
  } else if (a > 8) {
    return blend_image_with_alpha(dst, src, dst_r, src_r, a);
  } else {
    return RET_OK;
  }
}
