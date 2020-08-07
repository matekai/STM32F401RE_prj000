/*==============================================================================
     文字列変換処理 [str2.c]
  
 -------------------------------------------------------------------------------
  << REVISION HISTORY >>
  2020/xx/xx        matekai
  Initial Release
  
==============================================================================*/

#define STR2_EXTERN

/*=====================================
  include
=====================================*/
#include <string.h>
#include <ctype.h>

#include "common.h"
#include "str2.h"


/*=====================================
  define
=====================================*/
#define ASCII_0     ( U32 )( 0x30 )
#define ASCII_A_U   ( U32 )( 0x41 )
#define ASCII_A_L   ( U32 )( 0x61 )

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
    文字列→10進数変換処理関数
  U32 str2dec( C8 * )
  
 -------------------------------------------------------------------------------
  << Usage >>
  [ IN ]
    変換する文字列。0-9以外の数が入力された場合の動作は不定
  
  [ OUT ]
     変換した値
==============================================================================*/
U32 str2dec( C8 *str )
{
	S16 i, digit ;
	U32 radix = 1, ret = 0 ;

	/* 文字列長を取得して、桁として扱う */
	digit = strlen( str ) ;
	for( i = digit - 1 ; i >=0 ; i-- )
	{
		/* 文字が0-9の間？ */
		if( isdigit( str[i] ) )
		{
			/* 戻り値 = 現在の計算結果 + ( この桁の仮数 * 基数 ) */
			ret = ret + ( ( str[i] - ASCII_0 ) * radix ) ;
		}
		/* 基数を1桁上げる */
		radix = radix * 10 ;
	}

	return ret ;
}

/*==============================================================================
    文字列→16進数変換処理関数
  U32 str2hex( C8 * )

 -------------------------------------------------------------------------------
  << Usage >>
  [ IN ]
    変換する文字列。0-F以外の数が入力された場合の動作は不定

  [ OUT ]
     変換した値
==============================================================================*/
U32 str2hex( C8 *str )
{
	S16 i, digit ;
	U32 radix = 1, ret = 0 ;

	/* 文字列長を取得して、桁として扱う */
	digit = strlen( str ) ;
	for( i = digit - 1 ; i >=0 ; i-- )
	{
		/* 文字が0-9の間？ */
		if( isdigit( str[i] ) )
		{
			/* 戻り値 = 現在の計算結果 + ( この桁の仮数 * 基数 ) */
			ret = ret + ( ( str[i] - ASCII_0 ) * radix ) ;
		}
		/* 文字がA-Fの間？ */
		else if( ( isxdigit( str[i] ) )
		      && ( isupper( str[i]) ) )
		{
			/* 戻り値 = 現在の計算結果 + ( この桁の仮数 * 基数 ) */
			ret = ret + ( ( str[i] - ASCII_A_U + 10 ) * radix ) ;
		}
		/* 文字がa-fの間？ */
		else if( ( isxdigit( str[i] ) )
		      && ( islower( str[i]) ) )
		{
			/* 戻り値 = 現在の計算結果 + ( この桁の仮数 * 基数 ) */
			ret = ret + ( ( str[i] - ASCII_A_L + 10 ) * radix ) ;
		}
		/* それ以外 */
		else
		{
			/* do nothing */
		}
		/* 基数を1桁上げる */
		radix = radix * 16 ;
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


