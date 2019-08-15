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
// File    : wlibc-hdlc-codec.h
// Purpose : HDLC codec
// History : Created by WB on 2019-08-10 13:42:06
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
#pragma once
#include "wb-types.h"
//----------------------------------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------
typedef enum {
  WLIBC_HDLC_STATUS_DATA_OK,
  WLIBC_HDLC_STATUS_DATA_ERR,
  WLIBC_HDLC_STATUS_DATA_LEN,
} wlibc_hdlc_status_e;

typedef void (*wlibc_hdlc_decode_f)(u8* data, u16 len, wlibc_hdlc_status_e state);

typedef struct {
  wlibc_hdlc_decode_f pfn_out;
  wlibc_hdlc_status_e status;
  u16 rec_len;
  u16 buf_len;
  u8 buf[0];
} wlibc_hdlc_decode_s;

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
u32 wlibc_hdlc_encode(u8* src, u16 src_len , u8* out, u32 out_len);

//----------------------------------------------------------------------------------------------------------------------
// 解码初始化函数
//
// buf - 需要解码的数据buffer
// len - buffer size in bytes
// pfn - called-back fucntion
//
//
// return
//   !=nil - ctx handle
//   nil   - fail
//----------------------------------------------------------------------------------------------------------------------
wlibc_hdlc_decode_s* wlibc_hdlc_decode_init(u8* buf, u32 len, wlibc_hdlc_decode_f pfn);

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
u32 wlibc_hdlc_decode(wlibc_hdlc_decode_s *ctx, u8 *buf, u16 len);

