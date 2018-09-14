/*********************************************************************/
/* Filename:    os_thread.h                                                                           	   */
/*                                                                                                                  */
/*                                                                                                                  */
/* Description: the description os common thread create				    */
/*                                                                                                                  */
/*  Author:      wangyunjin                                                                                */
/*   Create:   2014-07-28                                                          		          */
/**********************************************************************/

/*********************************************************************/
/* Change History:                                                                                          */
/*     2014-07-28   wangyunjin  Created                                                             */
/*********************************************************************/


#ifndef __OS_THREAD_H_
#define __OS_THREAD_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "os_global.h"

typedef void *(*OS_THREAD_FUNC)(void *);

/*

for linux:
    return -1:failed, else success
*/
DLLEXPORT int32_t OS_thread_create(OS_THREAD_FUNC p_func, void *arg);
DLLEXPORT int32_t OS_thread_create_full(OS_THREAD_FUNC p_func, void *arg, unsigned int stackSize, char priority, char *name);


DLLEXPORT void OS_thread_close(int32_t handle);

DLLEXPORT void OS_sleep(uint32_t sec);
DLLEXPORT void OS_msleep(uint32_t msec);
DLLEXPORT void OS_usleep(uint32_t usec);

typedef void* OS_LOOP_HANDLE;
typedef void *(*OS_THREAD_LOOP_FUNC)(OS_LOOP_HANDLE handle, const char *evtName, void *privData);
DLLEXPORT int32_t OS_thread_loop_init(OS_LOOP_HANDLE *pHandle);
DLLEXPORT int32_t OS_thread_loop_start(OS_LOOP_HANDLE handle);
DLLEXPORT int32_t OS_thread_loop_register_event(OS_LOOP_HANDLE handle, const char *evtName, OS_THREAD_LOOP_FUNC p_func);
DLLEXPORT int32_t OS_thread_loop_unregister_event(OS_LOOP_HANDLE handle, const char *evtName);
DLLEXPORT int32_t OS_thread_loop_send_event(OS_LOOP_HANDLE handle, const char *evtName, void *evtData);
DLLEXPORT int32_t OS_thread_loop_uninit(OS_LOOP_HANDLE *pHandle);
DLLEXPORT int32_t OS_thread_loop_check_exist(OS_LOOP_HANDLE handle, const char *evtName);
DLLEXPORT int32_t OS_thread_loop_get_evt_num(OS_LOOP_HANDLE handle);

#ifdef __cplusplus
}
#endif

#endif /* __OS_THREAD_H_ */

