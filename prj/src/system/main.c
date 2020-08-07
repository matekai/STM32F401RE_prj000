/*==============================================================================
  xxxxxx���� [templete.c]
  
 -------------------------------------------------------------------------------
  << REVISION HISTORY >>
  2020/xx/xx        matekai
  Initial Release
  
==============================================================================*/

#define MAIN_EXTERN

/*=====================================
  include
=====================================*/
#include <stdio.h>
#include <string.h>

#include "common.h"
#include "gpio.h"
#include "rcc.h"
#include "nvic.h"
#include "timer.h"
#include "uart.h"

#include "pccom_rcv.h"
#include "pccom_send.h"
#include "pccom_getline.h"

#include "pccom_anly.h"
#include "dbgbrd_ctl.h"

#include "systm.h"
#include "sprintf.h"
#include "main.h"


/*=====================================
  define
=====================================*/
#define WELCOME_STRING \
"\r\n\
Welcome to Nucleo STM32-F401RE Debugboard System!!\r\n\
Soft version: 01.00 by matekai.\r\n\
Press [?] to help.\r\n\r\n"

/*=====================================
  typedef
=====================================*/


/*=====================================
  static argument
=====================================*/


/*=====================================
  function prototype
=====================================*/
static void hwinit( void ) ;
static void modinit( void ) ;

/*=====================================
  global function
=====================================*/

/*==============================================================================
  main�����֐�
  int main( int argc, char **argv )
  
 -------------------------------------------------------------------------------
  << Usage >>
  [ IN ]
  
  
  [ OUT ]
  
==============================================================================*/
int main( int argc, char **argv )
{
	U32 cnt ;
	CMD_RCVD cmd_rcvd ;
	U8 call_rslt ;

	/* �N������͊��荞�݋֎~�̂͂��ł��邪�A�����I�ɋ֎~�ɂ��Ă��� */
	DISABLE_INT ;
	modinit( ) ;
	hwinit( ) ;
	/* �������M������ݒ� */
	pccom_send_set( ( U8 * )WELCOME_STRING, strlen( WELCOME_STRING ) ) ;
	/* ���荞�݋��� */
	ENABLE_INT ;

	for(;;)
	{
		/* 10ms�����Ń��C�����͂��擾���� */
		cnt = systm_getcnt( ) ;
		if( cnt % 10 == 0 )
		{
			call_rslt = pccom_anly_get( &cmd_rcvd ) ;
			if( call_rslt == U8_BOOL_TRUE )
			{
				/* ���C�����͂�����Ƃ��́A�f�o�b�O�{�[�h������N������ */
				dbgbrd_ctl_main( &cmd_rcvd ) ;
			}
		}
	}
}

/*=====================================
  local function
=====================================*/

/*==============================================================================
  �n�[�h�E�F�A�����������֐�
  void hwinit( void )
  
 -------------------------------------------------------------------------------
  << Usage >>
  [ IN ]
    �Ȃ�
  
  [ OUT ]
    �Ȃ�
==============================================================================*/
static void hwinit( void )
{
	U32 peri_en_inf ;
	/* AHB1 init */
	peri_en_inf = ( RCC_AHB1_GPIOH_EN
			    |   RCC_AHB1_GPIOE_EN
				|   RCC_AHB1_GPIOD_EN
				|   RCC_AHB1_GPIOC_EN
				|   RCC_AHB1_GPIOB_EN
				|   RCC_AHB1_GPIOA_EN ) ;
	stm32_rcc_ahb1_peri_en( peri_en_inf ) ;

	/* AHB2 init */
	stm32_rcc_ahb2_peri_en( 0UL ) ;

	/* APB1 init */
	peri_en_inf = RCC_APB1_TIM2_EN ;
	stm32_rcc_apb1_peri_en( peri_en_inf ) ;

	/* APB2 init */
	peri_en_inf = RCC_APB2_USART1_EN ;
	stm32_rcc_apb2_peri_en( peri_en_inf ) ;

	/* GPIO init */
	stm32_gpio_init( ) ;
	/* timer init */
	stm32_tim2_init( ) ;
	/* UART init */
	stm32_uart1_init( ) ;

	/* NVIC init */
	cm4_nvic_init( ) ;
	/* TM2 start */
	stm32_tim2_start( ) ;

	return ;
}

/*==============================================================================
    ���W���[�������������֐�
  void modinit( void )

 -------------------------------------------------------------------------------
  << Usage >>
  [ IN ]
    �Ȃ�

  [ OUT ]
    �Ȃ�
==============================================================================*/
static void modinit( void )
{
	systm_init_ram( ) ;
	pccom_rcv_initram( ) ;
	pccom_send_initram( ) ;
	dbgbrd_ctl_initram( ) ;
	pccom_anly_initram( ) ;

	return ;
}
