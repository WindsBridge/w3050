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
// File    : demo.h
// Purpose : the demo for W3050-10
// History : Created by WB on 2019-08-10 13:42:46
//           Last Modified time: 2019-08-15 14:56:11
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
#pragma once
#include "wlibc-hdlc-codec.h"
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
//透传模块支持的命令以及命令回复
typedef enum {
  W8100_CMD_CFG_QRY_NET_TOP = 79,      // w3050_qry_net_top_s
  W8100_CMD_CFG_QRY_NET_TOP_IND = 179, // w3050_qry_net_top_s

  W8100_CMD_SEND_DATA = 200, //命令行模式透传
  W8100_CMD_RECV_DATA = 200, //命令行模式透传

  W8100_CMD_NET_WOEK_FIN = 203,  // w3050_event_ind_net_work CCO&STA组网完成
  W8100_CMD_EVT_IND_ERR  = 204, // w3050_event_ind_err_s //操作错误上报错误码
} w3050_cmd_e;

typedef enum {
  W8100_ERR_OK = 0,
  W8100_ERR_CMD_NOT_SUPPORT,   //命令不支持
  W8100_ERR_NET_WORK_NOT_FIN,  //组网未完成
  W8100_ERR_HDLC_SUM_ERR,      // hdlc sum和错误
  W8100_ERR_HDLC_DATA_LEN_OUT, //数据长度超出正常范围
  W8100_ERR_PARM_ERR
} w3050_err_code_e;

typedef struct {
  u8 cmd;
  u8 mac[6]; // 200:d_mac  201:s_mac
  u8 data_len;
  u8 data[0];
} w3050_cmd_s;

typedef struct {
  u8 result; // 1
} w3050_event_ind_net_work;

typedef struct {
  u8 err_code; // w3050_err_code_e
} w3050_event_ind_err_s;

typedef struct {
  u8 my_tei;
  u8 proxy_tei;
  u8 role;
  u8 level;

  u8 year;
  u8 month;
  u8 day;
  u8 hour;

  u8 minute;
  u8 second;
  u8 my_mac[6];
} w3050_qry_net_top_s; //查询网络TOPO
