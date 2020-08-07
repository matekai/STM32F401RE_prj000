/*==============================================================================
  PC間通信　受信解析処理用ヘッダ [pccom_anly.h]
  
 -------------------------------------------------------------------------------
  << REVISION HISTORY >>
  2020/xx/xx        matekai
  Initial Release
  
==============================================================================*/

/*======================================
  二重インクルード防止
======================================*/
#ifndef PCCOM_ANLY_H
#define PCCOM_ANLY_H
#include "common.h"
#include "gpio.h"

/*======================================
  実体 or 外部参照切り替え
======================================*/
#ifdef PCCOM_ANLY_EXTERN
#define Extern
#else
#define Extern extern
#endif

/*======================================
  define
======================================*/


/*======================================
  typedef
======================================*/
typedef enum eCMD_CODE
{
	CMD_PON,
	CMD_POFF,
	CMD_PIN,
	CMD_VER,
	CMD_HELP,
	CMD_MAX
} CMD_CODE ;

typedef struct strCMD_RCVD
{
	CMD_CODE cmd ;
	union unCMD_OPTION
	{
		struct strCMDOP_PORT
		{
			PORT_TYPE ptype ;
			U16       ptno  ;
		} op_port ;

	} cmdop ;
} CMD_RCVD ;


/*======================================
  global argument
======================================*/


/*======================================
  function prototype
======================================*/
Extern U8 pccom_anly_get( CMD_RCVD *cmd_rcvd ) ;
Extern void pccom_anly_initram( void ) ;


#undef Extern
#endif /* ifndef hoge_H */
