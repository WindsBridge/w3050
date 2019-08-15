//----------------------------------------------------------------------------------------------------------------------
// Copyright (c) 2014-2019, WindsBridge - http://windsbridge.com All rights reserved!
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
// File    : demo.c
// Purpose : the demo for W3050-10
// History : Created by WB on 2019-08-15 14:31:56
//           Last Modified time: 2019-08-15 14:57:38
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
#include "demo.h"
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
//HPLC编码的buff最大长度
#define HDLC_CTX_BUF_MAX 1024

static u8 g_hdlc_ctx_cache[HDLC_CTX_BUF_MAX];
static u8 g_hdlc_enc_buf[HDLC_CTX_BUF_MAX] ={0,};

static u32 * g_wlibc_hdlc_ctx = nil;
extern void w3050_mcu_uart_send_data(u8* data, u16 len);
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
void w3050_mcu_rev_data_proc(u8* data, u16 len, wlibc_hdlc_status_e state) {
  if (state != 0) {
    return;
  }

  w3050_cmd_s *ptr = (w3050_cmd_s *)data;
  if (ptr->cmd == W8100_CMD_RECV_DATA) {
    // WB-TODO: 2019-08-15 14:32:39 receive data, process it.
  } else if (ptr->cmd == W8100_CMD_NET_WOEK_FIN) {
    // WB-TODO: 2019-08-15 14:32:39 ...
    // NOT SUPPORT for this version.
  } else if (ptr->cmd == W8100_CMD_EVT_IND_ERR) {
    // WB-TODO: 2019-08-15 14:32:39 found error
  }
}

//----------------------------------------------------------------------------------------------------------------------
// d_mac:
// data_len <= 100 bytes
//----------------------------------------------------------------------------------------------------------------------
u8 g_cmd_buf[500] = {0};
static void w3050_mcu_send_data(u8 d_mac[6], u8 *data, u8 data_len) {
  u32 enc_data_len = 0, ret = 0;
  w3050_cmd_s *cmd_s = (w3050_cmd_s*)g_cmd_buf;
  cmd_s->cmd = W8100_CMD_SEND_DATA;
  memcpy(cmd_s->mac, d_mac, 6);
  cmd_s->data_len = data_len;

  if (data && data_len) {
    memcpy(cmd_s->data, data, data_len);
  }

  enc_data_len = wlibc_hdlc_encode((u8 *)cmd_s, data_len + sizeof(w3050_cmd_s), g_hdlc_enc_buf, HDLC_CTX_BUF_MAX);

  // uart send data
  w3050_mcu_uart_send_data(g_hdlc_enc_buf, enc_data_len);
}

//----------------------------------------------------------------------------------------------------------------------
// uart recv data
//----------------------------------------------------------------------------------------------------------------------
void w3050_mcu_uart_data_input(u8 *data, u8 len) {
  wlibc_hdlc_decode((wlibc_hdlc_decode_s*)g_wlibc_hdlc_ctx, data, len);
}

void w3050_mcu_init(void) {
  g_wlibc_hdlc_ctx = (u32 *)wlibc_hdlc_decode_init(g_hdlc_ctx_cache, HDLC_CTX_BUF_MAX, w3050_mcu_rev_data_proc);
}
