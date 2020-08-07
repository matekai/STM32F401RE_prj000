/*==============================================================================
  PC�ԒʐM�@��M��͏����p�w�b�_ [pccom_anly.h]
  
 -------------------------------------------------------------------------------
  << REVISION HISTORY >>
  2020/xx/xx        matekai
  Initial Release
  
==============================================================================*/

/*======================================
  ��d�C���N���[�h�h�~
======================================*/
#ifndef PCCOM_ANLY_H
#define PCCOM_ANLY_H
#include "common.h"
#include "gpio.h"

/*======================================
  ���� or �O���Q�Ɛ؂�ւ�
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
