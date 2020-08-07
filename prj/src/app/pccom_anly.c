/*==============================================================================
  PC間通信　受信解析処理 [pccom_anly.c]
  
 -------------------------------------------------------------------------------
  << REVISION HISTORY >>
  2020/xx/xx        matekai
  Initial Release
  
==============================================================================*/

#define PCCOM_ANLY_EXTERN

/*=====================================
  include
=====================================*/
#include <string.h>

#include "common.h"
#include "str2.h"
#include "pccom_getline.h"
#include "pccom_anly.h"


/*=====================================
  define
=====================================*/
#define CMDSTR_PORT_ON_U "PON"
#define CMDSTR_PORT_ON_L "pon"

#define CMDSTR_PORT_OFF_U "POFF"
#define CMDSTR_PORT_OFF_L "poff"

#define CMDSTR_PORT_IN_U "PIN"
#define CMDSTR_PORT_IN_L "pin"

#define CMDSTR_VER_U "VER"
#define CMDSTR_VER_L "ver"

#define CMDSTR_HELP "?"

#define NUMOF_CMD         ( U16 )( 5 )
#define CMDCODE_IDX_UPPER ( U16 )( 0 )
#define CMDCODE_IDX_LOWER ( U16 )( 1 )

#define PORTSTR_IDX_UPPER ( U16 )( 0 )
#define PORTSTR_IDX_LOWER ( U16 )( 1 )

#define NUMOF_CMD_TOKEN   ( U16 )( 8 )


/*=====================================
  typedef
=====================================*/


/*=====================================
  static argument
=====================================*/
static const C8 *CMDSTR_TBL[ NUMOF_CMD ][ 2 ] =
{
		{ CMDSTR_PORT_ON_U, CMDSTR_PORT_ON_L },   /* Port ON */
		{ CMDSTR_PORT_OFF_U, CMDSTR_PORT_OFF_L }, /* Port OFF */
		{ CMDSTR_PORT_IN_U, CMDSTR_PORT_IN_L },   /* Port IN */
		{ CMDSTR_VER_U, CMDSTR_VER_L },           /* Display version */
		{ CMDSTR_HELP, CMDSTR_HELP }              /* Help */
};

static const C8 *PORT_STR_TBL[ PORT_E_MAX ][ 2 ] =
{
		{ "PA", "pa" },  /* PORT_A */
		{ "PB", "pb" },  /* PORT_B */
		{ "PC", "pc" },  /* PORT_C */
		{ "PD", "pd" },  /* PORT_D */
		{ "PE", "pe" },  /* PORT_E */
		{ "PH", "pf" },  /* PORT_H */
};

static const PORT_TYPE PTYPE_TBL[ ] =
{
		PORT_A,
		PORT_B,
		PORT_C,
		PORT_D,
		PORT_E,
		PORT_H,
};

static const CMD_CODE CMD_CODE_TBL[] =
{
		CMD_PON,
		CMD_POFF,
		CMD_PIN,
		CMD_VER,
		CMD_HELP
};
/*=====================================
  function prototype
=====================================*/
static U8 cmdanly_port( C8 *[], U16, CMD_RCVD * ) ;
static U8 cmdanly_nothing( C8 *[], U16, CMD_RCVD * ) ;

static U8 ( *p_cmdanly_tbl[] )( C8 *[], U16, CMD_RCVD * ) =
{
		cmdanly_port,
		cmdanly_port,
		cmdanly_port,
		cmdanly_nothing,
		cmdanly_nothing,
};

/*=====================================
  global function
=====================================*/

/*==============================================================================
  PC間通信　コマンド解析結果取得処理関数
  U8 pccom_anly_get( CMD_RCVD )
  
 -------------------------------------------------------------------------------
  << Usage >>
  [ IN ]
  arg0: コマンド受信値格納用構造体へのポインタ
  
  [ OUT ]
  TRUE: 有効なコマンド受信あり / FALSE: 有効なコマンド受信なし
  
==============================================================================*/
U8 pccom_anly_get( CMD_RCVD *cmd_rcvd )
{
	U8 ret = U8_BOOL_FALSE ;
	static C8 comin_str[ MAX_LINEBUF ] ;
	C8 *cmd_token[ NUMOF_CMD_TOKEN ] ;
	U16 i, call_rslt, numof_tok ;

	/* 引数がNULL？ */
	if( cmd_rcvd == NULL_PTR )
	{
		/* do nothing */
	}
	else
	{
		/* ライン入力を取得する */
		call_rslt = pccom_getline( comin_str ) ;
		/* ライン入力あり？ */
		if( call_rslt != 0 )
		{
			/* スペースを区切り文字にしてトークン分割する */
			cmd_token[ 0 ] = strtok( comin_str, " " ) ;
			numof_tok = 0 ;
			/* 入力可能数オーバー or 戻り値がNULLになるまで続ける */
			while( ( numof_tok < NUMOF_CMD_TOKEN ) && ( cmd_token[ numof_tok ] != NULL_PTR ) )
			{
				numof_tok++ ;
				cmd_token[ numof_tok ] = strtok( NULL_PTR, " " ) ;
			} ;

			/* 1つ以上のトークンあり？ */
			if( numof_tok > 0 )
			{
				/* 登録されているコマンド文字列テーブルと比較を行う */
				for( i = 0 ; i < NUMOF_CMD ; i++ )
				{
					/* 1つ目のトークンが指定された文字列であれば、対応する解析処理を起動する */
					if( ( !strcmp( cmd_token[ 0 ], CMDSTR_TBL[ i ][ CMDCODE_IDX_UPPER ] ) )
					 || ( !strcmp( cmd_token[ 0 ], CMDSTR_TBL[ i ][ CMDCODE_IDX_LOWER ] ) ) )
					{
						cmd_rcvd->cmd = CMD_CODE_TBL[ i ] ;
						call_rslt     = ( *p_cmdanly_tbl[ i ] )( cmd_token, numof_tok, cmd_rcvd ) ;
						/* 実行結果をそのまま戻り値に代入 */
						ret = call_rslt ;
						/* 実行OKなのでループを抜ける */
						break ;
					}
				}
			}
		}
	}
	return ret ;
}

/*==============================================================================
  PC間通信　コマンド解析変数初期化処理処理関数
  void pccom_anly_initram( void )

 -------------------------------------------------------------------------------
  << Usage >>
  [ IN ]
     なし

  [ OUT ]
     なし

==============================================================================*/
void pccom_anly_initram( void )
{
	return ;
}
/*=====================================
  local function
=====================================*/

/*==============================================================================
    ポート関連コマンドオプション解析処理関数
  void cmdanly_port( C8 *[], U16, CMD_RCVD * )
  
 -------------------------------------------------------------------------------
  << Usage >>
  [ IN ]
  arg0: トークン文字列ポインタ配列
  arg1: トークン数
  arg2: 受信データ格納用構造体へのポインタ
  [ OUT ]
  TRUE: 有効なコマンド受信あり / FALSE: 有効なコマンド受信なし
==============================================================================*/
static U8 cmdanly_port( C8 *cmd_token[], U16 numof_tok, CMD_RCVD *cmd_rcvd )
{
	U16 i, j ;
	/* 全トークンを検索する */
	for( i = 0 ; i < numof_tok ; i++ )
	{
		/* PORTA - PORTHまで該当する文字列か検索する */
		for( j = 0 ; j < PORT_E_MAX ; j++ )
		{
			/* いずれかのを示す文字列？ */
			if( ( !strncmp( cmd_token[ i ], PORT_STR_TBL[ j ][ PORTSTR_IDX_UPPER ], 2 ) )
		     || ( !strncmp( cmd_token[ i ], PORT_STR_TBL[ j ][ PORTSTR_IDX_LOWER ], 2 ) ) )
			{
				/* 指定されたポートタイプを示す情報を格納 */
				cmd_rcvd->cmdop.op_port.ptype = PTYPE_TBL[ j ] ;
				/* 3文字目以降に格納されているポート番号を取得 */
				cmd_rcvd->cmdop.op_port.ptno = str2dec( &cmd_token[ i ][ 2 ] ) ;
				/* 必要な情報が見つかったのでここでTRUEを返す */
				return U8_BOOL_TRUE ;
			}
		}
	}
	/* ここに来たときは有効な情報がない時であるため、FALSEを返す */
	return U8_BOOL_FALSE ;
}

/*==============================================================================
    コマンドオプション解析不要時処理関数
  U8 cmdanly_nothing( C8 *[], U16, CMD_RCVD * )

 -------------------------------------------------------------------------------
  << Usage >>
  [ IN ]
  arg0: トークン文字列ポインタ配列
  arg1: トークン数
  arg2: 受信データ格納用構造体へのポインタ
  [ OUT ]
  TRUE: 有効なコマンド受信あり / FALSE: 有効なコマンド受信なし
==============================================================================*/
static U8 cmdanly_nothing( C8 *cmd_token[], U16 numof_tok, CMD_RCVD *cmd_rcvd )
{
	/* 何もせず、常にTRUEを返す */
	return U8_BOOL_TRUE ;
}
