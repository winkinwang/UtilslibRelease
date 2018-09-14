/*********************************************************************/
/* Filename:    os_cond.h                                                                               	   */
/*                                                                                                                  */
/*                                                                                                                  */
/* Description: the description os pthread condition mutex module					    */
/*                                                                                                                  */
/*  Author:      wangyunjin                                                                                */
/*   Create:   2014-07-30                                                           		          */
/**********************************************************************/

/*********************************************************************/
/* Change History:                                                                                          */
/*     2014-07-30   wangyunjin  Created                                                             */
/*********************************************************************/

#ifndef _OS_CONF_H
#define _OS_CONF_H


#ifdef __cplusplus
extern "C" {
#endif

#include "os_global.h"
//#ifndef	WIN32

typedef void *  OS_COND_HANDLE;

//获取条件锁
DLLEXPORT OS_COND_HANDLE  OS_condCreate();
DLLEXPORT int  OS_condWaitSignal(OS_COND_HANDLE nCondId,int nMsTimeout);
DLLEXPORT int  OS_condSendSignal(OS_COND_HANDLE nCondId);
DLLEXPORT int OS_condDelete(OS_COND_HANDLE nCondId);

//void OS_condEnableErrPrint();
//void OS_condDisableErrPrint();

//#endif	// ifndef	WIN32

#ifdef __cplusplus
}
#endif


#endif	//_OS_CONF_H

