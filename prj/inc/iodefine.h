/* =================================================
 * IO definition file for STM32F4xx [iodefine.h]
 * By matekai
 * -------------------------------------------------
 * << REVISION HISTORY >>
 * 2020/07/xx Ver. 1.00 by matekai
 * Initial release.
 *
================================================== */

#ifndef IODEFINE_H
#define IODEFINE_H

/* =============================
 * BaseAddress Definition
============================= */
// AHB2
#define OTG_FS_BAR 0x50000000UL

// AHB1
#define AHB1_WINDOW 0x40020000UL

#define DMA2_BAR  ( AHB1_WINDOW + 0x6400UL )
#define DMA1_BAR  ( AHB1_WINDOW + 0x6000UL )
#define RCC_BAR   ( AHB1_WINDOW + 0x3800UL )
#define CRC_BAR   ( AHB1_WINDOW + 0x3000UL )
#define GPIOH_BAR ( AHB1_WINDOW + 0x1C00UL )
#define GPIOE_BAR ( AHB1_WINDOW + 0x1000UL )
#define GPIOD_BAR ( AHB1_WINDOW + 0x0C00UL )
#define GPIOC_BAR ( AHB1_WINDOW + 0x0800UL )
#define GPIOB_BAR ( AHB1_WINDOW + 0x0400UL )
#define GPIOA_BAR ( AHB1_WINDOW + 0x0000UL )

// APB2
#define APB2_WINDOW 0x40010000UL

#define TIM11_BAR   ( APB2_WINDOW + 0x4800UL )
#define TIM10_BAR   ( APB2_WINDOW + 0x4400UL )
#define TIM9_BAR    ( APB2_WINDOW + 0x4000UL )
#define EXTI_BAR    ( APB2_WINDOW + 0x3C00UL )
#define SYSCFG_BAR  ( APB2_WINDOW + 0x3800UL )
#define SPI4_BAR    ( APB2_WINDOW + 0x3400UL )
#define SPI1_BAR    ( APB2_WINDOW + 0x3000UL )
#define SDIO_BAR    ( APB2_WINDOW + 0x2C00UL )
#define ADC1_BAR    ( APB2_WINDOW + 0x2000UL )
#define USART6_BAR  ( APB2_WINDOW + 0x1400UL )
#define USART1_BAR  ( APB2_WINDOW + 0x1000UL )
#define TIM1_BAR    ( APB2_WINDOW + 0x0000UL )

// APB1
#define APB1_WINDOW 0x40000000UL

#define PWR_BAR     ( APB1_WINDOW + 0x7000UL )
#define I2C3_BAR    ( APB1_WINDOW + 0x5C00UL )
#define I2C2_BAR    ( APB1_WINDOW + 0x5800UL )
#define I2C1_BAR    ( APB1_WINDOW + 0x5400UL )
#define USART2_BAR  ( APB1_WINDOW + 0x4400UL )
#define I2S3EXT_BAR ( APB1_WINDOW + 0x4000UL )
#define SPI3_BAR    ( APB1_WINDOW + 0x3C00UL )
#define SPI2_BAR    ( APB1_WINDOW + 0x3800UL )
#define I2S2EXT_BAR ( APB1_WINDOW + 0x3400UL )
#define IWDG_BAR    ( APB1_WINDOW + 0x3000UL )
#define WWDG_BAR    ( APB1_WINDOW + 0x2C00UL )
#define RTC_BAR     ( APB1_WINDOW + 0x2800UL )
#define TIM5_BAR    ( APB1_WINDOW + 0x0C00UL )
#define TIM4_BAR    ( APB1_WINDOW + 0x0800UL )
#define TIM3_BAR    ( APB1_WINDOW + 0x0400UL )
#define TIM2_BAR    ( APB1_WINDOW + 0x0000UL )

// PPB
#define PPB_WINDOW 0xE0000000UL

#define STK_BAR       ( PPB_WINDOW + 0xE010UL )
#define NVIC_BAR      ( PPB_WINDOW + 0xE000UL )
#define SCB_BAR       ( PPB_WINDOW + 0xED00UL )
#define CPR_BAR       ( PPB_WINDOW + 0xED88UL )
#define MPU_BAR       ( PPB_WINDOW + 0xED90UL )
#define NVIC_STIR_BAR ( PPB_WINDOW + 0xEF00UL )
#define FPU_BAR       ( PPB_WINDOW + 0xEF30UL )

/* ==========================
 *  GPIO SFR definition
========================== */

#define GPIOA_MODER   ( *( ( volatile unsigned long int *)( GPIOA_BAR + 0x00UL ) ) )
#define GPIOA_OTYPER  ( *( ( volatile unsigned long int *)( GPIOA_BAR + 0x04UL ) ) )
#define GPIOA_OSPEEDR ( *( ( volatile unsigned long int *)( GPIOA_BAR + 0x08UL ) ) )
#define GPIOA_PUPDR   ( *( ( volatile unsigned long int *)( GPIOA_BAR + 0x0CUL ) ) )
#define GPIOA_IDR     ( *( ( volatile unsigned long int *)( GPIOA_BAR + 0x10UL ) ) )
#define GPIOA_ODR     ( *( ( volatile unsigned long int *)( GPIOA_BAR + 0x14UL ) ) )
#define GPIOA_BSRR    ( *( ( volatile unsigned long int *)( GPIOA_BAR + 0x18UL ) ) )
#define GPIOA_LCKR    ( *( ( volatile unsigned long int *)( GPIOA_BAR + 0x1CUL ) ) )
#define GPIOA_AFRL    ( *( ( volatile unsigned long int *)( GPIOA_BAR + 0x20UL ) ) )
#define GPIOA_AFRH    ( *( ( volatile unsigned long int *)( GPIOA_BAR + 0x24UL ) ) )

#define GPIOB_MODER   ( *( ( volatile unsigned long int *)( GPIOB_BAR + 0x00UL ) ) )
#define GPIOB_OTYPER  ( *( ( volatile unsigned long int *)( GPIOB_BAR + 0x04UL ) ) )
#define GPIOB_OSPEEDR ( *( ( volatile unsigned long int *)( GPIOB_BAR + 0x08UL ) ) )
#define GPIOB_PUPDR   ( *( ( volatile unsigned long int *)( GPIOB_BAR + 0x0CUL ) ) )
#define GPIOB_IDR     ( *( ( volatile unsigned long int *)( GPIOB_BAR + 0x10UL ) ) )
#define GPIOB_ODR     ( *( ( volatile unsigned long int *)( GPIOB_BAR + 0x14UL ) ) )
#define GPIOB_BSRR    ( *( ( volatile unsigned long int *)( GPIOB_BAR + 0x18UL ) ) )
#define GPIOB_LCKR    ( *( ( volatile unsigned long int *)( GPIOB_BAR + 0x1CUL ) ) )
#define GPIOB_AFRL    ( *( ( volatile unsigned long int *)( GPIOB_BAR + 0x20UL ) ) )
#define GPIOB_AFRH    ( *( ( volatile unsigned long int *)( GPIOB_BAR + 0x24UL ) ) )

#define GPIOC_MODER   ( *( ( volatile unsigned long int *)( GPIOC_BAR + 0x00UL ) ) )
#define GPIOC_OTYPER  ( *( ( volatile unsigned long int *)( GPIOC_BAR + 0x04UL ) ) )
#define GPIOC_OSPEEDR ( *( ( volatile unsigned long int *)( GPIOC_BAR + 0x08UL ) ) )
#define GPIOC_PUPDR   ( *( ( volatile unsigned long int *)( GPIOC_BAR + 0x0CUL ) ) )
#define GPIOC_IDR     ( *( ( volatile unsigned long int *)( GPIOC_BAR + 0x10UL ) ) )
#define GPIOC_ODR     ( *( ( volatile unsigned long int *)( GPIOC_BAR + 0x14UL ) ) )
#define GPIOC_BSRR    ( *( ( volatile unsigned long int *)( GPIOC_BAR + 0x18UL ) ) )
#define GPIOC_LCKR    ( *( ( volatile unsigned long int *)( GPIOC_BAR + 0x1CUL ) ) )
#define GPIOC_AFRL    ( *( ( volatile unsigned long int *)( GPIOC_BAR + 0x20UL ) ) )
#define GPIOC_AFRH    ( *( ( volatile unsigned long int *)( GPIOC_BAR + 0x24UL ) ) )

#define GPIOD_MODER   ( *( ( volatile unsigned long int *)( GPIOD_BAR + 0x00UL ) ) )
#define GPIOD_OTYPER  ( *( ( volatile unsigned long int *)( GPIOD_BAR + 0x04UL ) ) )
#define GPIOD_OSPEEDR ( *( ( volatile unsigned long int *)( GPIOD_BAR + 0x08UL ) ) )
#define GPIOD_PUPDR   ( *( ( volatile unsigned long int *)( GPIOD_BAR + 0x0CUL ) ) )
#define GPIOD_IDR     ( *( ( volatile unsigned long int *)( GPIOD_BAR + 0x10UL ) ) )
#define GPIOD_ODR     ( *( ( volatile unsigned long int *)( GPIOD_BAR + 0x14UL ) ) )
#define GPIOD_BSRR    ( *( ( volatile unsigned long int *)( GPIOD_BAR + 0x18UL ) ) )
#define GPIOD_LCKR    ( *( ( volatile unsigned long int *)( GPIOD_BAR + 0x1CUL ) ) )
#define GPIOD_AFRL    ( *( ( volatile unsigned long int *)( GPIOD_BAR + 0x20UL ) ) )
#define GPIOD_AFRH    ( *( ( volatile unsigned long int *)( GPIOD_BAR + 0x24UL ) ) )

#define GPIOE_MODER   ( *( ( volatile unsigned long int *)( GPIOE_BAR + 0x00UL ) ) )
#define GPIOE_OTYPER  ( *( ( volatile unsigned long int *)( GPIOE_BAR + 0x04UL ) ) )
#define GPIOE_OSPEEDR ( *( ( volatile unsigned long int *)( GPIOE_BAR + 0x08UL ) ) )
#define GPIOE_PUPDR   ( *( ( volatile unsigned long int *)( GPIOE_BAR + 0x0CUL ) ) )
#define GPIOE_IDR     ( *( ( volatile unsigned long int *)( GPIOE_BAR + 0x10UL ) ) )
#define GPIOE_ODR     ( *( ( volatile unsigned long int *)( GPIOE_BAR + 0x14UL ) ) )
#define GPIOE_BSRR    ( *( ( volatile unsigned long int *)( GPIOE_BAR + 0x18UL ) ) )
#define GPIOE_LCKR    ( *( ( volatile unsigned long int *)( GPIOE_BAR + 0x1CUL ) ) )
#define GPIOE_AFRL    ( *( ( volatile unsigned long int *)( GPIOE_BAR + 0x20UL ) ) )
#define GPIOE_AFRH    ( *( ( volatile unsigned long int *)( GPIOE_BAR + 0x24UL ) ) )

#define GPIOH_MODER   ( *( ( volatile unsigned long int *)( GPIOH_BAR + 0x00UL ) ) )
#define GPIOH_OTYPER  ( *( ( volatile unsigned long int *)( GPIOH_BAR + 0x04UL ) ) )
#define GPIOH_OSPEEDR ( *( ( volatile unsigned long int *)( GPIOH_BAR + 0x08UL ) ) )
#define GPIOH_PUPDR   ( *( ( volatile unsigned long int *)( GPIOH_BAR + 0x0CUL ) ) )
#define GPIOH_IDR     ( *( ( volatile unsigned long int *)( GPIOH_BAR + 0x10UL ) ) )
#define GPIOH_ODR     ( *( ( volatile unsigned long int *)( GPIOH_BAR + 0x14UL ) ) )
#define GPIOH_BSRR    ( *( ( volatile unsigned long int *)( GPIOH_BAR + 0x18UL ) ) )
#define GPIOH_LCKR    ( *( ( volatile unsigned long int *)( GPIOH_BAR + 0x1CUL ) ) )
#define GPIOH_AFRL    ( *( ( volatile unsigned long int *)( GPIOH_BAR + 0x20UL ) ) )
#define GPIOH_AFRH    ( *( ( volatile unsigned long int *)( GPIOH_BAR + 0x24UL ) ) )

/* ==========================
 *  RCC SFR definition
========================== */
#define RCC_CR         ( *( ( volatile unsigned long int *)( RCC_BAR + 0x00UL ) ) )
#define RCC_PLLCFGR    ( *( ( volatile unsigned long int *)( RCC_BAR + 0x04UL ) ) )
#define RCC_CFGR       ( *( ( volatile unsigned long int *)( RCC_BAR + 0x08UL ) ) )
#define RCC_CIR        ( *( ( volatile unsigned long int *)( RCC_BAR + 0x0CUL ) ) )
#define RCC_AHB1RSTR   ( *( ( volatile unsigned long int *)( RCC_BAR + 0x10UL ) ) )
#define RCC_AHB2RSTR   ( *( ( volatile unsigned long int *)( RCC_BAR + 0x14UL ) ) )
#define RCC_APB1RSTR   ( *( ( volatile unsigned long int *)( RCC_BAR + 0x20UL ) ) )
#define RCC_APB2RSTR   ( *( ( volatile unsigned long int *)( RCC_BAR + 0x24UL ) ) )
#define RCC_AHB1ENR    ( *( ( volatile unsigned long int *)( RCC_BAR + 0x30UL ) ) )
#define RCC_AHB2ENR    ( *( ( volatile unsigned long int *)( RCC_BAR + 0x34UL ) ) )
#define RCC_APB1ENR    ( *( ( volatile unsigned long int *)( RCC_BAR + 0x40UL ) ) )
#define RCC_APB2ENR    ( *( ( volatile unsigned long int *)( RCC_BAR + 0x44UL ) ) )
#define RCC_AHB1LPENR  ( *( ( volatile unsigned long int *)( RCC_BAR + 0x50UL ) ) )
#define RCC_AHB2LPENR  ( *( ( volatile unsigned long int *)( RCC_BAR + 0x54UL ) ) )
#define RCC_APB1LPENR  ( *( ( volatile unsigned long int *)( RCC_BAR + 0x60UL ) ) )
#define RCC_APB2LPENR  ( *( ( volatile unsigned long int *)( RCC_BAR + 0x64UL ) ) )
#define RCC_BDCR       ( *( ( volatile unsigned long int *)( RCC_BAR + 0x70UL ) ) )
#define RCC_CSR        ( *( ( volatile unsigned long int *)( RCC_BAR + 0x74UL ) ) )
#define RCC_SSCGR      ( *( ( volatile unsigned long int *)( RCC_BAR + 0x80UL ) ) )
#define RCC_PLLI2SCFGR ( *( ( volatile unsigned long int *)( RCC_BAR + 0x84UL ) ) )
#define RCC_DCKCFGR    ( *( ( volatile unsigned long int *)( RCC_BAR + 0x8CUL ) ) )

/* ==========================
 *  USART6 SFR definition
========================== */
#define USART6_SR      ( *( ( volatile unsigned long int *)( USART6_BAR + 0x00UL ) ) )
#define USART6_DR      ( *( ( volatile unsigned long int *)( USART6_BAR + 0x04UL ) ) )
#define USART6_BRR     ( *( ( volatile unsigned long int *)( USART6_BAR + 0x08UL ) ) )
#define USART6_CR1     ( *( ( volatile unsigned long int *)( USART6_BAR + 0x0CUL ) ) )
#define USART6_CR2     ( *( ( volatile unsigned long int *)( USART6_BAR + 0x10UL ) ) )
#define USART6_CR3     ( *( ( volatile unsigned long int *)( USART6_BAR + 0x14UL ) ) )
#define USART6_GTPR    ( *( ( volatile unsigned long int *)( USART6_BAR + 0x18UL ) ) )

/* ==========================
 *  USART2 SFR definition
========================== */
#define USART2_SR      ( *( ( volatile unsigned long int *)( USART2_BAR + 0x00UL ) ) )
#define USART2_DR      ( *( ( volatile unsigned long int *)( USART2_BAR + 0x04UL ) ) )
#define USART2_BRR     ( *( ( volatile unsigned long int *)( USART2_BAR + 0x08UL ) ) )
#define USART2_CR1     ( *( ( volatile unsigned long int *)( USART2_BAR + 0x0CUL ) ) )
#define USART2_CR2     ( *( ( volatile unsigned long int *)( USART2_BAR + 0x10UL ) ) )
#define USART2_CR3     ( *( ( volatile unsigned long int *)( USART2_BAR + 0x14UL ) ) )
#define USART2_GTPR    ( *( ( volatile unsigned long int *)( USART2_BAR + 0x18UL ) ) )

/* ==========================
 *  USART1 SFR definition
========================== */
#define USART1_SR      ( *( ( volatile unsigned long int *)( USART1_BAR + 0x00UL ) ) )
#define USART1_DR      ( *( ( volatile unsigned long int *)( USART1_BAR + 0x04UL ) ) )
#define USART1_BRR     ( *( ( volatile unsigned long int *)( USART1_BAR + 0x08UL ) ) )
#define USART1_CR1     ( *( ( volatile unsigned long int *)( USART1_BAR + 0x0CUL ) ) )
#define USART1_CR2     ( *( ( volatile unsigned long int *)( USART1_BAR + 0x10UL ) ) )
#define USART1_CR3     ( *( ( volatile unsigned long int *)( USART1_BAR + 0x14UL ) ) )
#define USART1_GTPR    ( *( ( volatile unsigned long int *)( USART1_BAR + 0x18UL ) ) )

/* ==========================
 *  TIM2 SFR definition
========================== */
#define TIM2_CR1      ( *( ( volatile unsigned long int *)( TIM2_BAR + 0x00UL ) ) )
#define TIM2_CR2      ( *( ( volatile unsigned long int *)( TIM2_BAR + 0x04UL ) ) )
#define TIM2_SMCR     ( *( ( volatile unsigned long int *)( TIM2_BAR + 0x08UL ) ) )
#define TIM2_DIER     ( *( ( volatile unsigned long int *)( TIM2_BAR + 0x0CUL ) ) )
#define TIM2_SR       ( *( ( volatile unsigned long int *)( TIM2_BAR + 0x10UL ) ) )
#define TIM2_EGR      ( *( ( volatile unsigned long int *)( TIM2_BAR + 0x14UL ) ) )
#define TIM2_CCMR1    ( *( ( volatile unsigned long int *)( TIM2_BAR + 0x18UL ) ) )
#define TIM2_CCMR2    ( *( ( volatile unsigned long int *)( TIM2_BAR + 0x1CUL ) ) )
#define TIM2_CCER     ( *( ( volatile unsigned long int *)( TIM2_BAR + 0x20UL ) ) )
#define TIM2_CNT      ( *( ( volatile unsigned long int *)( TIM2_BAR + 0x24UL ) ) )
#define TIM2_PSC      ( *( ( volatile unsigned long int *)( TIM2_BAR + 0x28UL ) ) )
#define TIM2_ARR      ( *( ( volatile unsigned long int *)( TIM2_BAR + 0x2CUL ) ) )
#define TIM2_CCR1     ( *( ( volatile unsigned long int *)( TIM2_BAR + 0x34UL ) ) )
#define TIM2_CCR2     ( *( ( volatile unsigned long int *)( TIM2_BAR + 0x38UL ) ) )
#define TIM2_CCR3     ( *( ( volatile unsigned long int *)( TIM2_BAR + 0x3CUL ) ) )
#define TIM2_CCR4     ( *( ( volatile unsigned long int *)( TIM2_BAR + 0x40UL ) ) )
#define TIM2_DCR      ( *( ( volatile unsigned long int *)( TIM2_BAR + 0x48UL ) ) )
#define TIM2_DMAR     ( *( ( volatile unsigned long int *)( TIM2_BAR + 0x4CUL ) ) )
#define TIM2_OR       ( *( ( volatile unsigned long int *)( TIM2_BAR + 0x50UL ) ) )

/* ==========================
 *  TIM3 SFR definition
========================== */
#define TIM3_CR1      ( *( ( volatile unsigned long int *)( TIM3_BAR + 0x00UL ) ) )
#define TIM3_CR2      ( *( ( volatile unsigned long int *)( TIM3_BAR + 0x04UL ) ) )
#define TIM3_SMCR     ( *( ( volatile unsigned long int *)( TIM3_BAR + 0x08UL ) ) )
#define TIM3_DIER     ( *( ( volatile unsigned long int *)( TIM3_BAR + 0x0CUL ) ) )
#define TIM3_SR       ( *( ( volatile unsigned long int *)( TIM3_BAR + 0x10UL ) ) )
#define TIM3_EGR      ( *( ( volatile unsigned long int *)( TIM3_BAR + 0x14UL ) ) )
#define TIM3_CCMR1    ( *( ( volatile unsigned long int *)( TIM3_BAR + 0x18UL ) ) )
#define TIM3_CCMR2    ( *( ( volatile unsigned long int *)( TIM3_BAR + 0x1CUL ) ) )
#define TIM3_CCER     ( *( ( volatile unsigned long int *)( TIM3_BAR + 0x20UL ) ) )
#define TIM3_CNT      ( *( ( volatile unsigned long int *)( TIM3_BAR + 0x24UL ) ) )
#define TIM3_PSC      ( *( ( volatile unsigned long int *)( TIM3_BAR + 0x28UL ) ) )
#define TIM3_ARR      ( *( ( volatile unsigned long int *)( TIM3_BAR + 0x2CUL ) ) )
#define TIM3_CCR1     ( *( ( volatile unsigned long int *)( TIM3_BAR + 0x34UL ) ) )
#define TIM3_CCR2     ( *( ( volatile unsigned long int *)( TIM3_BAR + 0x38UL ) ) )
#define TIM3_CCR3     ( *( ( volatile unsigned long int *)( TIM3_BAR + 0x3CUL ) ) )
#define TIM3_CCR4     ( *( ( volatile unsigned long int *)( TIM3_BAR + 0x40UL ) ) )
#define TIM3_DCR      ( *( ( volatile unsigned long int *)( TIM3_BAR + 0x48UL ) ) )
#define TIM3_DMAR     ( *( ( volatile unsigned long int *)( TIM3_BAR + 0x4CUL ) ) )
#define TIM3_OR       ( *( ( volatile unsigned long int *)( TIM3_BAR + 0x50UL ) ) )

/* ==========================
 *  TIM4 SFR definition
========================== */
#define TIM4_CR1      ( *( ( volatile unsigned long int *)( TIM4_BAR + 0x00UL ) ) )
#define TIM4_CR2      ( *( ( volatile unsigned long int *)( TIM4_BAR + 0x04UL ) ) )
#define TIM4_SMCR     ( *( ( volatile unsigned long int *)( TIM4_BAR + 0x08UL ) ) )
#define TIM4_DIER     ( *( ( volatile unsigned long int *)( TIM4_BAR + 0x0CUL ) ) )
#define TIM4_SR       ( *( ( volatile unsigned long int *)( TIM4_BAR + 0x10UL ) ) )
#define TIM4_EGR      ( *( ( volatile unsigned long int *)( TIM4_BAR + 0x14UL ) ) )
#define TIM4_CCMR1    ( *( ( volatile unsigned long int *)( TIM4_BAR + 0x18UL ) ) )
#define TIM4_CCMR2    ( *( ( volatile unsigned long int *)( TIM4_BAR + 0x1CUL ) ) )
#define TIM4_CCER     ( *( ( volatile unsigned long int *)( TIM4_BAR + 0x20UL ) ) )
#define TIM4_CNT      ( *( ( volatile unsigned long int *)( TIM4_BAR + 0x24UL ) ) )
#define TIM4_PSC      ( *( ( volatile unsigned long int *)( TIM4_BAR + 0x28UL ) ) )
#define TIM4_ARR      ( *( ( volatile unsigned long int *)( TIM4_BAR + 0x2CUL ) ) )
#define TIM4_CCR1     ( *( ( volatile unsigned long int *)( TIM4_BAR + 0x34UL ) ) )
#define TIM4_CCR2     ( *( ( volatile unsigned long int *)( TIM4_BAR + 0x38UL ) ) )
#define TIM4_CCR3     ( *( ( volatile unsigned long int *)( TIM4_BAR + 0x3CUL ) ) )
#define TIM4_CCR4     ( *( ( volatile unsigned long int *)( TIM4_BAR + 0x40UL ) ) )
#define TIM4_DCR      ( *( ( volatile unsigned long int *)( TIM4_BAR + 0x48UL ) ) )
#define TIM4_DMAR     ( *( ( volatile unsigned long int *)( TIM4_BAR + 0x4CUL ) ) )
#define TIM4_OR       ( *( ( volatile unsigned long int *)( TIM4_BAR + 0x50UL ) ) )

/* ==========================
 *  TIM5 SFR definition
========================== */
#define TIM5_CR1      ( *( ( volatile unsigned long int *)( TIM5_BAR + 0x00UL ) ) )
#define TIM5_CR2      ( *( ( volatile unsigned long int *)( TIM5_BAR + 0x04UL ) ) )
#define TIM5_SMCR     ( *( ( volatile unsigned long int *)( TIM5_BAR + 0x08UL ) ) )
#define TIM5_DIER     ( *( ( volatile unsigned long int *)( TIM5_BAR + 0x0CUL ) ) )
#define TIM5_SR       ( *( ( volatile unsigned long int *)( TIM5_BAR + 0x10UL ) ) )
#define TIM5_EGR      ( *( ( volatile unsigned long int *)( TIM5_BAR + 0x14UL ) ) )
#define TIM5_CCMR1    ( *( ( volatile unsigned long int *)( TIM5_BAR + 0x18UL ) ) )
#define TIM5_CCMR2    ( *( ( volatile unsigned long int *)( TIM5_BAR + 0x1CUL ) ) )
#define TIM5_CCER     ( *( ( volatile unsigned long int *)( TIM5_BAR + 0x20UL ) ) )
#define TIM5_CNT      ( *( ( volatile unsigned long int *)( TIM5_BAR + 0x24UL ) ) )
#define TIM5_PSC      ( *( ( volatile unsigned long int *)( TIM5_BAR + 0x28UL ) ) )
#define TIM5_ARR      ( *( ( volatile unsigned long int *)( TIM5_BAR + 0x2CUL ) ) )
#define TIM5_CCR1     ( *( ( volatile unsigned long int *)( TIM5_BAR + 0x34UL ) ) )
#define TIM5_CCR2     ( *( ( volatile unsigned long int *)( TIM5_BAR + 0x38UL ) ) )
#define TIM5_CCR3     ( *( ( volatile unsigned long int *)( TIM5_BAR + 0x3CUL ) ) )
#define TIM5_CCR4     ( *( ( volatile unsigned long int *)( TIM5_BAR + 0x40UL ) ) )
#define TIM5_DCR      ( *( ( volatile unsigned long int *)( TIM5_BAR + 0x48UL ) ) )
#define TIM5_DMAR     ( *( ( volatile unsigned long int *)( TIM5_BAR + 0x4CUL ) ) )
#define TIM5_OR       ( *( ( volatile unsigned long int *)( TIM5_BAR + 0x50UL ) ) )

/* ==========================
 *  NVIC SFR definition
========================== */
#define NVIC_ISER0    ( *( ( volatile unsigned long int *)( NVIC_BAR + 0x100UL ) ) )
#define NVIC_ISER1    ( *( ( volatile unsigned long int *)( NVIC_BAR + 0x104UL ) ) )
#define NVIC_ISER2    ( *( ( volatile unsigned long int *)( NVIC_BAR + 0x108UL ) ) )
#define NVIC_ISER3    ( *( ( volatile unsigned long int *)( NVIC_BAR + 0x10CUL ) ) )
#define NVIC_ISER4    ( *( ( volatile unsigned long int *)( NVIC_BAR + 0x110UL ) ) )
#define NVIC_ISER5    ( *( ( volatile unsigned long int *)( NVIC_BAR + 0x114UL ) ) )
#define NVIC_ISER6    ( *( ( volatile unsigned long int *)( NVIC_BAR + 0x118UL ) ) )
#define NVIC_ISER7    ( *( ( volatile unsigned long int *)( NVIC_BAR + 0x11CUL ) ) )

#define NVIC_ICER0    ( *( ( volatile unsigned long int *)( NVIC_BAR + 0x180UL ) ) )
#define NVIC_ICER1    ( *( ( volatile unsigned long int *)( NVIC_BAR + 0x184UL ) ) )
#define NVIC_ICER2    ( *( ( volatile unsigned long int *)( NVIC_BAR + 0x188UL ) ) )
#define NVIC_ICER3    ( *( ( volatile unsigned long int *)( NVIC_BAR + 0x18CUL ) ) )
#define NVIC_ICER4    ( *( ( volatile unsigned long int *)( NVIC_BAR + 0x190UL ) ) )
#define NVIC_ICER5    ( *( ( volatile unsigned long int *)( NVIC_BAR + 0x194UL ) ) )
#define NVIC_ICER6    ( *( ( volatile unsigned long int *)( NVIC_BAR + 0x198UL ) ) )
#define NVIC_ICER7    ( *( ( volatile unsigned long int *)( NVIC_BAR + 0x19CUL ) ) )

#define NVIC_ISPR0    ( *( ( volatile unsigned long int *)( NVIC_BAR + 0x200UL ) ) )
#define NVIC_ISPR1    ( *( ( volatile unsigned long int *)( NVIC_BAR + 0x204UL ) ) )
#define NVIC_ISPR2    ( *( ( volatile unsigned long int *)( NVIC_BAR + 0x208UL ) ) )
#define NVIC_ISPR3    ( *( ( volatile unsigned long int *)( NVIC_BAR + 0x20CUL ) ) )
#define NVIC_ISPR4    ( *( ( volatile unsigned long int *)( NVIC_BAR + 0x210UL ) ) )
#define NVIC_ISPR5    ( *( ( volatile unsigned long int *)( NVIC_BAR + 0x214UL ) ) )
#define NVIC_ISPR6    ( *( ( volatile unsigned long int *)( NVIC_BAR + 0x218UL ) ) )
#define NVIC_ISPR7    ( *( ( volatile unsigned long int *)( NVIC_BAR + 0x21CUL ) ) )

#define NVIC_ICPR0    ( *( ( volatile unsigned long int *)( NVIC_BAR + 0x280UL ) ) )
#define NVIC_ICPR1    ( *( ( volatile unsigned long int *)( NVIC_BAR + 0x284UL ) ) )
#define NVIC_ICPR2    ( *( ( volatile unsigned long int *)( NVIC_BAR + 0x288UL ) ) )
#define NVIC_ICPR3    ( *( ( volatile unsigned long int *)( NVIC_BAR + 0x28CUL ) ) )
#define NVIC_ICPR4    ( *( ( volatile unsigned long int *)( NVIC_BAR + 0x290UL ) ) )
#define NVIC_ICPR5    ( *( ( volatile unsigned long int *)( NVIC_BAR + 0x294UL ) ) )
#define NVIC_ICPR6    ( *( ( volatile unsigned long int *)( NVIC_BAR + 0x298UL ) ) )
#define NVIC_ICPR7    ( *( ( volatile unsigned long int *)( NVIC_BAR + 0x29CUL ) ) )

#define NVIC_IABR0    ( *( ( volatile unsigned long int *)( NVIC_BAR + 0x300UL ) ) )
#define NVIC_IABR1    ( *( ( volatile unsigned long int *)( NVIC_BAR + 0x304UL ) ) )
#define NVIC_IABR2    ( *( ( volatile unsigned long int *)( NVIC_BAR + 0x308UL ) ) )
#define NVIC_IABR3    ( *( ( volatile unsigned long int *)( NVIC_BAR + 0x30CUL ) ) )
#define NVIC_IABR4    ( *( ( volatile unsigned long int *)( NVIC_BAR + 0x310UL ) ) )
#define NVIC_IABR5    ( *( ( volatile unsigned long int *)( NVIC_BAR + 0x314UL ) ) )
#define NVIC_IABR6    ( *( ( volatile unsigned long int *)( NVIC_BAR + 0x318UL ) ) )
#define NVIC_IABR7    ( *( ( volatile unsigned long int *)( NVIC_BAR + 0x31CUL ) ) )

#define NVIC_IPR0     ( *( ( volatile unsigned long int *)( NVIC_BAR + 0x400UL ) ) )
#define NVIC_IPR1     ( *( ( volatile unsigned long int *)( NVIC_BAR + 0x404UL ) ) )
#define NVIC_IPR2     ( *( ( volatile unsigned long int *)( NVIC_BAR + 0x408UL ) ) )
#define NVIC_IPR3     ( *( ( volatile unsigned long int *)( NVIC_BAR + 0x40CUL ) ) )
#define NVIC_IPR4     ( *( ( volatile unsigned long int *)( NVIC_BAR + 0x410UL ) ) )
#define NVIC_IPR5     ( *( ( volatile unsigned long int *)( NVIC_BAR + 0x414UL ) ) )
#define NVIC_IPR6     ( *( ( volatile unsigned long int *)( NVIC_BAR + 0x418UL ) ) )
#define NVIC_IPR7     ( *( ( volatile unsigned long int *)( NVIC_BAR + 0x41CUL ) ) )
#define NVIC_IPR8     ( *( ( volatile unsigned long int *)( NVIC_BAR + 0x420UL ) ) )
#define NVIC_IPR9     ( *( ( volatile unsigned long int *)( NVIC_BAR + 0x424UL ) ) )
#define NVIC_IPR10    ( *( ( volatile unsigned long int *)( NVIC_BAR + 0x428UL ) ) )
#define NVIC_IPR11    ( *( ( volatile unsigned long int *)( NVIC_BAR + 0x42CUL ) ) )
#define NVIC_IPR12    ( *( ( volatile unsigned long int *)( NVIC_BAR + 0x430UL ) ) )
#define NVIC_IPR13    ( *( ( volatile unsigned long int *)( NVIC_BAR + 0x434UL ) ) )
#define NVIC_IPR14    ( *( ( volatile unsigned long int *)( NVIC_BAR + 0x438UL ) ) )
#define NVIC_IPR15    ( *( ( volatile unsigned long int *)( NVIC_BAR + 0x43CUL ) ) )
#define NVIC_IPR16    ( *( ( volatile unsigned long int *)( NVIC_BAR + 0x440UL ) ) )
#define NVIC_IPR17    ( *( ( volatile unsigned long int *)( NVIC_BAR + 0x444UL ) ) )
#define NVIC_IPR18    ( *( ( volatile unsigned long int *)( NVIC_BAR + 0x448UL ) ) )
#define NVIC_IPR19    ( *( ( volatile unsigned long int *)( NVIC_BAR + 0x44CUL ) ) )
#define NVIC_IPR20    ( *( ( volatile unsigned long int *)( NVIC_BAR + 0x450UL ) ) )
#define NVIC_IPR21    ( *( ( volatile unsigned long int *)( NVIC_BAR + 0x454UL ) ) )
#define NVIC_IPR22    ( *( ( volatile unsigned long int *)( NVIC_BAR + 0x458UL ) ) )
#define NVIC_IPR23    ( *( ( volatile unsigned long int *)( NVIC_BAR + 0x45CUL ) ) )
#define NVIC_IPR24    ( *( ( volatile unsigned long int *)( NVIC_BAR + 0x460UL ) ) )
#define NVIC_IPR25    ( *( ( volatile unsigned long int *)( NVIC_BAR + 0x464UL ) ) )
#define NVIC_IPR26    ( *( ( volatile unsigned long int *)( NVIC_BAR + 0x468UL ) ) )
#define NVIC_IPR27    ( *( ( volatile unsigned long int *)( NVIC_BAR + 0x46CUL ) ) )
#define NVIC_IPR28    ( *( ( volatile unsigned long int *)( NVIC_BAR + 0x470UL ) ) )
#define NVIC_IPR29    ( *( ( volatile unsigned long int *)( NVIC_BAR + 0x474UL ) ) )
#define NVIC_IPR30    ( *( ( volatile unsigned long int *)( NVIC_BAR + 0x478UL ) ) )
#define NVIC_IPR31    ( *( ( volatile unsigned long int *)( NVIC_BAR + 0x47CUL ) ) )
#define NVIC_IPR32    ( *( ( volatile unsigned long int *)( NVIC_BAR + 0x480UL ) ) )
#define NVIC_IPR33    ( *( ( volatile unsigned long int *)( NVIC_BAR + 0x484UL ) ) )
#define NVIC_IPR34    ( *( ( volatile unsigned long int *)( NVIC_BAR + 0x488UL ) ) )
#define NVIC_IPR35    ( *( ( volatile unsigned long int *)( NVIC_BAR + 0x48CUL ) ) )
#define NVIC_IPR36    ( *( ( volatile unsigned long int *)( NVIC_BAR + 0x490UL ) ) )
#define NVIC_IPR37    ( *( ( volatile unsigned long int *)( NVIC_BAR + 0x494UL ) ) )
#define NVIC_IPR38    ( *( ( volatile unsigned long int *)( NVIC_BAR + 0x498UL ) ) )
#define NVIC_IPR39    ( *( ( volatile unsigned long int *)( NVIC_BAR + 0x49CUL ) ) )
#define NVIC_IPR40    ( *( ( volatile unsigned long int *)( NVIC_BAR + 0x4A0UL ) ) )
#define NVIC_IPR41    ( *( ( volatile unsigned long int *)( NVIC_BAR + 0x4A4UL ) ) )
#define NVIC_IPR42    ( *( ( volatile unsigned long int *)( NVIC_BAR + 0x4A8UL ) ) )
#define NVIC_IPR43    ( *( ( volatile unsigned long int *)( NVIC_BAR + 0x4ACUL ) ) )
#define NVIC_IPR44    ( *( ( volatile unsigned long int *)( NVIC_BAR + 0x4B0UL ) ) )
#define NVIC_IPR45    ( *( ( volatile unsigned long int *)( NVIC_BAR + 0x4B4UL ) ) )
#define NVIC_IPR46    ( *( ( volatile unsigned long int *)( NVIC_BAR + 0x4B8UL ) ) )
#define NVIC_IPR47    ( *( ( volatile unsigned long int *)( NVIC_BAR + 0x4BCUL ) ) )
#define NVIC_IPR48    ( *( ( volatile unsigned long int *)( NVIC_BAR + 0x4C0UL ) ) )
#define NVIC_IPR49    ( *( ( volatile unsigned long int *)( NVIC_BAR + 0x4C4UL ) ) )
#define NVIC_IPR50    ( *( ( volatile unsigned long int *)( NVIC_BAR + 0x4C8UL ) ) )
#define NVIC_IPR51    ( *( ( volatile unsigned long int *)( NVIC_BAR + 0x4CCUL ) ) )
#define NVIC_IPR52    ( *( ( volatile unsigned long int *)( NVIC_BAR + 0x4D0UL ) ) )
#define NVIC_IPR53    ( *( ( volatile unsigned long int *)( NVIC_BAR + 0x4D4UL ) ) )
#define NVIC_IPR54    ( *( ( volatile unsigned long int *)( NVIC_BAR + 0x4D8UL ) ) )
#define NVIC_IPR55    ( *( ( volatile unsigned long int *)( NVIC_BAR + 0x4DCUL ) ) )
#define NVIC_IPR56    ( *( ( volatile unsigned long int *)( NVIC_BAR + 0x4E0UL ) ) )
#define NVIC_IPR57    ( *( ( volatile unsigned long int *)( NVIC_BAR + 0x4E4UL ) ) )
#define NVIC_IPR58    ( *( ( volatile unsigned long int *)( NVIC_BAR + 0x4E8UL ) ) )
#define NVIC_IPR59    ( *( ( volatile unsigned long int *)( NVIC_BAR + 0x4ECUL ) ) )

#define NVIC_STIR     ( *( ( volatile unsigned long int *)( NVIC_BAR + 0xF00UL ) ) )

#endif /* ifndef hoge_H */
