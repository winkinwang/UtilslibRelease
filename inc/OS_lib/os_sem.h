/*********************************************************************/
/* Filename:    os_sem.h                                                                                   */
/*                                                                                                                  */
/*                                                                                                                  */
/* Description: the description os semaphore interface module                       */
/*                                                                                                                  */
/*  Author:      wangyunjin                                                                                */
/*   Create:   2014-08-4                                                                          */
/**********************************************************************/

/*********************************************************************/
/* Change History:                                                                                          */
/*     2014-08-4   wangyunjin  Created                                                             */
/*********************************************************************/
#ifndef _OS_SEM_H
#define _OS_SEM_H

#include "os_global.h"

#ifdef __cplusplus
extern "C" {
#endif

/*it mean the max sem id is 256, note: it just limit in WIN32 */
#define SEM_MAX_INIT_NUM    256

//typedef void * OS_SEM_HANDLE;
typedef struct _SEM_CONTEXT_S *OS_SEM_HANDLE;

DLLEXPORT OS_SEM_HANDLE OS_semCreate(int initCnt);
//nMsTimeout <0---block, 0---nonblock, >0---timeout
DLLEXPORT int OS_semTake(OS_SEM_HANDLE handle, int nMsTimeout);
DLLEXPORT int OS_semGive(OS_SEM_HANDLE handle);
DLLEXPORT int OS_semDestroy(OS_SEM_HANDLE handle);

DLLEXPORT void OS_semEnableLogPrint(OS_BOOL_E bool);

#ifdef __cplusplus
}
#endif

#endif/*_OS_SEM_H*/

