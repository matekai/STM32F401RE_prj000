/*==============================================================================
  STM32F4xx GPIO処理用ヘッダ [gpio.h]
  
 -------------------------------------------------------------------------------
  << REVISION HISTORY >>
  2020/xx/xx        matekai
  Initial Release
  
==============================================================================*/

/*======================================
  二重インクルード防止
======================================*/
#ifndef GPIO_H
#define GPIO_H
#include "common.h"

/*======================================
  実体 or 外部参照切り替え
======================================*/
#ifdef GPIO_EXTERN
#define Extern
#else
#define Extern extern
#endif

/*======================================
  define
======================================*/
#define GPIO_FREE      ( U8 )( 0x0 )
#define GPIO_SYS_RSVD  ( U8 )( 0x1 )
#define GPIO_NOT_EXIST ( U8 )( 0xFF )

/*======================================
  typedef
======================================*/
typedef enum ePortType
{
	PORT_A,
	PORT_B,
	PORT_C,
	PORT_D,
	PORT_E,
	PORT_H,
	PORT_E_MAX

} PORT_TYPE ;

#ifdef GPIO_EXTERN
const U8 GPIO_USAGE_TABLE[ PORT_E_MAX ][ 16 ] =
{
		/* PA */
		{ GPIO_FREE, GPIO_FREE,     GPIO_SYS_RSVD, GPIO_SYS_RSVD,  /* 0-3 */
		  GPIO_FREE, GPIO_SYS_RSVD, GPIO_FREE,     GPIO_FREE,      /* 4-7 */
		  GPIO_FREE, GPIO_SYS_RSVD, GPIO_SYS_RSVD, GPIO_FREE,      /* 8-11 */
		  GPIO_FREE, GPIO_SYS_RSVD, GPIO_SYS_RSVD, GPIO_FREE       /* 12-15 */
		},
		/* PB */
		{ GPIO_FREE, GPIO_FREE, GPIO_FREE, GPIO_SYS_RSVD,  /* 0-3 */
		  GPIO_FREE, GPIO_FREE, GPIO_FREE, GPIO_FREE,      /* 4-7 */
		  GPIO_FREE, GPIO_FREE, GPIO_FREE, GPIO_SYS_RSVD,  /* 8-11 */
		  GPIO_FREE, GPIO_FREE, GPIO_FREE, GPIO_FREE       /* 12-15 */
		},
		/* PC */
		{ GPIO_FREE, GPIO_FREE, GPIO_FREE, GPIO_FREE,  /* 0-3 */
		  GPIO_FREE, GPIO_FREE, GPIO_FREE, GPIO_FREE,  /* 4-7 */
		  GPIO_FREE, GPIO_FREE, GPIO_FREE, GPIO_FREE,  /* 8-11 */
		  GPIO_FREE, GPIO_FREE, GPIO_FREE, GPIO_FREE   /* 12-15 */
		},
		/* PD */
		{ GPIO_NOT_EXIST, GPIO_NOT_EXIST, GPIO_FREE, GPIO_NOT_EXIST,        /* 0-3 */
		  GPIO_NOT_EXIST, GPIO_NOT_EXIST, GPIO_NOT_EXIST, GPIO_NOT_EXIST,   /* 4-7 */
		  GPIO_NOT_EXIST, GPIO_NOT_EXIST, GPIO_NOT_EXIST, GPIO_NOT_EXIST,   /* 8-11 */
		  GPIO_NOT_EXIST, GPIO_NOT_EXIST, GPIO_NOT_EXIST, GPIO_NOT_EXIST,   /* 12-15 */
		},
		/* PE */
		{ GPIO_NOT_EXIST, GPIO_NOT_EXIST, GPIO_NOT_EXIST, GPIO_NOT_EXIST,   /* 0-3 */
		  GPIO_NOT_EXIST, GPIO_NOT_EXIST, GPIO_NOT_EXIST, GPIO_NOT_EXIST,   /* 4-7 */
		  GPIO_NOT_EXIST, GPIO_NOT_EXIST, GPIO_NOT_EXIST, GPIO_NOT_EXIST,   /* 8-11 */
		  GPIO_NOT_EXIST, GPIO_NOT_EXIST, GPIO_NOT_EXIST, GPIO_NOT_EXIST,   /* 12-15 */
		},
		/* PH */
		{ GPIO_SYS_RSVD,  GPIO_SYS_RSVD,  GPIO_NOT_EXIST, GPIO_NOT_EXIST,   /* 0-3 */
		  GPIO_NOT_EXIST, GPIO_NOT_EXIST, GPIO_NOT_EXIST, GPIO_NOT_EXIST,   /* 4-7 */
		  GPIO_NOT_EXIST, GPIO_NOT_EXIST, GPIO_NOT_EXIST, GPIO_NOT_EXIST,   /* 8-11 */
		  GPIO_NOT_EXIST, GPIO_NOT_EXIST, GPIO_NOT_EXIST, GPIO_NOT_EXIST,   /* 12-15 */
		}
};
#else
	extern const U8 GPIO_USAGE_TABLE[ PORT_E_MAX ][ 16 ] ;
#endif

/*======================================
  global argument
======================================*/


/*======================================
  function prototype
======================================*/
Extern void stm32_gpio_init( void ) ;
Extern void stm32_gpio_out( PORT_TYPE, U8, U8 ) ;
Extern U8 stm32_gpio_in( PORT_TYPE, U8 ) ;

#undef Extern
#endif /* ifndef hoge_H */
