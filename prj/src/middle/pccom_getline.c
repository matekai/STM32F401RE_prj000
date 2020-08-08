/*==============================================================================
  PC間通信 ライン入力取得処理 [pccom_getline.c]
  
 -------------------------------------------------------------------------------
  << REVISION HISTORY >>
  2020/xx/xx        matekai
  Initial Release
  
==============================================================================*/

#define PCCOM_GETLINE_EXTERN

/*=====================================
  include
=====================================*/
#include <string.h>

#include "common.h"
#include "pccom_rcv.h"
#include "pccom_getline.h"


/*=====================================
  define
=====================================*/
#define LINE_TERMINATOR   "\r\n"

/*=====================================
  typedef
=====================================*/


/*=====================================
  static argument
=====================================*/
static C8 lineBufIn[ MAX_LINEBUF ] ;
static U16 lineBufPos ;

/*=====================================
  function prototype
=====================================*/
static U16 local_getline( C8 *, C8 *, U16 ) ;

/*=====================================
  global function
=====================================*/

/*==============================================================================
  PC間通信　ライン入力取得処理関数
  U16 pccom_getline( C8 * )
  
 -------------------------------------------------------------------------------
  << Usage >>
  [ IN ]
     文字列格納バッファへのポインタ
  
  [ OUT ]
     文字数。ライン入力がない場合は0を返す
  
==============================================================================*/
U16 pccom_getline( C8 *str )
{
	C8 str_local[ PCCOM_MAX_RCVBUF ] ;
	U16 ret, nrcvd ;

	/* 引数がNULL？ */
	if( str == NULL_PTR )
	{
		/* 何もできないので、戻り値 = 0(入力なし) */
		ret = 0U ;
	}
	else
	{
		/* 受信データを取得する */
		nrcvd = pccom_rcv_get( ( U8 * )str_local ) ;
		/* 1byte以上の受信あり？ */
		if( nrcvd > 0 )
		{
			/* ライン入力取得関数を実行 */
			ret = local_getline( str, str_local, nrcvd ) ;
		}
		else
		{
			/* 受信がなければ、戻り値 = 0 */
			ret = 0 ;
		}
	}
	return ret ;
}

/*==============================================================================
  PC間通信　ライン入力取得　変数初期化処理関数
  void pccom_getline_initram( void )

 -------------------------------------------------------------------------------
  << Usage >>
  [ IN ]
     なし

  [ OUT ]
     なし

==============================================================================*/
void pccom_getline_initram( void )
{
	U16 i ;

	lineBufPos = 0 ;
	for( i = 0 ; i < MAX_LINEBUF ; i++ )
	{
		lineBufIn[ i ] = 0 ;
	}
	return ;
}
/*=====================================
  local function
=====================================*/

/*==============================================================================
    ローカルライン入力取得処理関数
  U16 local_getline( C8 *, C8 *, U16 )
  
 -------------------------------------------------------------------------------
  << Usage >>
  [ IN ]
  Arg0:  文字列格納バッファへのポインタ
  Arg1:  受信文字列バッファへのポインタ
  Arg2:  受信した文字数
  
  [ OUT ]
     ライン入力があった場合、その文字列長、ない場合は0
==============================================================================*/
static U16 local_getline( C8 *str_set, C8 *str_rcv, U16 nrcvd )
{
	U16 i = 0, local_lbpos ;
	U8 f_getline_done = U8_BOOL_FALSE ;
	C8 *p_call_rslt = NULL_PTR ;

	/* ローカル変数のラインバッファインデックスに現在のインデックスを代入 */
	local_lbpos = lineBufPos ;
	/* 格納バッファ初期化 */
	*str_set = '\0' ;

	while( ( i < nrcvd) && ( f_getline_done == U8_BOOL_FALSE ) )
	{
		/* ラインバッファが1行分全部埋まっていない？ */
		if( local_lbpos < CHAR_PER_LINE )
		{
			/* 入力文字がBS(0x08)？ */
			if( str_rcv[ i ] == 0x08 )
			{
				/* 前一文字を上書きするために、local_lbposをデクリする(0でなければ) */
				if( local_lbpos > 0 )
				{
					local_lbpos-- ;
				}
			}
			else
			{
				/* 入力文字を1文字、ラインバッファに複写 */
				lineBufIn[ local_lbpos ] = str_rcv[ i ] ;
				/* 末尾にNULL文字を加え、strstrで改行文字があるか調べる */
				lineBufIn[ local_lbpos + 1 ] = '\0' ;
				p_call_rslt = strstr( lineBufIn, LINE_TERMINATOR ) ;

				/* 改行文字あり？ */
				if( p_call_rslt != NULL_PTR )
				{
					/* 改行文字をNUL文字に変える */
					*p_call_rslt = '\0' ;
					/* 文字列を格納バッファに複写する(改行文字の2文字分減らす) */
					strncpy( str_set, lineBufIn, MAX_LINEBUF ) ;
					/* ラインバッファインデックスを巻き戻す */
					local_lbpos = 0 ;
				}
				else
				{
					/* ラインバッファインデックスを1つインクリ */
					local_lbpos++ ;
				}
			}
		}
		/* 80文字受信しても改行がない場合は、そこで文字入力を打ち切る */
		else
		{
			strncpy( str_set, lineBufIn, CHAR_PER_LINE ) ;
			/* NUL文字追加 */
			str_set[ CHAR_PER_LINE ] = '\0' ;
			/* ラインバッファインデックスを巻き戻す */
			local_lbpos = 0 ;
			/* 文字列取得終了 */
			f_getline_done = U8_BOOL_TRUE ;
		}
		/* 入力文字列用配列インデックスをインクリする */
		i++ ;
	}
	/* 静的変数のラインバッファインデックスを更新 */
	lineBufPos = local_lbpos ;
	/* 文字列長を返す(空の文字列で初期化されているので、見つかってなければ0が返る) */
	return ( strlen( str_set ) ) ;
}
