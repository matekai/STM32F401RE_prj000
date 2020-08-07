/*==============================================================================
  STM32F4xx UART処理 [uart.c]
  
 -------------------------------------------------------------------------------
  << REVISION HISTORY >>
  2020/xx/xx        matekai
  Initial Release
  
 -------------------------------------------------------------------------------
   << Usage >>
   UART1: Debug Communication to PC
   UART2: 未使用
   UART6: 未使用
==============================================================================*/

#define UART_EXTERN

/*=====================================
  include
=====================================*/
#include "common.h"
#include "iodefine.h"
#include "uart.h"


/*=====================================
  define
=====================================*/
/* 16MHz / 115.2kbps = 138.888888, 138.8888 / 8 = 17.361なので、
 * DIV_MANTISSA = 17, DIV_Fraction = 6/16(0.375) = 6とする(OVER8 = 1) */
#define USART1_BRR_INITVAL   ( U32 )(  ( 17UL << 4U ) | ( 6UL ) )

/* OVER8 = 1(8倍のオーバーサンプリング)
 * UE    = 1(USART有効)
 * M     = 0(1word = 8bit)
 * WAKE  = 0(Wakeup = アイドルライン)
 * PCE   = 0(パリティ無効)
 * PS    = 0(パリティ無効なので初期値)
 * PEIE  = 0(パリティエラー割り込み無効)
 * TXEIE = 0(転送バッファエンプティ割り込み無効)
 * TCIE  = 0(転送完了割り込み無効)
 * RXNEIE = 1(受信バッファデータあり割り込み有効)
 * IDLEIE = 0(アイドル割り込み無効)
 * TE     = 1(転送無効)
 * RE     = 1(受信有効)
 * RWU    = 0(レシーバアクティブ)
 * SBK    = 0(ブレークキャラクタ送信なし) */
#define USART1_CR1_INITVAL ( U32 )( 0xA02CUL )

/* LINEN  = 0(LIN無効)
 * STOP   = 00(Stop bit = 1bit)
 * CLKEN  = 0(SCLK無効)
 * CPOL   = 0(SCLK無効なので初期値)
 * CPHA   = 0(SCLK無効なので初期値)
 * LBCL   = 0(SCLK無効なので初期値)
 *　LBDIE  = 0(LIN無効なので初期値)
 *　LBDL   = 0(LIN無効なので初期値)
 *　ADD    = 000(Muteモード未使用なので初期値)　*/
#define USART1_CR2_INITVAL ( U32 )( 0x0UL )

/* ONEBIT = 0(3sample bit)
 * CTSIE  = 0(CTS割り込み無効)
 * CTSE   = 0(CTS無効)
 * RTSE   = 0(RTS無効)
 * DMAT   = 0(送信時DMA転送無効)
 * DMAR   = 0(受信時DMA転送無効)
 * SCEN   = 0(スマートカードモード無効)
 * NACK   = 0(スマートカード無効なので初期値)
 * HDSEL  = 0(全二重モード)
 * IRLP   = 0(IrDA無効なので初期値)
 * IREN   = 0(IrDA無効)
 * EIE    = 0(DMAR無効なので初期値) */
#define USART1_CR3_INITVAL ( U32 )( 0x0UL )

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
  UART1 初期化処理関数
  void stm32_uart1_init( void )
  
 -------------------------------------------------------------------------------
  << Usage >>
  [ IN ]
  None
  
  [ OUT ]
  None
==============================================================================*/
void stm32_uart1_init( void )
{
	USART1_BRR = USART1_BRR_INITVAL ;
	USART1_CR3 = USART1_CR3_INITVAL ;
	USART1_CR2 = USART1_CR2_INITVAL ;

	USART1_SR  = 0UL ;

	USART1_CR1 = USART1_CR1_INITVAL ;

	return ;
}

/*==============================================================================
  UART1 受信データ取得関数
  U8 stm32_uart1_getrcv( void )

 -------------------------------------------------------------------------------
  << Usage >>
  [ IN ]
     受信データ格納先へのポインタ

  [ OUT ]
     受信結果(TRUE = 受信あり / FALSE = 受信なし)
==============================================================================*/
U8 stm32_uart1_getrcv( U8 *data )
{
	U32 rcv_data = 0 ;
	U32 sr_val ;
	U8 ret ;

	/* 引数がNULL？ */
	if( data == NULL_PTR )
	{
		/* 何もできないので、戻り値 = FALSE */
		ret = U8_BOOL_FALSE ;
	}
	else
	{
		/* ステータスレジスタを取得 */
		sr_val = USART1_SR ;

		/* 受信バッファデータあり？ */
		if( ( sr_val & 0x00000020UL ) != 0UL )
		{
			/* 受信バッファからデータを取得する */
			rcv_data = USART1_DR ;
			*data    = ( U8 )( rcv_data & 0x000000FFUL ) ;
			/* 戻り値 = TRUE */
			ret = U8_BOOL_TRUE ;
		}
		else
		{
			/* 受信データは0にしておく */
			*data = 0U ;
			/* 戻り値 = FALSE */
			ret = U8_BOOL_FALSE ;
		}
	}
	return ret ;
}

/*==============================================================================
  UART1 受信ステータス取得関数
  U8 stm32_uart1_getsts( void )

 -------------------------------------------------------------------------------
  << Usage >>
  [ IN ]
  None

  [ OUT ]
     受信ステータス(U8_BOOL_TRUE: 異常なし, U8_BOOL_FALSE: 異常あり)
==============================================================================*/
U8 stm32_uart1_getrcvsts( void )
{
	U32 reg_val ;
	U8  ret = U8_BOOL_TRUE ;

	/* ステータスレジスタを取得 */
	reg_val = USART1_SR ;

	/* 受信あり？ */
	if( ( reg_val & 0x00000020UL ) != 0UL )
	{
		/* 異常フラグあり？ */
		if( ( reg_val & 0x0000000FUL ) != 0UL )
		{
			/* 戻り値 = FALSE */
			ret = U8_BOOL_FALSE ;
			/* エラーフラグを消すため、DRを空読みする */
			reg_val = USART1_DR ;
		}
	}
	return ret ;
}

/*==============================================================================
  UART1 データ送信処理
  U8 stm32_uart1_send( U8 )

 -------------------------------------------------------------------------------
  << Usage >>
  [ IN ]
     送信データ

  [ OUT ]
  U8_BOOL_TRUE: 送信OK, U8_BOOL_FALSE: 送信NG
==============================================================================*/
U8 stm32_uart1_send( U8 data )
{
	U32 reg_val ;
	U8  ret = U8_BOOL_FALSE ;

	/* ステータスレジスタを取得 */
	reg_val = USART1_SR ;

	/* 送信データエンプティ？ */
	if( ( reg_val & 0x00000080UL ) != 0UL )
	{
		/* 送信データレジスタに送信値を設定 */
		reg_val   = ( ( U32 )( data ) & 0x000000FFUL ) ;
		USART1_DR = reg_val ;
		/* 送信できたので、戻り値 = TRUE */
		ret = U8_BOOL_TRUE ;
	}
	return ret ;
}

/*==============================================================================
  UART1 データ送信状態取得処理
  U8 stm32_uart1_getsendsts( void )

 -------------------------------------------------------------------------------
  << Usage >>
  [ IN ]
     送信データ

  [ OUT ]
  U8_BOOL_TRUE: 送信完了, U8_BOOL_FALSE: 送信未完了
==============================================================================*/
U8 stm32_uart1_getsendsts( void )
{
	U32 reg_val ;
	U8  ret = U8_BOOL_FALSE ;

	/* ステータスレジスタを取得 */
	reg_val = USART1_SR ;

	/* 送信完了？ */
	if( ( reg_val & 0x00000040UL ) != 0UL )
	{
		/* 送信完了しているので、戻り値 = TRUE */
		ret = U8_BOOL_TRUE ;
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


