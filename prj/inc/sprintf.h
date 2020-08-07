/*
 * sprintf.h
 *
 *  Created on: 2020/07/11
 *      Author: matek
 */

#ifndef SPRINTF_H
#define SPRINTF_H

/* À‘Ì or ŠO•”QÆØ‚è‘Ö‚¦ */
#ifdef STRING_EXTERN
#define Extern
#else
#define Extern extern
#endif

/* Function prototype */
Extern int tsprintf( char *, const char *, ... ) ;

#undef Extern
#endif /* STRING_H_ */
