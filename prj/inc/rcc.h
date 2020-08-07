/*==============================================================================
 STM32F4xx Reset/Clockモジュール制御処理用ヘッダ [rcc.h]
  
 -------------------------------------------------------------------------------
  << REVISION HISTORY >>
  2020/xx/xx        matekai
  Initial Release
  
==============================================================================*/

/*======================================
  二重インクルード防止
======================================*/
#ifndef RCC_H
#define RCC_H
#include "common.h"

/*======================================
  実体 or 外部参照切り替え
======================================*/
#ifdef RCC_EXTERN
#define Extern
#else
#define Extern extern
#endif

/*======================================
  define
======================================*/
/* ペリフェラル有効情報(そのままRCC_xxxENRの設定値に流用) */
#define RCC_AHB1_DMA2_EN   ( 1UL << 22U )
#define RCC_AHB1_DMA1_EN   ( 1UL << 21U )
#define RCC_AHB1_CRC_EN    ( 1UL << 12U )
#define RCC_AHB1_GPIOH_EN  ( 1UL << 7U )
#define RCC_AHB1_GPIOE_EN  ( 1UL << 4U )
#define RCC_AHB1_GPIOD_EN  ( 1UL << 3U )
#define RCC_AHB1_GPIOC_EN  ( 1UL << 2U )
#define RCC_AHB1_GPIOB_EN  ( 1UL << 1U )
#define RCC_AHB1_GPIOA_EN  ( 1UL << 0U )

#define RCC_AHB2_OTGFS_EN  ( 1UL << 7U )

#define RCC_APB1_PWR_EN     ( 1UL << 28U )
#define RCC_APB1_I2C3_EN    ( 1UL << 23U )
#define RCC_APB1_I2C2_EN    ( 1UL << 22U )
#define RCC_APB1_I2C1_EN    ( 1UL << 21U )
#define RCC_APB1_USART2_EN  ( 1UL << 17U )
#define RCC_APB1_SPI3_EN    ( 1UL << 15U )
#define RCC_APB1_SPI2_EN    ( 1UL << 14U )
#define RCC_APB1_WWDG_EN    ( 1UL << 11U )
#define RCC_APB1_TIM5_EN    ( 1UL << 3U )
#define RCC_APB1_TIM4_EN    ( 1UL << 2U )
#define RCC_APB1_TIM3_EN    ( 1UL << 1U )
#define RCC_APB1_TIM2_EN    ( 1UL << 0U )

#define RCC_APB2_TIM11_EN  ( 1UL << 18U )
#define RCC_APB2_TIM10_EN  ( 1UL << 17U )
#define RCC_APB2_TIM9_EN   ( 1UL << 16U )
#define RCC_APB2_SYSCFG_EN ( 1UL << 14U )
#define RCC_APB2_SPI4_EN   ( 1UL << 13U )
#define RCC_APB2_SPI1_EN   ( 1UL << 12U )
#define RCC_APB2_SDIO_EN   ( 1UL << 11U )
#define RCC_APB2_ADC1_EN   ( 1UL << 8U )
#define RCC_APB2_USART6_EN ( 1UL << 5U )
#define RCC_APB2_USART1_EN ( 1UL << 4U )
#define RCC_APB2_TIM1_EN   ( 1UL << 0U )

/*======================================
  typedef
======================================*/


/*======================================
  global argument
======================================*/


/*======================================
  function prototype
======================================*/
Extern void stm32_rcc_ahb1_peri_en( U32 ) ;
Extern void stm32_rcc_ahb2_peri_en( U32 ) ;
Extern void stm32_rcc_apb1_peri_en( U32 ) ;
Extern void stm32_rcc_apb2_peri_en( U32 ) ;


#undef Extern
#endif /* ifndef hoge_H */
