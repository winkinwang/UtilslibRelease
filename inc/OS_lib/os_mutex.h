/*********************************************************************/
/* Filename:    os_mutex.h                                                                               	   */
/*                                                                                                                  */
/*                                                                                                                  */
/* Description: the description os pthread mutex module					    */
/*                                                                                                                  */
/*  Author:      wangyunjin                                                                                */
/*   Create:   2014-07-28                                                           		          */
/**********************************************************************/

/*********************************************************************/
/* Change History:                                                                                          */
/*     2014-07-28   wangyunjin  Created                                                             */
/*********************************************************************/


#ifndef _OS_MUTEX_H
#define _OS_MUTEX_H


#ifdef __cplusplus
extern "C" {
#endif

#include "os_global.h"

typedef void *  OS_MUTEX_HANDLE;

DLLEXPORT OS_MUTEX_HANDLE OS_mutexCreate();
DLLEXPORT int OS_mutexDelete(OS_MUTEX_HANDLE nMutexId);
DLLEXPORT int OS_mutexTake(OS_MUTEX_HANDLE nMutexId );
DLLEXPORT int OS_mutexGive(OS_MUTEX_HANDLE nMutexId);

//void OS_mutexEnableErrPrint();
//void OS_mutexDisableErrPrint();


#ifdef __cplusplus
}
#endif

#endif/*_OS_MUTX_H*/

