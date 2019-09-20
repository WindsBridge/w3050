//----------------------------------------------------------------------------------------------------------------------
// Copyright (c) 2014-2030, WindsBridge - windsbridge.com All rights reserved.
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
// File    : wb-types.h
// Purpose : windsbridge coding basic types
// History : Created by BDX on 2015-08-19
//           Last Modified time: 2019-08-15 14:49:43
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
#pragma once
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
#ifndef	_WB_TYPES_H_
#define	_WB_TYPES_H_
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
// __WB_SIZE_T__=1   ---> need size_t
// __WB_CPUBIT__=64 or 32
// __WB_UNICODE_SUPPORT__=1
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
#if defined(__cplusplus)
#define	WB_CPP_BEGIN_DECLS	extern "C" {
#define	WB_CPP_END_DECLS	}
#else
#define	WB_CPP_BEGIN_DECLS
#define	WB_CPP_END_DECLS
#endif

#define BDXI
#define BDXO
#define BDXIO

#define	BDX_CPP_BEGIN_DECLS WB_CPP_BEGIN_DECLS
#define BDX_CPP_END_DECLS WB_CPP_END_DECLS

#if defined(__APPLE__) && defined(__llvm__)
#define __WB_PLATFORM_OS_X__
#elif defined(__linux__) && defined(__GNUC__)
#define __WB_PLATFORM_LINUX__
#elif defined(__GMDM__) && defined(__GNUC__)
#define __WB_PLATFORM_GMDM__
#elif defined(__WDP__) && defined(__GNUC__)
#define __WB_PLATFORM_WDP__
#elif defined(__XCM__) && defined(__GNUC__)
#define __WB_PLATFORM_XCM__
#elif defined(__WIN32__) && defined(__GNUC__)
#define __WB_PLATFORM_WIN32
#elif defined(__W8010__) && defined(__GNUC__)
#define __WB_ARCH_W8010__
#define __WB_ARCH_WXXXX__
#elif defined(__W8020__) && defined(__GNUC__)
#define __WB_ARCH_W8020__
#define __WB_ARCH_WXXXX__
#elif defined(__W8030__) && defined(__GNUC__)
#define __WB_ARCH_W8030__
#define __WB_ARCH_WXXXX__
#elif defined(__W8100__) && defined(__GNUC__)
#define __WB_ARCH_W8100__
#define __WB_ARCH_WXXXX__
#elif defined(__W8600__) && defined(__GNUC__)
#define __WB_ARCH_W8600__
#define __WB_ARCH_WXXXX__
#elif defined(__W8900__) && defined(__GNUC__)
#define __WB_ARCH_W8900__
#define __WB_ARCH_WXXXX__
#else
#error "no valid WB platform found!"
#endif

#if defined(__GNUC__) || defined(__llvm__) || defined(__LVM__)
#define __WB_COMPILER_GCCLLVM__
#endif

#if defined(WB_ARCH_W8010)
  #define WNOP()  __asm("nop")
  #define WSWI()  __asm {swi 0x123456}
#endif

// basic data type definition
#define __WB_DATA_TYPES__

#if !defined(__BDX_BASIC_DATA_TYPE1_H__)
#define __BDX_BASIC_DATA_TYPE1_H__
// following posix standard
typedef int              s32;
typedef unsigned int     u32;
typedef unsigned short   u16;
typedef short            s16;
typedef unsigned char    u8;
typedef char             s8;
typedef char             ut8;
typedef char             bool_t;
#endif // __BDX_BASIC_DATA_TYPE1_H__

#if !defined(__BDX_BASIC_DATA_TYPE2_H__)
#define __BDX_BASIC_DATA_TYPE2_H__
#if !defined(__cplusplus) && !defined(__WB_PLATFORM_OS_X__) && !defined(__WB_PLATFORM_WDP__)
typedef u8              bool;
#elif !defined(__cplusplus) && !defined(__WB_PLATFORM_WDP__)
#if !defined(__WB_PLATFORM_OS_X__)
typedef u8               bool;
#endif
#elif  !defined(__cplusplus) && defined(__WB_PLATFORM_WDP_SIMU__)
typedef u8               bool;
#endif
#endif // __BDX_BASIC_DATA_TYPE2_H__

#if defined(__WB_ARCH_WXXXX__)
#define WB_PACKED __attribute__ ((__packed__))
#endif

typedef void*          ptr_t;      // unknown pointer type
typedef char*          pstr_t;     // string pointer
typedef const s8*      pcstr_t;    // const string pointer
typedef       u8*      pbuf_t;     // buffer pointer
typedef const u8*      pcbuf_t;    // const buffer pointer
typedef       u8*      pu8_t;
typedef const u8*      pcu8_t;
typedef const s8*      pcs8_t;
typedef const u8       cu8_t;
typedef const s8       cs8_t;

#if defined(__WB_UNICODE_SUPPORT__)
typedef       s16*   tchar_t;;
#else
typedef       s8*    tchar_t;;
#endif

#ifndef NULL
  #define NULL (void*)0
#endif

#ifndef FALSE
  #define FALSE 0
#endif

#ifndef TRUE
  #define TRUE 1
#endif

#ifndef  nil
  #define  nil  (void*)0
#endif
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
typedef u16 ocid_t;  // object class id
typedef u32 evtid_t; // event id define
typedef u16 oeid_t;  // object extpand id
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
// predefined object class and object handle
// COBJ is base class of WDP all object
//----------------------------------------------------------------------------------------------------------------------
typedef void* obj_h;  // object handle
typedef obj_h mem_h;  // memeory object handle
typedef obj_h str_h;  // string object handle
typedef obj_h buf_h;  // buffer object handle
typedef obj_h pbuf_h; // ping-pong buffer object handle
typedef obj_h rbuf_h; // ring buffer object handle
typedef obj_h tm_h;   // time object handle
typedef obj_h list_h; // list object handle
typedef list_h stack_h; // stack object handle
typedef list_h queue_h; // queue object handle
typedef obj_h evt_h; // event object handle
typedef evt_h tmr_h; // event object handle
typedef obj_h trd_h; // thread object handle
typedef trd_h app_H; // app business object handle

// event param
typedef u32    iparm_t;
typedef void*  pparm_t;

typedef obj_h   dev_h; // device object handle
typedef u8      dsid_t;
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
#define  WB_O
#define  WB_IO
#define  WB_I

#define  WB_PUB  extern
#define  WB_PRVL static inline
#define  WB_PRV  static

#define  BDX_PUB  WB_PUB
#define  BDX_PRVL WB_PRVL
#define  BDX_PRV  WB_PRV

#define  WB_UPCASE(c)          ( ((c) >= 'a' && (c) <= 'z') ? ((c) - 0x20) : (c) )
#define  WB_CHK_DEC_CHAR(c)    ((c) >= '0' && (c) <= '9')
#define  WB_CHK_HEX_CHAR(c)    ( ((c) >= '0' && (c) <= '9') ||((c) >= 'A' && (c) <= 'F') ||((c) >= 'a' && (c) <= 'f') )
#define  WB_INC_CHK(val)       (val = ((val)+1 > (val)) ? (val)+1 : (val))
#define  WB_ARR_SIZE(a)        ( sizeof( (a) ) / sizeof( (a[0]) ) )
#define  WB_COUNTOF_FIELD(x)   WB_ARR_SIZE(x)
#define  WB_SHIFT(value, n)    (((n) > 0) ? ((value) << (n)) : ((value) >> -(n)))
#define  WB_ABS_VALUE(x)       (((x) < 0) ? -(x) : (x))
#define  WB_BIT(VAL,N)         (((VAL) >> (N)) & 1 ? 1 : 0) // 整数val取第n位的bit
#define  WB_MAX(a,b)           ( ((a)>(b)) ? (a):(b) )
#define  WB_MIN(a,b)           ( ((a)>(b)) ? (b):(a) )
#define  WB_OFFSETOF(t, m)     ((size_t) &((t *)4)->m) // get member offsert
#define  WB_VERSION(x,y,z)     ((((u8)(x)) << 16) + (((u8)(y)) << 8) + ((u8)(z))) // major minor patch
#define  WB_VERSION_X(ver)     ((u8)(ver >> 16))
#define  WB_VERSION_Y(ver)     ((u8)(ver >> 8))
#define  WB_VERSION_Z(ver)     ((u8)(ver))

#define WB_MKU64(l, h)         ((u64)(((u32)(l)) | ((u64)((u32)(h))) << 32))
#define WB_LOU64(x)            (u32)(x)
#define WB_HIU64(x)            ((u32)((u64)(x) >> 32))
#define WB_MKS16(a, b)         ((s16)(((u8)(a)) | ((s16)((u8)(b))) << 8))
#define WB_MKS32(a, b)         ((s32)(((u16)(a)) | ((s32)((u16)(b))) << 16))
#define WB_LOS8(w)             ((s8)(w))
#define WB_HIS8(w)             ((s8)((u16)(w) >> 8))
#define WB_LOS16(l)            ((s16)(l))
#define WB_HIS16(l)            ((s16)((u32)(l) >> 16))

#define WB_MKU16(a, b)         ((u16)(((u8)(a)) | ((u16)((u8)(b))) << 8))
#define WB_MKU32(a, b)         ((u32)(((u16)(a)) | ((u32)((u16)(b))) << 16))
#define WB_LOU8(w)             ((u8)(w))
#define WB_HIU8(w)             ((u8)((u16)(w) >> 8))
#define WB_LOU16(l)            ((u16)(l))
#define WB_HIU16(l)            ((u16)((u32)(l) >> 16))

#define WB_MSB(x)              (((x) >> 8) & 0xff) // most signif byte of 2-byte integer
#define WB_LSB(x)              ((x) & 0xff)        // least signif byte of 2-byte integer
#define WB_MKU16_P(p)          (((u16)(p)[0] << 8) | (u16)(p)[1])
#define WB_MKU32_P(p)          (((u32)(p)[0] << 24) | ((u32)(p)[1] << 16) | ((u32)(p)[2] << 8) | (u32)(p)[3])

#define WB_SWAP16(p)           (((u16)(p)[1] << 8) | (u16)(p)[0])
#define WB_SWAP32(p)           (((u32)(p)[3] << 24) | ((u32)(p)[2] << 16) | ((u32)(p)[1] << 8) | (u32)(p)[0])

#define WB_UNREF(x)            x = x

#define WB_ARRAY_SIZE(_a)         (sizeof(_a)/sizeof(_a[0]))
#define WB_LAST_ELEMENT(_x)       (&_x[WB_ARRAY_SIZE(_x)-1])
#define WB_TCHAR_SIZEOF(_sz)      (sizeof(_sz)/sizeof(TCHAR))
#define WB_BOUND(_x, _min, _max)  ((_x) < (_min) ? (_min) : ((_x) > (_max) ? (max):(_x)))
#define WB_ROUNDEDSIZEOF(t)       ((sizeof(t)+sizeof(int)-1)&~(sizeof(int)-1))

#define WB_ALIGN(_val,_exp)       (((_val) + ((_exp)-1)) & ~((_exp)-1))
#define WB_ALIGN32(_val)          ((((u32)(_val))&(~3))+4)
#define WB_IS_ALIGN32(_add)       ((u32)(((u32)(_add)) & 0x3)==0) // (!((x)&3)
#define WB_IS_ALIGN16(_size)      ((u32)(((u32)(_size))& 0x0f) == 0)

#define WB_ABS(_x)             ((_x<0)?(-_x):(_x))
#define WB_NUM2STR(num)        #num
#define WB_MAX_PATH            256
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
WB_CPP_BEGIN_DECLS
#define WB_DISALLOW_COPY_AND_ASSIGN(TypeName) \
  TypeName(const TypeName&);   \
  TypeName& operator=(const TypeName&)
WB_CPP_END_DECLS

#define WB_ZERO_STRU(struct_name, ptr)         memset(ptr, 0, sizeof(struct_name))
#define WB_ZERO_ARRAY(array)                   memset((void*)array, 0, sizeof(array))
#define WB_STRU_TO_NSDATA(ptr, struct_name)    ([NSData dataWithBytes:(ptr) length:sizeof(struct_name)])
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
#if defined(__WB_COMPILER_GCCLLVM__)
#define WDP_OCLASS_ATTR  __attribute__((section("WDP.OCLASS"), used))
#else
#define WDP_OCLASS_ATTR
#endif

#if defined(__WB_COMPILER_GCCLLVM__)
#define WB_DATA_ATTR(x) __attribute__((aligned(4), section(". ## x"), used))
#else
#define WB_DATA_ATTR(x)
#endif
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
// iOS GCD UI Queue
//----------------------------------------------------------------------------------------------------------------------
#define WB_IOS_UI_QUEUE_BEGIN dispatch_async(dispatch_get_main_queue(), ^{
#define WB_IOS_UI_QUEUE_END   });

// Once BLOCK
#define WB_IOS_BLOCK_ONCE_BEGIN  static dispatch_once_t once; dispatch_once(&once, ^ {
#define WB_IOS_BLOCK_ONCE_END     });
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
#define WB_STRU_MEM_IS_VALID(dest, src)      ((int)(sizeof(dest)-1) >= (int)strlen(src))?1:0
#define WB_STRNCPY_STRU_MEM_STR(dest, src)   if(src && dest) { strncpy(dest, src, (size_t)sizeof(dest)-1); }
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
#define BDX_UNREF(x)       WB_UNREF(x)
#define BDX_MIN(x,y)       WB_MIN(x,y)
#define BDX_MAX(x,y)       WB_MAX(x,y)

#define BDX_MKU64(l, h)    WB_MKU64(l, h)
#define BDX_LOU64(x)       WB_LOU64(x)
#define BDX_HIU64(x)       WB_HIU64(x)
#define BDX_MKS16(a, b)    WB_MKS16(a, b)
#define BDX_MKS32(a, b)    WB_MKS32(a, b)
#define BDX_LOS8(w)        WB_LOS8(w)
#define BDX_HIS8(w)        WB_HIS8(w)
#define BDX_LOS16(l)       WB_LOS16(l)
#define BDX_HIS16(l)       WB_HIS16(l)

#define BDX_MKU16(a, b)     WB_MKU16(a, b)
#define BDX_MKU32(a, b)     WB_MKU32(a, b)
#define BDX_LOU8(w)         WB_LOU8(w)
#define BDX_HIU8(w)         WB_HIU8(w)
#define BDX_LOU16(l)        WB_LOU16(l)
#define BDX_HIU16(l)        WB_HIU16(l)

#define BDX_ABS(x)          WB_ABS(x)

#define  BDX_UPCASE(c)          WB_UPCASE(c)
#define  BDX_CHK_DEC_CHAR(c)    WB_CHK_DEC_CHAR(c)
#define  BDX_CHK_HEX_CHAR(c)    WB_CHK_HEX_CHAR(c)
#define  BDX_INC_CHK(val)       WB_INC_CHK(val)
#define  BDX_ARR_SIZE(a)        WB_ARR_SIZE(a)
#define  BDX_COUNTOF_FIELD(x)   WB_COUNTOF_FIELD(x)
#define  BDX_BIT(VAL,N)         WB_BIT(VAL,N)
#define  BDX_OFFSETOF(t, m)     WB_OFFSETOF(t, m)
#define  BDX_VERSION(x,y,z)     WB_VERSION(x,y,z)
#define  BDX_VERSION_X(ver)     WB_VERSION_X(ver)
#define  BDX_VERSION_Y(ver)     WB_VERSION_Y(ver)
#define  BDX_VERSION_Z(ver)     WB_VERSION_Z(ver)
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
#include "wb-err.h"
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
typedef struct {
  s32	tm_sec;
  s32	tm_min;
  s32	tm_hour;
  s32	tm_mday;
  s32	tm_mon;
  s32	tm_year;
} wlibc_tm_s;

#define WDPM_O
#define WDPM_I
#define WDPM_IO
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
#define WDP_MSGDATA_IAR_NA            (0)
#define WDP_MSGDATA_IAR_REQ           (1)
#define WDP_MSGDATA_IAR_ACK           (2)
#define WDP_MSGDATA_IAR_IND           (3)
#define WDP_MSGDATA_IAR_ERR           (4)
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
#if defined(__WB_PLATFORM_OS_X__) || defined(__WB_PLATFORM_LINUX__)
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdint.h>
#include <time.h>
#include "wlibc-types-macos.h"
#endif

#if defined(__WB_ARCH_WXXXX__)
#define __bool_true_false_are_defined 1
#define __STDBOOL_H
#undef bool
#undef true
#undef false
#define bool u8
#define false 0
#define true  1
#include <string.h>
#include <stdint.h>
#endif
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
// from ISO/IEC 988:1999 spec
// 7.18.2.2 ~ 7.18.2.3 Limits of exact-width integer types
#define WB_MAX_S8                   127
#define WB_MIN_S8                   (-WB_MAX_S8 - 1)
#define WB_MAX_U8                   255
#define WB_MIN_U8                   0
#define WB_MAX_S16                  32767
#define WB_MIN_S16                  (-WB_MAX_S16 - 1)
#define WB_MAX_U16                  65535
#define WB_MIN_U16                  0
#define WB_MAX_S32                  2147483647L
#define WB_MIN_S32                  (-WB_MAX_S32 - 1)
#define WB_MAX_U32                  4294967295U
#define WB_MIN_U32                  0U
#define WB_MAX_U64                  18446744073709551615ULL
#define WB_MIN_U64                  0
#define WB_MAX_S64                  9223372036854775807L
#define WB_MIN_S64                  (-WB_MAX_S64 - 1)

#ifndef __WB_CPUBIT__
  #if (__WORDSIZE == 64)
    #define __WB_CPUBIT__ 64
  #else
    #define __WB_CPUBIT__ 32
  #endif
#endif

//
// 7.18.2.4 Limits of integer types capable of holding object pointers
// Fixed-size types, underlying types depend on word size and compiler.
// void* 型指针的类型定义: sptr_t  uptr_t
//
#if (__WB_CPUBIT__ == 64)
typedef long int           sptr_t;
typedef unsigned long int  uptr_t;
# define WB_INTPTR_MAX     9223372036854775807L
# define WB_UINTPTR_MAX    18446744073709551615UL
# define WB_U64_C(c)       c ## UL
# define WB_S64_C(c)       c ## L
#else
typedef int                sptr_t;
typedef unsigned  int      uptr_t;
# define WB_INTPTR_MAX     2147483647L
# define WB_UINTPTR_MAX    4294967295UL
# define WB_S64_C(c)       c ## LL
# define WB_U64_C(c)       c ## ULL
#endif

#define WB_INTPTR_MIN        (-WB_INTPTR_MAX-1)

# if (__WB_CPUBIT__ == 64)
typedef signed long int         s64;
typedef unsigned long int       u64;
# else
__extension__
typedef signed long long int    s64;
typedef unsigned long long int  u64;
# endif

# if (__WB_SIZE_T__ == 1)
  # if (__WB_CPUBIT__ == 64)
    typedef size_t u64; // typeof(sizeof(t))
  # else
    typedef size_t u32;
  # endif
#endif
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
typedef u32 (* wcb_f)(obj_h ptr, s32 status, s32 transmissions);
typedef struct {
  pcstr_t name;

  // Initialize the port
  u32 (* init)(void);

  // send a packet from the user buffer
  u32 (* send)(wcb_f sent_callback, obj_h ptr);
} wcb_ctx_s;
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
WB_PUB pcstr_t wlibc_ver_board_ver(void);  // "W1010-10-01-53"
WB_PUB pcstr_t wlibc_ver_prod_model(void); // "W1010-10-01"
WB_PUB pcstr_t wlibc_ver_arch_model(void); // "W8010-11"
WB_PUB pcstr_t wlibc_ver_chip_ver(void);   // "snode"
WB_PUB pcstr_t wlibc_ver_dt(void);         // "2018-06-27 19:05:39"
WB_PUB pcstr_t wlibc_ver_pver(void);       // "W1010-10-01-53 11.10.05.00 2311b51"
WB_PUB pcstr_t wlibc_ver_str(void);        // "11.10.05.00, built 2018-06-27 19:05:39"
WB_PUB pcstr_t wlibc_ver_fver(void);       // "11.10.05.00"
WB_PUB pcstr_t wlibc_ver_rver(void);       // "windsbridge W8010-11 snode W1010-10-10 2311b51"
WB_PUB pcstr_t wlibc_ver_plat_ver(void);   // "0.5.0"
WB_PUB pcstr_t wlibc_ver_app_ver(void);    // "0.4.0"
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
#endif // _WB_TYPES_H_
