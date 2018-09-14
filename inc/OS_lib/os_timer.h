/*********************************************************************/
/* Filename:    os_timer.h                                                                                 */
/*                                                                                                                  */
/*                                                                                                                  */
/* Description: the description os common timer                                                  */
/*                                                                                                                  */
/*  Author:      wangyunjin                                                                                */
/*   Create:   2014-08-15                                                                                */
/**********************************************************************/

/*********************************************************************/
/* Change History:                                                                                          */
/*     2014-08-15    wangyunjin  Created                                                             */
/*********************************************************************/


#ifndef __OS_TIMER_H_
#define __OS_TIMER_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "os_global.h"

typedef enum
{
    E_OS_TIMER_ONESHOT,
    E_OS_TIMER_LOOP
}OS_TIMER_TYPE_E;

typedef void *(*OS_TIMER_FUNC)(void *);
typedef void * OS_TIMER_HANDLE;


/****************************************************************
*function:      OS_timer_create 
*description:  create the timer object handle
*parameter:
*       tickMs------the timer response interval ms, each tickMs tick all functions
*       maxCnt-----the max count functions to add
*       
*
*return:
*   NULL---failed
*   Other----the handle for other interface
******************************************************************/
DLLEXPORT OS_TIMER_HANDLE OS_timer_create(int32_t tickMs, int32_t maxCnt);


/****************************************************************
*function:      OS_timer_destroy 
*description:  destroy the timer object handle
*parameter:
*       handle------the handle create by OS_timer_create
*       
*
*return:
*   OS_ERROR---failed
*   OS_OK------success
******************************************************************/
DLLEXPORT int32_t OS_timer_destroy(OS_TIMER_HANDLE handle);


/****************************************************************
*function:      OS_timer_add 
*description:  add the new function in the timer
*parameter:
*       handle------the handle create by OS_timer_create
*       p_func------a new func to tick
*       interTicks----each ticks to response the function
*       useData-----the private date for this function
*       
*
*return:
*   <=0---failed
*   > 0------success, the sub id
******************************************************************/
DLLEXPORT int64_t OS_timer_add(OS_TIMER_HANDLE handle, OS_TIMER_FUNC p_func, int32_t interTicks, void *userData);


/****************************************************************
*function:      OS_timer_add_ext 
*description:  add the new function in the timer with TIMER_TYPE
*parameter:
*       handle------the handle create by OS_timer_create
*       p_func------a new func to tick
*       interTicks----each ticks to response the function
*       useData-----the private date for this function
*       type-----the timer type: LOOP OR ONESHOT
*       
*
*return:
*   <=0---failed
*   >------success, the sub id
******************************************************************/
DLLEXPORT int64_t OS_timer_add_ext(OS_TIMER_HANDLE handle, OS_TIMER_FUNC p_func, int32_t interTicks, void *userData, OS_TIMER_TYPE_E type);



/****************************************************************
*function:      OS_timer_remove 
*description:  destroy the timer object handle
*parameter:
*       handle------the handle create by OS_timer_create
*       sub_id------get by OS_timer_add
*       
*
*return:
*   OS_ERROR---failed
*   OS_OK------success
******************************************************************/
DLLEXPORT int32_t OS_timer_remove(OS_TIMER_HANDLE handle, int32_t sub_id);


/****************************************************************
*function:      OS_timer_reset 
*description:  reset the sub_id ticks to 0
*parameter:
*       handle------the handle create by OS_timer_create
*       sub_id------get by OS_timer_add
*       
*
*return:
*   OS_ERROR---failed
*   OS_OK------success
******************************************************************/
DLLEXPORT int32_t OS_timer_reset(OS_TIMER_HANDLE handle, int32_t sub_id);


/****************************************************************
*function:      OS_timer_start 
*description:  start the timer thread
*parameter:
*       handle------the handle create by OS_timer_create
*       
*
*return:
*   OS_ERROR---failed
*   OS_OK------success
******************************************************************/
DLLEXPORT int32_t OS_timer_start(OS_TIMER_HANDLE handle);


/****************************************************************
*function:      OS_timer_stop 
*description:  stop the timer thread
*parameter:
*       handle------the handle create by OS_timer_create
*       
*
*return:
*   OS_ERROR---failed
*   OS_OK------success
******************************************************************/
DLLEXPORT int32_t OS_timer_stop(OS_TIMER_HANDLE handle);


#ifdef __cplusplus
}
#endif

#endif /* __OS_TIMER_H_ */

