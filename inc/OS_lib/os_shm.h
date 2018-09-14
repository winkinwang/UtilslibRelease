/*********************************************************************/
/* Filename:    os_shm.h                                                                                   */
/*                                                                                                                  */
/*                                                                                                                  */
/* Description: the description os share memory module                      */
/*                                                                                                                  */
/*  Author:      wangyunjin                                                                                */
/*   Create:   2014-08-1                                                                          */
/**********************************************************************/

/*********************************************************************/
/* Change History:                                                                                          */
/*     2014-08-1   wangyunjin  Created                                                             */
/*********************************************************************/

#ifndef OS_SHM_H
#define OS_SHM_H

#ifdef WIN32
#include <windows.h>
#else
#include <sys/ipc.h> 
#include <sys/shm.h>
#endif

#include "os_global.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef void *  OS_SHM_HANDLE;

#if 1
typedef enum
{
    EN_OS_SHM_CREATE,        //创建一个共享内存对象，如果存在就直接打开，没有就创建
    EN_OS_SHM_CREATE_ONLY    //创建一个新的共享内存对象，如果存在就失败
}OS_SHM_CREATE_FLAG_E;
DLLEXPORT OS_SHM_HANDLE OS_shmCreate(int key, int size, OS_SHM_CREATE_FLAG_E flag);
DLLEXPORT void *OS_shmGetAddr(OS_SHM_HANDLE handle);
DLLEXPORT void OS_shmDestroy(OS_SHM_HANDLE handle);
#else
HANDLE OS_shmget(int key,int size);
int OS_shmdt(const void *shmaddr);
void OS_shmclose(HANDLE shmid);
void* OS_shmat(HANDLE shmid);

#endif

#ifdef __cplusplus
}
#endif
#endif  /*OS_SHM_H*/


