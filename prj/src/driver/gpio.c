/*==============================================================================
  STM32F4xx GPIO処理 [gpio.c]
  
 -------------------------------------------------------------------------------
  << REVISION HISTORY >>
  2020/xx/xx        matekai
  Initial Release
  
==============================================================================*/

#define GPIO_EXTERN

/*=====================================
  include
=====================================*/
#include "common.h"
#include "iodefine.h"
#include "gpio.h"


/*=====================================
  define
=====================================*/

/* ===================================
 * GPIOA init value
 * Embedded PA0-15
 * =================================*/

/* PA10   : Alternate(USART1 Rx)
 * PA09   : Alternate(USART1 Tx)
 * PA05   : Output(Debug LED)
 * Others : Keep default */
#define GPIOA_MODER_INIT   ( U32 )( 0x69695505UL )

/* Others: Push-pull */
#define GPIOA_OTYPER_INIT  ( U32 )( 0x0UL )

/* PA15-13: Keep default for JTAG Debugger
 * Others : No PU/PD */
#define GPIOA_PUPDR_INIT   ( U32 )( 0x64000000UL )

/* Others: AF0 */
#define GPIOA_AFRL_INIT    ( U32 )( 0x0UL )

/* PA10  : AF7( USART1/2 )
 * PA09  : AF7( USART1/2 )
 * Others: AF0 */
#define GPIOA_AFRH_INIT    ( U32 )( 0x00000770UL )

/* Others: Output Lo */
#define GPIOA_ODR_INIT     ( U32 )( 0UL )

/* ===================================
 * GPIOB init value
 * Embedded: PB0-10, PB12-15
 * =================================*/

/* Others: Keep default(No use) */
#define GPIOB_MODER_INIT   ( U32 )( 0x55155595UL )

/* Others: Push-pull */
#define GPIOB_OTYPER_INIT  ( U32 )( 0x0UL )

/* PB03   : Keep default for J-TAG Debugger
 * Others : No PU/PD */
#define GPIOB_PUPDR_INIT   ( U32 )( 0x0UL )

/* Others: AF0 */
#define GPIOB_AFRL_INIT    ( U32 )( 0x0UL )

/* Others: AF0 */
#define GPIOB_AFRH_INIT    ( U32 )( 0x0UL )

/* Others: Output Lo */
#define GPIOB_ODR_INIT     ( U32 )( 0UL )

/* ===================================
 * GPIOC init value
 * Embedded: PC0-15
 * =================================*/

/* Others: Keep default(No use) */
#define GPIOC_MODER_INIT   ( U32 )( 0x55555555UL )

/* Others: Push-pull */
#define GPIOC_OTYPER_INIT  ( U32 )( 0x0UL )

/* Others: No-pullup/down */
#define GPIOC_PUPDR_INIT   ( U32 )( 0x0UL )

/* Others: AF0 */
#define GPIOC_AFRL_INIT    ( U32 )( 0x0UL )

/* Others: AF0 */
#define GPIOC_AFRH_INIT    ( U32 )( 0x0UL )

/* Others: Output Lo */
#define GPIOC_ODR_INIT     ( U32 )( 0UL )

/* ===================================
 * GPIOD init value
 * Embedded: PD2
 * =================================*/

/* Others: Keep default(No use) */
#define GPIOD_MODER_INIT   ( U32 )( 0x00000010UL )

/* Others: Push-pull */
#define GPIOD_OTYPER_INIT  ( U32 )( 0x0UL )

/* Others: No-pullup/down */
#define GPIOD_PUPDR_INIT   ( U32 )( 0x0UL )

/* Others: AF0 */
#define GPIOD_AFRL_INIT    ( U32 )( 0x0UL )

/* Others: AF0 */
#define GPIOD_AFRH_INIT    ( U32 )( 0x0UL )

/* Others: Output Lo */
#define GPIOD_ODR_INIT     ( U32 )( 0UL )

/* ===================================
 * Omit GPIOE&H init value
 * Because of no embedded
 * =================================*/


/*=====================================
  typedef
=====================================*/


/*=====================================
  static argument
=====================================*/


/*=====================================
  function prototype
=====================================*/


/*=====================================
  global function
=====================================*/

/*==============================================================================
  GPIO 初期化処理関数
  void stm32_gpio_init( void )
  
 -------------------------------------------------------------------------------
  << Usage >>
  [ IN ]
  
  
  [ OUT ]
  
==============================================================================*/
void stm32_gpio_init( void )
{
	/* INIT GPIOA */
	GPIOA_MODER  = GPIOA_MODER_INIT ;
	GPIOA_OTYPER = GPIOA_OTYPER_INIT ;
	GPIOA_PUPDR  = GPIOA_PUPDR_INIT ;
	GPIOA_AFRL   = GPIOA_AFRL_INIT ;
	GPIOA_AFRH   = GPIOA_AFRH_INIT ;
	GPIOA_ODR    = GPIOA_ODR_INIT ;

	/* INIT GPIOB */
	GPIOB_MODER  = GPIOB_MODER_INIT ;
	GPIOB_OTYPER = GPIOB_OTYPER_INIT ;
	GPIOB_PUPDR  = GPIOB_PUPDR_INIT ;
	GPIOB_AFRL   = GPIOB_AFRL_INIT ;
	GPIOB_AFRH   = GPIOB_AFRH_INIT ;
	GPIOB_ODR    = GPIOB_ODR_INIT ;

	/* INIT GPIOC */
	GPIOC_MODER  = GPIOC_MODER_INIT ;
	GPIOC_OTYPER = GPIOC_OTYPER_INIT ;
	GPIOC_PUPDR  = GPIOC_PUPDR_INIT ;
	GPIOC_AFRL   = GPIOC_AFRL_INIT ;
	GPIOC_AFRH   = GPIOC_AFRH_INIT ;
	GPIOC_ODR    = GPIOC_ODR_INIT ;

	/* INIT GPIOD */
	GPIOD_MODER  = GPIOD_MODER_INIT ;
	GPIOD_OTYPER = GPIOD_OTYPER_INIT ;
	GPIOD_PUPDR  = GPIOD_PUPDR_INIT ;
	GPIOD_AFRL   = GPIOD_AFRL_INIT ;
	GPIOD_AFRH   = GPIOD_AFRH_INIT ;
	GPIOD_ODR    = GPIOD_ODR_INIT ;

	return ;

}

/*==============================================================================
  GPIO 出力処理関数
  void stm32_gpio_out( PORT_TYPE, U8, U8 )

 -------------------------------------------------------------------------------
  << Usage >>
  [ IN ]
  Arg0: PORT_TYPE列挙子(PORT_A - PORT_H)
  Arg1: ポートインデックス(0-15)
  Arg2: 出力値(U8_LVL_HIGH or U8_LVL_LOW)

  [ OUT ]
     なし

==============================================================================*/
void stm32_gpio_out( PORT_TYPE port_type, U8 port_idx, U8 data )
{
	volatile U32 *gpio_ptr ;
	U32 ptr_dummy ;
	U32 reg_val ;

	/* 入力値チェック */
	if( ( port_type < PORT_E_MAX )
	 && ( port_idx < 16)
	 && ( data <= U8_LVL_HIGH ) )
	{
		/* 値を書き込むSFRをきめる */
		switch( port_type )
		{
		case PORT_A:
			gpio_ptr = &GPIOA_BSRR ;
			break ;
		case PORT_B:
			gpio_ptr = &GPIOB_BSRR ;
			break ;
		case PORT_C:
			gpio_ptr = &GPIOC_BSRR ;
			break ;
		case PORT_D:
			gpio_ptr = &GPIOD_BSRR ;
			break ;
		case PORT_E:
			gpio_ptr = &GPIOE_BSRR ;
			break ;
		case PORT_H:
			gpio_ptr = &GPIOH_BSRR ;
			break ;
		default:
			/* 何もしないためにダミー変数を指しておく */
			gpio_ptr = &ptr_dummy ;
		}
		if( data == U8_LVL_HIGH )
		{
			/* BSxx bitに値を書き込むため、1をport_idx分左シフト */
			reg_val = ( U32 )( 1UL << port_idx ) ;
		}
		else
		{
			/* BRxx bitに値を書き込むため、1を(port_idx + 16)分左シフト */
			reg_val = ( U32 )( 1UL << ( port_idx + 16U ) ) ;
		}
		*gpio_ptr = reg_val ;
	}

	return ;
}

/*==============================================================================
  GPIO 入力処理関数
  U8 stm32_gpio_in( PORT_TYPE, U8 )

 -------------------------------------------------------------------------------
  << Usage >>
  [ IN ]
  Arg0: PORT_TYPE列挙子(PORT_A - PORT_H)
  Arg1: ポートインデックス(0-15)

  [ OUT ]
     入力値

==============================================================================*/
U8 stm32_gpio_in( PORT_TYPE port_type, U8 port_idx )
{
	U32 reg_val ;
	U8 ret = U8_LVL_LOW ;

	/* 入力値チェック */
	if( ( port_type < PORT_E_MAX )
	 && ( port_idx < 16) )
	{
		/* 値を書き込むSFRをきめる */
		switch( port_type )
		{
		case PORT_A:
			reg_val = GPIOA_IDR ;
			break ;
		case PORT_B:
			reg_val = GPIOB_IDR ;
			break ;
		case PORT_C:
			reg_val = GPIOC_IDR ;
			break ;
		case PORT_D:
			reg_val = GPIOD_IDR ;
			break ;
		case PORT_E:
			reg_val = GPIOE_IDR ;
			break ;
		case PORT_H:
			reg_val = GPIOH_IDR ;
			break ;
		default:
			/* 何もしないためレジスタ設定 = 0 */
			reg_val = 0UL ;
		}
		/* 入力値 = 1？ */
		if( ( reg_val & ( 1UL << port_idx ) ) != 0UL )
		{
			/* 戻り値 = HIGH */
			ret = U8_LVL_HIGH ;
		}
		else
		{
			/* 戻り値 = LOW */
			ret = U8_LVL_LOW ;
		}
	}

	return ret ;
}

/*=====================================
  local function
=====================================*/

/*==============================================================================
  xxxxxx処理関数
  void hoge( void )
  
 -------------------------------------------------------------------------------
  << Usage >>
  [ IN ]
  
  
  [ OUT ]
  
==============================================================================*/


