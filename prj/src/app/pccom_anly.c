/*==============================================================================
  PC�ԒʐM�@��M��͏��� [pccom_anly.c]
  
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
  PC�ԒʐM�@�R�}���h��͌��ʎ擾�����֐�
  U8 pccom_anly_get( CMD_RCVD )
  
 -------------------------------------------------------------------------------
  << Usage >>
  [ IN ]
  arg0: �R�}���h��M�l�i�[�p�\���̂ւ̃|�C���^
  
  [ OUT ]
  TRUE: �L���ȃR�}���h��M���� / FALSE: �L���ȃR�}���h��M�Ȃ�
  
==============================================================================*/
U8 pccom_anly_get( CMD_RCVD *cmd_rcvd )
{
	U8 ret = U8_BOOL_FALSE ;
	static C8 comin_str[ MAX_LINEBUF ] ;
	C8 *cmd_token[ NUMOF_CMD_TOKEN ] ;
	U16 i, call_rslt, numof_tok ;

	/* ������NULL�H */
	if( cmd_rcvd == NULL_PTR )
	{
		/* do nothing */
	}
	else
	{
		/* ���C�����͂��擾���� */
		call_rslt = pccom_getline( comin_str ) ;
		/* ���C�����͂���H */
		if( call_rslt != 0 )
		{
			/* �X�y�[�X����؂蕶���ɂ��ăg�[�N���������� */
			cmd_token[ 0 ] = strtok( comin_str, " " ) ;
			numof_tok = 0 ;
			/* ���͉\���I�[�o�[ or �߂�l��NULL�ɂȂ�܂ő����� */
			while( ( numof_tok < NUMOF_CMD_TOKEN ) && ( cmd_token[ numof_tok ] != NULL_PTR ) )
			{
				numof_tok++ ;
				cmd_token[ numof_tok ] = strtok( NULL_PTR, " " ) ;
			} ;

			/* 1�ȏ�̃g�[�N������H */
			if( numof_tok > 0 )
			{
				/* �o�^����Ă���R�}���h������e�[�u���Ɣ�r���s�� */
				for( i = 0 ; i < NUMOF_CMD ; i++ )
				{
					/* 1�ڂ̃g�[�N�����w�肳�ꂽ������ł���΁A�Ή������͏������N������ */
					if( ( !strcmp( cmd_token[ 0 ], CMDSTR_TBL[ i ][ CMDCODE_IDX_UPPER ] ) )
					 || ( !strcmp( cmd_token[ 0 ], CMDSTR_TBL[ i ][ CMDCODE_IDX_LOWER ] ) ) )
					{
						cmd_rcvd->cmd = CMD_CODE_TBL[ i ] ;
						call_rslt     = ( *p_cmdanly_tbl[ i ] )( cmd_token, numof_tok, cmd_rcvd ) ;
						/* ���s���ʂ����̂܂ܖ߂�l�ɑ�� */
						ret = call_rslt ;
						/* ���sOK�Ȃ̂Ń��[�v�𔲂��� */
						break ;
					}
				}
			}
		}
	}
	return ret ;
}

/*==============================================================================
  PC�ԒʐM�@�R�}���h��͕ϐ����������������֐�
  void pccom_anly_initram( void )

 -------------------------------------------------------------------------------
  << Usage >>
  [ IN ]
     �Ȃ�

  [ OUT ]
     �Ȃ�

==============================================================================*/
void pccom_anly_initram( void )
{
	return ;
}
/*=====================================
  local function
=====================================*/

/*==============================================================================
    �|�[�g�֘A�R�}���h�I�v�V������͏����֐�
  void cmdanly_port( C8 *[], U16, CMD_RCVD * )
  
 -------------------------------------------------------------------------------
  << Usage >>
  [ IN ]
  arg0: �g�[�N��������|�C���^�z��
  arg1: �g�[�N����
  arg2: ��M�f�[�^�i�[�p�\���̂ւ̃|�C���^
  [ OUT ]
  TRUE: �L���ȃR�}���h��M���� / FALSE: �L���ȃR�}���h��M�Ȃ�
==============================================================================*/
static U8 cmdanly_port( C8 *cmd_token[], U16 numof_tok, CMD_RCVD *cmd_rcvd )
{
	U16 i, j ;
	/* �S�g�[�N������������ */
	for( i = 0 ; i < numof_tok ; i++ )
	{
		/* PORTA - PORTH�܂ŊY�����镶���񂩌������� */
		for( j = 0 ; j < PORT_E_MAX ; j++ )
		{
			/* �����ꂩ�̂�����������H */
			if( ( !strncmp( cmd_token[ i ], PORT_STR_TBL[ j ][ PORTSTR_IDX_UPPER ], 2 ) )
		     || ( !strncmp( cmd_token[ i ], PORT_STR_TBL[ j ][ PORTSTR_IDX_LOWER ], 2 ) ) )
			{
				/* �w�肳�ꂽ�|�[�g�^�C�v�����������i�[ */
				cmd_rcvd->cmdop.op_port.ptype = PTYPE_TBL[ j ] ;
				/* 3�����ڈȍ~�Ɋi�[����Ă���|�[�g�ԍ����擾 */
				cmd_rcvd->cmdop.op_port.ptno = str2dec( &cmd_token[ i ][ 2 ] ) ;
				/* �K�v�ȏ�񂪌��������̂ł�����TRUE��Ԃ� */
				return U8_BOOL_TRUE ;
			}
		}
	}
	/* �����ɗ����Ƃ��͗L���ȏ�񂪂Ȃ����ł��邽�߁AFALSE��Ԃ� */
	return U8_BOOL_FALSE ;
}

/*==============================================================================
    �R�}���h�I�v�V������͕s�v�������֐�
  U8 cmdanly_nothing( C8 *[], U16, CMD_RCVD * )

 -------------------------------------------------------------------------------
  << Usage >>
  [ IN ]
  arg0: �g�[�N��������|�C���^�z��
  arg1: �g�[�N����
  arg2: ��M�f�[�^�i�[�p�\���̂ւ̃|�C���^
  [ OUT ]
  TRUE: �L���ȃR�}���h��M���� / FALSE: �L���ȃR�}���h��M�Ȃ�
==============================================================================*/
static U8 cmdanly_nothing( C8 *cmd_token[], U16 numof_tok, CMD_RCVD *cmd_rcvd )
{
	/* ���������A���TRUE��Ԃ� */
	return U8_BOOL_TRUE ;
}
