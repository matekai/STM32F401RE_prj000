/*==============================================================================
  PC�ԒʐM ���C�����͎擾���� [pccom_getline.c]
  
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
  PC�ԒʐM�@���C�����͎擾�����֐�
  U16 pccom_getline( C8 * )
  
 -------------------------------------------------------------------------------
  << Usage >>
  [ IN ]
     ������i�[�o�b�t�@�ւ̃|�C���^
  
  [ OUT ]
     �������B���C�����͂��Ȃ��ꍇ��0��Ԃ�
  
==============================================================================*/
U16 pccom_getline( C8 *str )
{
	C8 str_local[ PCCOM_MAX_RCVBUF ] ;
	U16 ret, nrcvd ;

	/* ������NULL�H */
	if( str == NULL_PTR )
	{
		/* �����ł��Ȃ��̂ŁA�߂�l = 0(���͂Ȃ�) */
		ret = 0U ;
	}
	else
	{
		/* ��M�f�[�^���擾���� */
		nrcvd = pccom_rcv_get( ( U8 * )str_local ) ;
		/* 1byte�ȏ�̎�M����H */
		if( nrcvd > 0 )
		{
			/* ���C�����͎擾�֐������s */
			ret = local_getline( str, str_local, nrcvd ) ;
		}
		else
		{
			/* ��M���Ȃ���΁A�߂�l = 0 */
			ret = 0 ;
		}
	}
	return ret ;
}

/*==============================================================================
  PC�ԒʐM�@���C�����͎擾�@�ϐ������������֐�
  void pccom_getline_initram( void )

 -------------------------------------------------------------------------------
  << Usage >>
  [ IN ]
     �Ȃ�

  [ OUT ]
     �Ȃ�

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
    ���[�J�����C�����͎擾�����֐�
  U16 local_getline( C8 *, C8 *, U16 )
  
 -------------------------------------------------------------------------------
  << Usage >>
  [ IN ]
  Arg0:  ������i�[�o�b�t�@�ւ̃|�C���^
  Arg1:  ��M������o�b�t�@�ւ̃|�C���^
  Arg2:  ��M����������
  
  [ OUT ]
     ���C�����͂��������ꍇ�A���̕����񒷁A�Ȃ��ꍇ��0
==============================================================================*/
static U16 local_getline( C8 *str_set, C8 *str_rcv, U16 nrcvd )
{
	U16 i = 0, local_lbpos ;
	U8 f_getline_done = U8_BOOL_FALSE ;
	C8 *p_call_rslt = NULL_PTR ;

	/* ���[�J���ϐ��̃��C���o�b�t�@�C���f�b�N�X�Ɍ��݂̃C���f�b�N�X���� */
	local_lbpos = lineBufPos ;
	/* �i�[�o�b�t�@������ */
	*str_set = '\0' ;

	while( ( i < nrcvd) && ( f_getline_done == U8_BOOL_FALSE ) )
	{
		/* ���C���o�b�t�@��1�s���S�����܂��Ă��Ȃ��H */
		if( local_lbpos < CHAR_PER_LINE )
		{
			/* ���͕�����1�����A���C���o�b�t�@�ɕ��� */
			lineBufIn[ local_lbpos ] = str_rcv[ i ] ;
			/* ������NULL�����������Astrstr�ŉ��s���������邩���ׂ� */
			lineBufIn[ local_lbpos + 1 ] = '\0' ;
			p_call_rslt = strstr( lineBufIn, LINE_TERMINATOR ) ;

			/* ���s��������H */
			if( p_call_rslt != NULL_PTR )
			{
				/* ���s������NUL�����ɕς��� */
				*p_call_rslt = '\0' ;
				/* ��������i�[�o�b�t�@�ɕ��ʂ���(���s������2���������炷) */
				strncpy( str_set, lineBufIn, MAX_LINEBUF ) ;
				/* ���C���o�b�t�@�C���f�b�N�X�������߂� */
				local_lbpos = 0 ;
			}
			else
			{
				/* ���C���o�b�t�@�C���f�b�N�X��1�C���N�� */
				local_lbpos++ ;

			}
		}
		/* 80������M���Ă����s���Ȃ��ꍇ�́A�����ŕ������͂�ł��؂� */
		else
		{
			strncpy( str_set, lineBufIn, CHAR_PER_LINE ) ;
			/* NUL�����ǉ� */
			str_set[ CHAR_PER_LINE ] = '\0' ;
			/* ���C���o�b�t�@�C���f�b�N�X�������߂� */
			local_lbpos = 0 ;
			/* ������擾�I�� */
			f_getline_done = U8_BOOL_TRUE ;
		}
		/* ���͕�����p�z��C���f�b�N�X���C���N������ */
		i++ ;
	}
	/* �ÓI�ϐ��̃��C���o�b�t�@�C���f�b�N�X���X�V */
	lineBufPos = local_lbpos ;
	/* �����񒷂�Ԃ�(��̕�����ŏ���������Ă���̂ŁA�������ĂȂ����0���Ԃ�) */
	return ( strlen( str_set ) ) ;
}
