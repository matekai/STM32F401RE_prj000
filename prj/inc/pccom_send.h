/*==============================================================================
  PC間通信　送信処理用ヘッダ [pccom_send.h]
  
 -------------------------------------------------------------------------------
  << REVISION HISTORY >>
  2020/xx/xx        matekai
  Initial Release
  
==============================================================================*/

/*======================================
  二重インクルード防止
======================================*/
#ifndef PCCOM_SEND_H
#define PCCOM_SEND_H
#include "common.h"

/*======================================
  実体 or 外部参照切り替え
======================================*/
#ifdef PCCOM_SEND_EXTERN
#define Extern
#else
#define Extern extern
#endif

/*======================================
  define
======================================*/
#define PCCOM_MAX_SENDBUF  ( U16 )( 256U )

/*======================================
  typedef
======================================*/


/*======================================
  global argument
======================================*/


/*======================================
  function prototype
======================================*/
Extern void pccom_send_cycle( void ) ;
Extern U8 pccom_send_set( U8 *, U16 ) ;
Extern U8 pccom_send_sig4input( void ) ;
Extern void pccom_send_initram( void ) ;

#undef Extern
#endif /* ifndef hoge_H */
