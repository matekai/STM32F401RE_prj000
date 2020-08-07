/*==============================================================================
  汎用定義	ヘッダ [common.h]
  
 -------------------------------------------------------------------------------
  << REVISION HISTORY >>
  2020/xx/xx        matekai
  Initial Release
  
==============================================================================*/

/*======================================
  二重インクルード防止
======================================*/
#ifndef COMMON_H
#define COMMON_H


/*======================================
  define
======================================*/
#define DISABLE_INT  __asm("cpsid i")
#define ENABLE_INT   __asm("cpsie i")
#define WAIT_NOP     __asm("nop")

#define CLR_PRIVILEGE  __asm("push {r0}") ;\
	                   __asm("mrs r0, control") ;\
					   __asm("orr r0, r0, #1") ;\
					   __asm("msr control, r0") ;\
					   __asm("pop {r0}")

#define SET_PRIVILEGE  __asm("push {r0}") ;\
	                   __asm("mrs r0, control") ;\
					   __asm("and r0, r0, #0x0FFFFFFFE") ;\
					   __asm("msr control, r0") ;\
					   __asm("pop {r0}")

#define U8_BOOL_TRUE   ( 1 )
#define U8_BOOL_FALSE  ( 0 )

#define U8_LVL_HIGH   ( 1 )
#define U8_LVL_LOW    ( 0 )
#define NULL_PTR      ( void * )( 0UL )

#define VERSION       "01.00"

/*======================================
  typedef
======================================*/
typedef unsigned char U8 ;
typedef unsigned short int U16 ;
typedef unsigned long int  U32 ;

typedef signed char S8 ;
typedef signed short int S16 ;
typedef signed long int  S32 ;

typedef char C8 ;

/*======================================
  global argument
======================================*/


/*======================================
  function prototype
======================================*/



#endif /* ifndef hoge_H */
