//----------------------------------------------------------------------------------------------------------------------
// Copyright (c) 2014-2030, WindsBridge - http://windsbridge.com All rights reserved!
//
// Redistribution and use in source and binary forms, with or without modification, are permitted provided that the
// following conditions are met:
// 1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following
//    disclaimer.
// 2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the
//    following disclaimer in the documentation and/or other materials provided with the distribution.
// THIS SOFTWARE IS PROVIDED BY BEIJING WINDSBRIDGE TECHNOLOGY CO.,LTD. ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES,
// INCLUDING,BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED.IN NO EVENT SHALL BEIJING WINDSBRIDGE TECHNOLOGY CO.,LTD. OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
// INDIRECT, INCIDENTAL,SPECIAL,EXEMPLARY,OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT,STRICT LIABILITY, OR TORT(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY
// WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
// File    : wlibc-hdlc-codec.c
// Purpose : HDLC codec
// History : Created by WB on 2019-08-10 13:39:31
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
#include "wlibc-hdlc-codec.h"
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
#define HDLC_CODEC_DATASTART   (0xfe)
#define HDLC_CODEC_DATAESCAPE  (0xfd)
#define HDLC_CODEC_SUM_LEN     (1)

enum { HDLC_CODEC_STATUS_ESCAPED = 0, HDLC_CODEC_STATUS_RECEIVING, HDLC_CODEC_STATUS_OK, HDLC_CODEC_STATUS_SUM_ERR };

static void transmit_one_byte(u8 data, u8 *out, u32 *idx) {
  if (data == HDLC_CODEC_DATASTART || data == HDLC_CODEC_DATAESCAPE) {
    out[*idx] = HDLC_CODEC_DATAESCAPE;
    (*idx)++;
    data = data & 0x0f;
  }

  out[*idx] = data;
  (*idx)++;
}

static u8 get_sum(u8 *p, u16 len) {
  u8 sum = 0;
  u16 idx = 0;

  while (idx < len) {
    sum += p[idx++];
  }
  return sum;
}

//----------------------------------------------------------------------------------------------------------------------
// encode HDLC frame
//
// src      - source data to encode
// src_len  - src size in bytes
// out      - to store encoded data
// out_len  - out size in bytes
//
// return
//   the valid length encode data in bytes
//----------------------------------------------------------------------------------------------------------------------
u32 wlibc_hdlc_encode(u8* src, u16 src_len, u8* out, u32 out_len) {
  if (src == nil || src_len == 0 || out == nil || out_len == 0) {
    return 0;
  }

  u32 idx = 0;
  out[idx++] = HDLC_CODEC_DATASTART;
  u8 *src_ptr = src;
  u16 src_len_temp = src_len;

  while (src_len_temp) {
    transmit_one_byte(*src_ptr, out, &idx);
    ++src_ptr;
    --src_len_temp;
  }

  u8 sum = get_sum(src, src_len);
  transmit_one_byte(sum, out, &idx);

  out[idx++] = HDLC_CODEC_DATASTART;

  return idx;
}

//----------------------------------------------------------------------------------------------------------------------
// 解码初始化函数
//
// buf - 需要解码的数据buffer
// len - buffer size in bytes
//
//
// return
//   !=nil - ctx handle
//   nil   - fail
//----------------------------------------------------------------------------------------------------------------------
wlibc_hdlc_decode_s* wlibc_hdlc_decode_init(u8* buf, u32 len, wlibc_hdlc_decode_f pfn) {
  if (buf == nil || len <= sizeof(wlibc_hdlc_decode_s) || pfn == nil) {
    return nil;
  }
  memset(buf, 0x00, len);
  wlibc_hdlc_decode_s *ctx = (wlibc_hdlc_decode_s *)buf;
  ctx->pfn_out = pfn;
  ctx->status = HDLC_CODEC_STATUS_OK;
  ctx->rec_len = 0;
  ctx->buf_len = len - sizeof(wlibc_hdlc_decode_s);

  return ctx;
}

//----------------------------------------------------------------------------------------------------------------------
// decode HDLC frame
//
// ctx - context from wlibc_hdlc_decode_init(...)
// buf - buffer to decode
// len - buffer size in bytes
//
// return
//   WB_ERR_OK                  - continue to decode or decode finish
//   WB_ERR_INVALID_PARAMTERS   - fail
//----------------------------------------------------------------------------------------------------------------------
u32 wlibc_hdlc_decode(wlibc_hdlc_decode_s* ctx, u8* buf, u16 len) {
  if (ctx == nil || buf == nil || len == 0) {
    return WB_ERR_INVALID_PARAMTERS;
  }

  u32 idx = 0;
  u8 data_temp = 0;

  while (idx < len) {
    data_temp = buf[idx];
    if (ctx->status >= HDLC_CODEC_STATUS_OK) {
      ctx->rec_len = 0U;
      ctx->status = HDLC_CODEC_STATUS_RECEIVING;
    }
    if (data_temp == HDLC_CODEC_DATASTART) {
      if (ctx->status == HDLC_CODEC_STATUS_RECEIVING && ctx->rec_len != 0U) {

        if (ctx->rec_len > HDLC_CODEC_SUM_LEN) {
          u16 data_len = ctx->rec_len - HDLC_CODEC_SUM_LEN;
          u8 sum = get_sum(ctx->buf, data_len);

          if (sum == ctx->buf[data_len]) {
            ctx->status = HDLC_CODEC_STATUS_OK;
            ctx->rec_len -= HDLC_CODEC_SUM_LEN;

            (ctx->pfn_out)(ctx->buf, ctx->rec_len, WLIBC_HDLC_STATUS_DATA_OK);
          } else {
            ctx->buf[data_len] = sum;
            ctx->status = HDLC_CODEC_STATUS_SUM_ERR;
            (ctx->pfn_out)(ctx->buf, ctx->rec_len, WLIBC_HDLC_STATUS_DATA_ERR);
          }
        } else {
          ctx->status = HDLC_CODEC_STATUS_SUM_ERR;
          (ctx->pfn_out)(ctx->buf, ctx->rec_len, WLIBC_HDLC_STATUS_DATA_LEN);
        }
      } else {
        ctx->rec_len = 0U;
        ctx->status = HDLC_CODEC_STATUS_RECEIVING;
      }
    } else {
      if (ctx->status == HDLC_CODEC_STATUS_ESCAPED) {
        ctx->status = HDLC_CODEC_STATUS_RECEIVING;

        if (ctx->rec_len < ctx->buf_len) {
          ctx->buf[ctx->rec_len] = data_temp | 0xf0;
          ++(ctx->rec_len);
        } else {
          ctx->status = HDLC_CODEC_STATUS_SUM_ERR;
        }
      } else if (data_temp != HDLC_CODEC_DATAESCAPE) {
        if (ctx->rec_len < ctx->buf_len) {
          ctx->buf[ctx->rec_len] = data_temp;
          ++(ctx->rec_len);
        } else {
          ctx->status = HDLC_CODEC_STATUS_SUM_ERR;
        }
      } else {
        ctx->status = HDLC_CODEC_STATUS_ESCAPED;
      }
    }
    idx++;
  }

  return WB_ERR_OK;
}
