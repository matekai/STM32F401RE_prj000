
#define STRING_EXTERN

#include <stdarg.h>
#include <string.h>
#include "sprintf.h"

#define MAX_BUF ( int )( 80 )

static void l_sprintf( char *, const char *, va_list ) ;
static int l_Hex2Str( char *, const unsigned int, int, int ) ;
static int l_Int2Str( char *, const unsigned int, int, int ) ;
static int l_Char2Str( char *, const char ) ;
static int l_Str2Str( char *, const char * ) ;

/* Public function */

int tsprintf( char *buf, const char *fmt, ... )
{
	va_list args ;
	va_start(args, fmt) ;

	l_sprintf( buf, fmt, args ) ;

	va_end(args) ;
	return 0 ;
}


/* Local function in string.c */
void l_sprintf( char *buf, const char *fmt, va_list args )
{
	int nDigit = 8, len_str, i ;
	int f_fillzero = 0 ;
	char temp[ MAX_BUF ] ;

	// NULLポインタチェック
	if( ( buf == NULL )
	 || ( fmt == NULL ) )
	{
		// do nothing
	}
	else
	{
		// fmt文字列ポインタがNULL文字でない限り続ける
		while( *fmt != 0 )
		{
			/* %dとかの"%"をみつけた？ */
			if( *fmt == '%' )
			{
				/* fmtをインクリして次の文字列を取得する */
				fmt++ ;
				/* 桁数を表す数字以外の文字？ */
				while( ( *fmt >= '0' ) && ( *fmt <= '9' ) )
				{
					/* 数字 = 0？ */
					if( *fmt == '0' )
					{
						/* 先頭に0を付与するフラグ = TRUE */
						f_fillzero = 1 ;
					}
					else
					{
						/* 桁数を記憶, asciiで'0'は0x30、'9'は0x39なので、0x30を引いて実際の数字にする */
						/* 桁数は1から9まで */
						nDigit = ( *fmt - 0x30 ) ;
					}
					/* fmtをインクリして次の文字を調べる */
					fmt++ ;
				}
				/* %s、%c、%x、%dの判定→指定されたフォーマットのデータを文字列に変換 */
				switch( *fmt )
				{
				case 's':
					len_str =  l_Str2Str(temp, va_arg(args, char *) ) ;
					break ;
				case 'c':
					len_str = l_Char2Str( temp, ( char )( va_arg(args, int ) ) ) ;
					break ;
				case 'x':
				case 'X':
					len_str = l_Hex2Str( temp, va_arg(args, unsigned int), nDigit, f_fillzero ) ;
					break ;

				case 'd':
					len_str = l_Int2Str( temp, va_arg(args, int), nDigit, f_fillzero ) ;
					break ;

				default:
					/* 異常値のときは解析を終わる */
					len_str = 0 ;
					temp[ 0 ] = 0x00 ;
					break ;
				}
				/* 変換した文字列をbufに複写 */
				for( i = 0 ; i < len_str ; i++ )
				{
					*buf = temp[ i ] ;
					buf++ ;
				}
				/* fmtを1つインクリ */
				fmt++ ;
				/* ゼロフィルフラグを初期化する*/
				f_fillzero = 0 ;
			}
			else
			{
				/* fmtに入っている文字を1文字、bufに複写 */
				*buf = *fmt ;
				buf++ ;
				fmt++ ;
			}
		}
		/* 最後にNULL文字を入れる */
		*buf = '\0' ;
	}
	return ;
}

static int l_Hex2Str( char *buf, const unsigned int hex, int digit, int f_zerofill )
{
	int i, len_str = 0 ;
	unsigned int tmp1, tmp2 ;

	for( i = digit ; i > 0 ; i-- )
	{
		/* 2^nは計算に時間がかかるのでシフト命令で代用 */
		tmp2 = 1 << ( ( ( unsigned int )i - 1 ) * 4 ) ;
		tmp1 = ( hex / tmp2 ) % 16 ;

		/* 該当する桁が0以外 or 0で埋めるフラグが立っている or 最後の1桁？ */
		if( ( tmp1 != 0 ) || ( f_zerofill == 1 ) || ( i == 1 ) )
		{
			/* 数値をASCIIに変換 */
			if( tmp1 < 9 )
			{
				/* 0 - 9なら数値 + 0x30(0x30(48d) = '0'なので) */
				tmp1 = tmp1 + 0x30 ;
			}
			else
			{
				/* それ以外は数値 + 0x37(0x41(65d) = 'A'なので) */
				tmp1 = tmp1 + 0x37 ;
			}
			/* 文字列バッファに代入 */
			*buf = ( char )( tmp1 & 0xff ) ;
			/* バッファインクリメント */
			buf++ ;
			/* 文字列長インクリ */
			len_str++ ;
			/* 一度でも文字列バッファに文字コードを埋めたら、以降は計算結果が0でも値を埋めていく */
			f_zerofill = 1 ;
		}
		else
		{
			/* 何もしない */
		}
	}
	/* 最後にNULLを入れる */
	buf++ ;
	*buf = 0x00 ;

	/* 文字列長を返す */
	return len_str ;
}

static int l_Int2Str( char *buf, const unsigned int val, int digit, int f_zerofill )
{
	int i, j, n_str = 0 ;
	unsigned int tmp1, tmp2 ;

	for( i = digit ; i > 0 ; i-- )
	{
		tmp2 = 1 ;
		for( j = 0 ; j < i - 1 ; j++ )
		{
			tmp2 = tmp2 * 10 ;
		}
		tmp1 = ( val / tmp2 ) % 10 ;

		/* 該当する桁が0以外 or 0で埋めるフラグが立っている or 最後の1桁？ */
		if( ( tmp1 != 0 ) || ( f_zerofill == 1 ) || ( i == 1 ) )
		{
			/* 0 - 9なら数値 + 0x30(0x30(48d) = '0'なので) */
			tmp1 = tmp1 + 0x30 ;
			/* 文字列バッファに代入 */
			*buf = ( char )( tmp1 & 0xff ) ;
			/* バッファインクリ */
			buf++ ;
			/* 文字数カウンタインクリ */
			n_str++ ;
			/* 一度でも文字列バッファに文字コードを埋めたら、以降は計算結果が0でも値を埋めていく */
			f_zerofill = 1 ;
		}
		else
		{
			/* 文字を埋めないため、何もしない */
		}
	}
	/* 最後にNULLを入れる */
	buf++ ;
	*buf = 0x00 ;

	/* 文字列長を返す */
	return n_str ;
}

static int l_Char2Str( char *buf, const char ch )
{
	*buf = ch ;
	buf++ ;
	buf = 0x00 ;

	return 1 ;
}

static int l_Str2Str( char *buf, const char *str )
{
	/* bufの先頭にNULLを複写(先頭から複写するため) */
	*buf = 0x00 ;
	/* bufへstrを複写 */
	strncpy( buf, str, MAX_BUF ) ;

	return ( strlen( buf ) ) ;
}
