//----------------------------------------------------------------------------------------------------------------------
// Copyright (c) 2014-203, WindsBridge - windsbridge.com All rights reserved.
//
// Redistribution and use in source and binary forms, with or without modification, are permitted provided that the
// following conditions are met:
// 1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following
//    disclaimer.
// 2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the
//    following disclaimer in the documentation and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY BEIJING WINDSBRIDGE TECHNOLOGY CO.,LTD.``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES,
// INCLUDING, BUT NOT LIMITED TO,THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL BEIJING WINDSBRIDGE TECHNOLOGY CO.,LTD. OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
// INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
// ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
//  File    : wb-err.h
//  Purpose : error definition file
//  History : Created by BDX on 2015-08-19
//            Last Modified time: 2019-04-09 19:10:52
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
#ifndef	_WB_ERR_H_
#define	_WB_ERR_H_
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
// Error definitions
//----------------------------------------------------------------------------------------------------------------------
#define WB_ERR_OK                      0   // success
#define WB_ERR_INVALID_PARAMTERS       1   // Invalid input parameters
#define WB_ERR_NO_PARAMTERS            2
#define WB_ERR_NOT_SUPPORT             4
#define WB_ERR_NOT_FOUND               5
#define WB_ERR_SKIP                    6
#define WB_ERR_INVALID_CODE            7
#define WB_ERR_FATAL                   8

#define WB_ERR_ACCESSED_DENY           9   // User access deny 用户访问拒绝，UID非法或权限不足
#define WB_ERR_TOKEN_INVALID           10  // TOKEN is invalid
#define WB_ERR_NOT_INIT                11  // don't call sysinit before sending any message to LQBC
#define WB_ERR_USRNAME_INVALID         12  // user name is invalid
#define WB_ERR_USRPSW_INVALID          13  // user password is invalid
#define WB_ERR_REQ_INVALID_SIZE        14  // req length is invalid
#define WB_ERR_ACT_INVALID             15  //
#define WB_ERR_NOT_FOUND_USR_RSP       16  // user don't define rsp
#define WB_ERR_SEND_SMS_CODE_FAIL      17
#define WB_ERR_INVALID_PK_HEADER       18
#define WB_ERR_ALREADY_START           19  //已经启动。
#define WB_ERR_NOT_LOGIN               20  //未登录。
#define WB_ERR_NO_MEM                  21  //没有内存。
#define WB_ERR_NOT_CONNECT             22  //没有连接。
#define WB_ERR_INVALID_GID             23  //gid非法。
#define WB_ERR_APP_LOCK                24  //app锁定。
#define WB_ERR_INVALID_MID             25  //mid非法。
#define WB_ERR_INVALID_QR              26  //
#define WB_ERR_INVALID_SYS_TIME        27  //非法时间。
#define WB_ERR_QR_SCAN_TO              28
#define WB_ERR_QR_SCAN_KEY             29
#define WB_ERR_INVALID_OID             30  //非法oid
#define WB_ERR_EXIST_USER              31  //
#define WB_ERR_EXIST_USER_AUDIT1       32
#define WB_ERR_EXIST_USER_AUDIT2       33
#define WB_ERR_EXIST_USER_AUDIT_FAIL   34
#define WB_ERR_ACT_NOT_SUPPORT         35  //act不支持。
#define WB_ERR_SND_ERR                 36  //
#define WB_ERR_LOGOUT                  37  //exit
#define WB_ERR_AUTH                    38
#define WB_ERR_JSON_FORMAT             39
#define WB_ERR_JSON_VALUE_NOT_FOUND    40
#define WB_ERR_INVALID_GDID            41  // 非法gdid
#define WB_ERR_INVALID_ACTION          42  //action 非法。
#define WB_ERR_INVALID_CHKSUM          43  //chksum 错误。
#define WB_ERR_TIME_OUT                44  //超时。
#define WB_ERR_INVALID_PERIOD          45  //
#define WB_ERR_INVALID_UPN             46
#define WB_ERR_INVALID_ID              47  //id非法，
#define WB_ERR_BUSY                    48  //忙。
#define WB_ERR_ALREADY_OPENED          49

#define WB_ERR_TCP_CONNECT_FAIL        50
#define WB_ERR_TCP_REGISTER_FAIL       51
#define WB_ERR_TCP_SND_BUSY            52
#define WB_ERR_TCP_SND_FAIL            53
#define WB_ERR_TCP_RCV_ERR             64
#define WB_ERR_TOO_SMALL               65
#define WB_ERR_TOO_LARGE               66
#define WB_ERR_INVALID_MODE            67
#define WB_ERR_WAIT                    68
#define WB_ERR_INVALID_SCODE           69
#define WB_ERR_INVALID_HCRC            70
#define WB_ERR_TOO_SMALL_CAHCE         71
#define WB_ERR_INVALID_DCRC            72

#define WB_ERR_BAD_FRAME_TOO_LARGE     102
#define WB_ERR_INVALID_PK_SIZE         104
#define WB_ERR_INVALID_PK_TOKEN        105
#define WB_ERR_SEND_URL_FAIL           106
#define WB_ERR_DB_RECORD_NULL          107 // no record
#define WB_ERR_DB_FIELD_NULL           108 // no field
#define WB_ERR_DB_NOT_FOUND            109 // no DB exist or not start
#define WB_ERR_DB_INVALID_FIELD        110
#define WB_ERR_DB_UPDATE_FAIL          111
#define WB_ERR_DB_CONTENT_TOO_LARGE    112
#define WB_ERR_DB_TABLE_NOT_FOUND      113
#define WB_ERR_INCOMPLETE_PARAMETER    114 // 参数字段缺失
#define WB_ERR_DB_INSERT_FAIL          115
#define WB_ERR_DB_EXIST_FIELD          116
#define WB_ERR_DB_ACCESSED_FAIL        117

#define WB_ERR_SMS_CODE_CHK            150
#define WB_ERR_SMS_CODE_SEND_TIME      151   // SMS Code should > time
#define WB_ERR_SMS_SEND_TIME           152

#define WB_ERR_INVALID_BODY            200
#define WB_ERR_MSG_NOT_SUPPORT         201
#define WB_ERR_UNSUPPORT_APP           202
#define WB_ERR_OS_ERROR                203

#define WB_ERR_NO_SPACE                210
#define WB_ERR_CRC                     211
#define WB_ERR_RESOURCE_TIMEOUT        212 // Timeout while trying to access the resource

#define WB_ERR_STATUS_FRM_OK                 300
#define WB_ERR_STATUS_FRM_CRC_ERR            301
#define WB_ERR_STATUS_FRM_BUF_TOO_SMALL_ERR  302
#define WB_ERR_STATUS_FRM_BUF_UNKNOWN_ERR    303
#define WB_ERR_FRM_SND_ERR                   304

#define WB_ERR_AUDREC_ERROR                  351
#define WB_ERR_AUDREC_PLAYING				         352
#define WB_ERR_AUDREC_RECORDING			         353
#define WB_ERR_AUDREC_UNRECORD				       354
#define WB_ERR_AUDREC_UNPLAY				         355
#define WB_ERR_AUDREC_BUSY				           356
#define WB_ERR_AUDREC_OVERFLOW               357

#define WB_ERR_ATP_INVALID_PARA              1001
#define WB_ERR_ATP_NO_MORE_MEMORY            1002
#define WB_ERR_ATP_WITHOUT_CR                1003
#define WB_ERR_ATP_SYNTAX_ERROR              1004
#define WB_ERR_ATP_NMAE_TOO_LONG             1005
#define WB_ERR_ATP_PARAM_TOO_LONG            1006
#define WB_ERR_ATP_SYNTAX_ERROR_AT_HEAD      1007

#define WB_ERR_FAIL                          65534
#define WB_ERR_UNKNOWN                       65535
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
#endif // _WB_ERR_H_
//----------------------------------------------------------------------------------------------------------------------
