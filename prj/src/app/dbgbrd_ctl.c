/*==============================================================================
  �f�o�b�O�{�[�h���䏈�� [dbgbrd_ctl.c]
  
 -------------------------------------------------------------------------------
  << REVISION HISTORY >>
  2020/xx/xx        matekai
  Initial Release
  
==============================================================================*/

#define DBGBRD_CTL_EXTERN

/*=====================================
  include
=====================================*/
#include <string.h>

#include "common.h"
#include "pccom_anly.h"
#include "pccom_send.h"
#include "gpio.h"
#include "sprintf.h"
#include "dbgbrd_ctl.h"


/*=====================================
  define
=====================================*/
#define ERRMSG_INVALID_INPUT    ( "Error!! Invalid input data!!\r\n" )
#define ERRMSG_PORT_RSVD        ( "Error!! Cannot use specified GPIO(Not implement or System Reserved)\r\n" )

#define HELP_MSG ( \
" << Usage >>\r\n\
pon : Set 1 to specified GPIO\r\n\
poff: Set 0 to specified GPIO\r\n\
pin : Get input value from specified GPIO\r\n\
ver : Get version information\r\n\
?   : Display help(this message)\r\n\r\n" )

/*=====================================
  typedef
=====================================*/


/*=====================================
  static argument
=====================================*/
static const C8 *PORT_TYPE_STR[ PORT_E_MAX ] =
{
		"PA", "PB", "PC", "PD", "PE", "PH"
} ;

/*=====================================
  function prototype
=====================================*/
static void dbgbrd_ctl_pon( CMD_RCVD * ) ;
static void dbgbrd_ctl_poff( CMD_RCVD * ) ;
static void dbgbrd_ctl_pin( CMD_RCVD * ) ;
static void dbgbrd_ctl_ver( void ) ;
static void dbgbrd_ctl_help( void ) ;

/*=====================================
  global function
=====================================*/

/*==============================================================================
    �f�o�b�O�{�[�h�@���C�����䏈���֐�
  void dbgbrd_ctl_main( CMD_RCVD * )
  
 -------------------------------------------------------------------------------
  << Usage >>
  [ IN ]
  arg0:  ��M�R�}���h��̓f�[�^�\���̂ւ̃|�C���^
  
  [ OUT ]
  None
  
==============================================================================*/
void dbgbrd_ctl_main( CMD_RCVD *cmd_rcvd )
{
	/* ������NULL�H */
	if( cmd_rcvd == NULL_PTR )
	{
		/* do nothing */
	}
	else
	{
		/* ��M�����R�}���h���Ƃ̐���ɔ�΂� */
		switch( cmd_rcvd->cmd )
		{
		case CMD_PON:
			dbgbrd_ctl_pon( cmd_rcvd ) ;
			break ;
		case CMD_POFF:
			dbgbrd_ctl_poff( cmd_rcvd ) ;
			break ;
		case CMD_PIN:
			dbgbrd_ctl_pin( cmd_rcvd ) ;
			break ;
		case CMD_VER:
			dbgbrd_ctl_ver( ) ;
			break ;
		case CMD_HELP:
			dbgbrd_ctl_help( ) ;
			break ;
		case CMD_MAX:
			/* do nothing */
			break ;
		}
	}
	return ;
}

/*==============================================================================
    �f�o�b�O�{�[�h���� �ϐ������������֐�
  void dbgbrd_ctl_initram( void )

 -------------------------------------------------------------------------------
  << Usage >>
  [ IN ]
  None

  [ OUT ]
  None

==============================================================================*/
void dbgbrd_ctl_initram( void )
{
	return ;
}
/*=====================================
  local function
=====================================*/

/*==============================================================================
    �f�o�b�O�{�[�h����@�|�[�gON�����֐�
  void dbgbrd_ctl_pon( CMD_RCVD * )
  
 -------------------------------------------------------------------------------
  << Usage >>
  [ IN ]
  arg0:  ��M�R�}���h��̓f�[�^�\���̂ւ̃|�C���^
  
  [ OUT ]
  None
  
==============================================================================*/
static void dbgbrd_ctl_pon( CMD_RCVD *cmd_rcvd )
{
	PORT_TYPE ptype ;
	U8 ptno ;
	C8 str[ 32 ] ;
	/* ���x���Q�Ƃ���̂Ń��[�J���ϐ��ɓ���Ȃ��� */
	ptype = cmd_rcvd->cmdop.op_port.ptype ;
	ptno  = cmd_rcvd->cmdop.op_port.ptno ;

	/* ���͒l����H */
	if( ( ptype < PORT_E_MAX )
	 && ( ptno < 16 ) )
	{
		/* GPIO���V�X�e���\��ς݁H */
		if( GPIO_USAGE_TABLE[ ptype ][ ptno ] != GPIO_FREE )
		{
			/* �G���[���b�Z�[�W���t */
			pccom_send_set( ( U8 * )ERRMSG_PORT_RSVD, strlen( ERRMSG_PORT_RSVD ) ) ;
		}
		else
		{
			/* GPIO��High�o�� */
			stm32_gpio_out( ptype, ptno, U8_LVL_HIGH ) ;
			/* �����f�[�^�쐬 */
			tsprintf(str, "%s%d output to 1\r\n", PORT_TYPE_STR[ ptype ], ptno ) ;
			pccom_send_set( ( U8 * )str, strlen( str ) ) ;
		}
	}
	else
	{
		/* �G���[���b�Z�[�W���t */
		pccom_send_set( ( U8 * )ERRMSG_INVALID_INPUT, strlen( ERRMSG_INVALID_INPUT ) ) ;
	}

	return ;
}

/*==============================================================================
    �f�o�b�O�{�[�h����@�|�[�gOFF�����֐�
  void dbgbrd_ctl_poff( CMD_RCVD * )

 -------------------------------------------------------------------------------
  << Usage >>
  [ IN ]
  arg0:  ��M�R�}���h��̓f�[�^�\���̂ւ̃|�C���^

  [ OUT ]
  None

==============================================================================*/
static void dbgbrd_ctl_poff( CMD_RCVD *cmd_rcvd )
{
	PORT_TYPE ptype ;
	U8 ptno ;
	C8 str[ 32 ] ;
	/* ���x���Q�Ƃ���̂Ń��[�J���ϐ��ɓ���Ȃ��� */
	ptype = cmd_rcvd->cmdop.op_port.ptype ;
	ptno  = cmd_rcvd->cmdop.op_port.ptno ;

	/* ���͒l����H */
	if( ( ptype < PORT_E_MAX )
	 && ( ptno < 16 ) )
	{
		/* GPIO���V�X�e���\��ς݁H */
		if( GPIO_USAGE_TABLE[ ptype ][ ptno ] != GPIO_FREE )
		{
			/* �G���[���b�Z�[�W���t */
			pccom_send_set( ( U8 * )ERRMSG_PORT_RSVD, strlen( ERRMSG_PORT_RSVD ) ) ;
		}
		else
		{
			/* GPIO��Low�o�� */
			stm32_gpio_out( ptype, ptno, U8_LVL_LOW ) ;
			/* �����f�[�^�쐬 */
			tsprintf(str, "%s%d output to 0\r\n", PORT_TYPE_STR[ ptype ], ptno ) ;
			pccom_send_set( ( U8 * )str, strlen( str ) ) ;
		}
	}
	else
	{
		/* �G���[���b�Z�[�W���t */
		pccom_send_set( ( U8 * )ERRMSG_INVALID_INPUT, strlen( ERRMSG_INVALID_INPUT ) ) ;
	}

	return ;
}

/*==============================================================================
    �f�o�b�O�{�[�h����@�|�[�g���͎擾�����֐�
  void dbgbrd_ctl_pin( CMD_RCVD * )

 -------------------------------------------------------------------------------
  << Usage >>
  [ IN ]
  arg0:  ��M�R�}���h��̓f�[�^�\���̂ւ̃|�C���^

  [ OUT ]
  None

==============================================================================*/
static void dbgbrd_ctl_pin( CMD_RCVD *cmd_rcvd )
{
	PORT_TYPE ptype ;
	U8 ptno, pin ;
	C8 str[ 32 ] ;
	/* ���x���Q�Ƃ���̂Ń��[�J���ϐ��ɓ���Ȃ��� */
	ptype = cmd_rcvd->cmdop.op_port.ptype ;
	ptno  = cmd_rcvd->cmdop.op_port.ptno ;

	/* ���͒l����H */
	if( ( ptype < PORT_E_MAX )
	 && ( ptno < 16 ) )
	{
		/* GPIO���V�X�e���\��ς݁H */
		if( GPIO_USAGE_TABLE[ ptype ][ ptno ] != GPIO_FREE )
		{
			/* �G���[���b�Z�[�W���t */
			pccom_send_set( ( U8 * )ERRMSG_PORT_RSVD, strlen( ERRMSG_PORT_RSVD ) ) ;
		}
		else
		{
			/* GPIO���͒l�擾 */
			pin = stm32_gpio_in( ptype, ptno ) ;
			/* �����f�[�^�쐬 */
			tsprintf(str, "%s%d input value: %d\r\n", PORT_TYPE_STR[ ptype ], ptno, pin ) ;
			pccom_send_set( ( U8 * )str, strlen( str ) ) ;
		}
	}
	else
	{
		/* �G���[���b�Z�[�W���t */
		pccom_send_set( ( U8 * )ERRMSG_INVALID_INPUT, strlen( ERRMSG_INVALID_INPUT ) ) ;
	}

	return ;
}

/*==============================================================================
    �f�o�b�O�{�[�h����@�o�[�W�������o�͏����֐�
  void dbgbrd_ctl_ver( void )

 -------------------------------------------------------------------------------
  << Usage >>
  [ IN ]
  arg0:  ��M�R�}���h��̓f�[�^�\���̂ւ̃|�C���^

  [ OUT ]
  None

==============================================================================*/
static void dbgbrd_ctl_ver( void )
{
	C8 str[ 32 ] ;
	/* Version��񕶎���쐬 */
	tsprintf( str, "Version: %s\r\n", VERSION ) ;
	pccom_send_set( ( U8 * )str, strlen( str ) ) ;

	return ;
}

/*==============================================================================
    �f�o�b�O�{�[�h����@�w���v���o�͏����֐�
  void dbgbrd_ctl_help( void )

 -------------------------------------------------------------------------------
  << Usage >>
  [ IN ]
  arg0:  ��M�R�}���h��̓f�[�^�\���̂ւ̃|�C���^

  [ OUT ]
  None

==============================================================================*/
static void dbgbrd_ctl_help( void )
{
	/* �w���v���o�� */
	pccom_send_set( ( U8 * )HELP_MSG, strlen( HELP_MSG ) ) ;

	return ;
}


