/*==============================================================================
  PC�ԒʐM ���C�����͎擾�����p�w�b�_ [pccom_getline.h]
  
 -------------------------------------------------------------------------------
  << REVISION HISTORY >>
  2020/xx/xx        matekai
  Initial Release
  
==============================================================================*/

/*======================================
  ��d�C���N���[�h�h�~
======================================*/
#ifndef PCCOM_GETLINE_H
#define PCCOM_GETLINE_H
#include "common.h"

/*======================================
  ���� or �O���Q�Ɛ؂�ւ�
======================================*/
#ifdef PCCOM_GETLINE_EXTERN
#define Extern
#else
#define Extern extern
#endif

/*======================================
  define
======================================*/
#define MAX_LINEBUF      ( U16 )( 83 )
#define CHAR_PER_LINE    ( U16 )( MAX_LINEBUF - 3 )


/*======================================
  typedef
======================================*/


/*======================================
  global argument
======================================*/


/*======================================
  function prototype
======================================*/
Extern U16 pccom_getline( C8 * ) ;
Extern void pccom_getline_initram( void ) ;


#undef Extern
#endif /* ifndef hoge_H */