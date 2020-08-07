
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

	// NULL�|�C���^�`�F�b�N
	if( ( buf == NULL )
	 || ( fmt == NULL ) )
	{
		// do nothing
	}
	else
	{
		// fmt������|�C���^��NULL�����łȂ����葱����
		while( *fmt != 0 )
		{
			/* %d�Ƃ���"%"���݂����H */
			if( *fmt == '%' )
			{
				/* fmt���C���N�����Ď��̕�������擾���� */
				fmt++ ;
				/* ������\�������ȊO�̕����H */
				while( ( *fmt >= '0' ) && ( *fmt <= '9' ) )
				{
					/* ���� = 0�H */
					if( *fmt == '0' )
					{
						/* �擪��0��t�^����t���O = TRUE */
						f_fillzero = 1 ;
					}
					else
					{
						/* �������L��, ascii��'0'��0x30�A'9'��0x39�Ȃ̂ŁA0x30�������Ď��ۂ̐����ɂ��� */
						/* ������1����9�܂� */
						nDigit = ( *fmt - 0x30 ) ;
					}
					/* fmt���C���N�����Ď��̕����𒲂ׂ� */
					fmt++ ;
				}
				/* %s�A%c�A%x�A%d�̔��聨�w�肳�ꂽ�t�H�[�}�b�g�̃f�[�^�𕶎���ɕϊ� */
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
					/* �ُ�l�̂Ƃ��͉�͂��I��� */
					len_str = 0 ;
					temp[ 0 ] = 0x00 ;
					break ;
				}
				/* �ϊ������������buf�ɕ��� */
				for( i = 0 ; i < len_str ; i++ )
				{
					*buf = temp[ i ] ;
					buf++ ;
				}
				/* fmt��1�C���N�� */
				fmt++ ;
				/* �[���t�B���t���O������������*/
				f_fillzero = 0 ;
			}
			else
			{
				/* fmt�ɓ����Ă��镶����1�����Abuf�ɕ��� */
				*buf = *fmt ;
				buf++ ;
				fmt++ ;
			}
		}
		/* �Ō��NULL���������� */
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
		/* 2^n�͌v�Z�Ɏ��Ԃ�������̂ŃV�t�g���߂ő�p */
		tmp2 = 1 << ( ( ( unsigned int )i - 1 ) * 4 ) ;
		tmp1 = ( hex / tmp2 ) % 16 ;

		/* �Y�����錅��0�ȊO or 0�Ŗ��߂�t���O�������Ă��� or �Ō��1���H */
		if( ( tmp1 != 0 ) || ( f_zerofill == 1 ) || ( i == 1 ) )
		{
			/* ���l��ASCII�ɕϊ� */
			if( tmp1 < 9 )
			{
				/* 0 - 9�Ȃ琔�l + 0x30(0x30(48d) = '0'�Ȃ̂�) */
				tmp1 = tmp1 + 0x30 ;
			}
			else
			{
				/* ����ȊO�͐��l + 0x37(0x41(65d) = 'A'�Ȃ̂�) */
				tmp1 = tmp1 + 0x37 ;
			}
			/* ������o�b�t�@�ɑ�� */
			*buf = ( char )( tmp1 & 0xff ) ;
			/* �o�b�t�@�C���N�������g */
			buf++ ;
			/* �����񒷃C���N�� */
			len_str++ ;
			/* ��x�ł�������o�b�t�@�ɕ����R�[�h�𖄂߂���A�ȍ~�͌v�Z���ʂ�0�ł��l�𖄂߂Ă��� */
			f_zerofill = 1 ;
		}
		else
		{
			/* �������Ȃ� */
		}
	}
	/* �Ō��NULL������ */
	buf++ ;
	*buf = 0x00 ;

	/* �����񒷂�Ԃ� */
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

		/* �Y�����錅��0�ȊO or 0�Ŗ��߂�t���O�������Ă��� or �Ō��1���H */
		if( ( tmp1 != 0 ) || ( f_zerofill == 1 ) || ( i == 1 ) )
		{
			/* 0 - 9�Ȃ琔�l + 0x30(0x30(48d) = '0'�Ȃ̂�) */
			tmp1 = tmp1 + 0x30 ;
			/* ������o�b�t�@�ɑ�� */
			*buf = ( char )( tmp1 & 0xff ) ;
			/* �o�b�t�@�C���N�� */
			buf++ ;
			/* �������J�E���^�C���N�� */
			n_str++ ;
			/* ��x�ł�������o�b�t�@�ɕ����R�[�h�𖄂߂���A�ȍ~�͌v�Z���ʂ�0�ł��l�𖄂߂Ă��� */
			f_zerofill = 1 ;
		}
		else
		{
			/* �����𖄂߂Ȃ����߁A�������Ȃ� */
		}
	}
	/* �Ō��NULL������ */
	buf++ ;
	*buf = 0x00 ;

	/* �����񒷂�Ԃ� */
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
	/* buf�̐擪��NULL�𕡎�(�擪���畡�ʂ��邽��) */
	*buf = 0x00 ;
	/* buf��str�𕡎� */
	strncpy( buf, str, MAX_BUF ) ;

	return ( strlen( buf ) ) ;
}
