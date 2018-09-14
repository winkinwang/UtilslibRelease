#ifndef _SYS_TIMER_H_
#define _SYS_TIMER_H_

#include <stdbool.h>

typedef void (*sys_timerproc_t)(char *data_priv);

#ifdef __cplusplus
extern "C" {
#endif



/************************************************************
* Function Name     : sys_timerpool_create
* Input Parameters  : max_timer --- maximum
*                    : tick_interval  --- tick interval (milliseconds)
*                : timer_wheel_size --- used to set the size of timerpool's wheel
*                     
* Output Parameters : none
* Return value      : timerpool_handle
* Description       : create a timerpool
* Modification      : 2013-10-29   created
***************************************************************/
char *sys_timerpool_create(unsigned int max_timer, unsigned int tick_interval, unsigned int timer_wheel_size);

/************************************************************
* Function Name       : sys_timerpool_ticking
* Input Parameters  : timerpool_handle --- the return of function sys_timerpool_create
                                
*                     
* Output Parameters : none
* Return value           : void
* Description             : timer tick ,User's APP must call this func once every tick to drive your timer pool in your task enviroment. 
*                                  It is to say the func 'sys_timerpool_ticking' must be called in the main loop of your task(thread).
* Modification      : 2013-10-29   created
***************************************************************/
void sys_timerpool_ticking(char* timerpool_handle);

/************************************************************
* Function Name       : sys_timerpool_delete
* Input Parameters  : timerpool_handle --- the return of function sys_timerpool_create
*                     
* Output Parameters : none
* Return value           : void
* Description             : delete the timerpool_handle created by function sys_timerpool_create
* Modification      : 2013-10-29   created
***************************************************************/
void sys_timerpool_delete(char *timerpool_handle);

/************************************************************
* Function Name       : sys_timer_alloc
* Input Parameters  : timerpool_handle --- the return of function sys_timerpool_create
*                     
* Output Parameters : none
* Return value           : timer_handle
* Description             : alloc a timer from the timerpool
* Modification      : 2013-10-29   created
***************************************************************/
char *sys_timer_alloc(char *timerpool_handle);

/************************************************************
* Function Name       : sys_timer_start
* Input Parameters  : timer_handle --- the return of function sys_timer_alloc
*                : timeout ---   time alarm, should be larger than 2*tick_interval(sys_timerpool_create)
                 : proc_p --- pointer to callback function
                  : priv_data --- user data for callback function
* Output Parameters : none
* Return value           : 0 -- success , -1 -- failed
* Description             : start a timer with callback-func, the timer will timeout(callback-func will be called) after 'timeout' millisecond
* Modification      : 2013-10-29   created
***************************************************************/
int sys_timer_start(char *timer_handle, unsigned timeout, sys_timerproc_t proc_p, char *priv_data);


/************************************************************
* Function Name       : sys_timer_stop
* Input Parameters  : timer_handle --- the return of function sys_timer_alloc
*               
* Output Parameters : none
* Return value           :0 -- success , -1 -- failed
* Description             : stop a timer
* Modification      : 2013-10-29   created
***************************************************************/
void sys_timer_stop(char *timer_handle);

/************************************************************
* Function Name       : sys_timer_free
* Input Parameters  : timer_handle --- the return of function sys_timer_alloc
*               
* Output Parameters : none
* Return value           :void
* Description             : free a timer, this function will return the timer space to the timerpool
* Modification      : 2013-10-29   created
***************************************************************/
void sys_timer_free(char *timer_handle);

/************************************************************
* Function Name       : sys_timer_show
* Input Parameters  : timerpool_handle --- the return of function sys_timerpool_create
*               
* Output Parameters : none
* Return value           :void
* Description             : show the information of all the timer
* Modification      : 2013-10-29   created
***************************************************************/
void sys_timerpool_show(char *timerpool_handle);

#ifdef __cplusplus
}
#endif

#endif /*_SYS_TIMER_H_*/
