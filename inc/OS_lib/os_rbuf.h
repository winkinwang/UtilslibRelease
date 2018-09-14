/*********************************************************************/
/* Filename:    os_rbuf.h                                                                                      */
/*                                                                                                                  */
/*                                                                                                                  */
/* Description: the description os ring buffer interface module                     */
/*                                                                                                                  */
/*  Author:      wangyunjin                                                                                */
/*   Create:   2014-08-4                                                                          */
/**********************************************************************/

/*********************************************************************/
/* Change History:                                                                                          */
/*     2014-08-4   wangyunjin  Created                                                             */
/*********************************************************************/
#ifndef _OS_RBUF_H
#define _OS_RBUF_H


#define RBUFF_MIN_SIZE (64 * 1024)

#ifdef __cplusplus
extern "C" {
#endif

typedef enum
{
    OS_RBUF_PRO_R,  //read priority, when the buffer not enough to write, stop
    OS_RBUF_PRO_W   //write priority, when no enough buffer , overwrite the old data
}OS_RBUF_PRO_E;

typedef void * OS_RBUF_HANDLE;

/****************************************************************
*function:      OS_rbufCreate 
*description:  create the ring buffer object handle
*parameter:
*       buffSize------the handle create by OS_rbufCreate
*       
*
*return:
*   NULL---failed
*   Other----the handle used before
******************************************************************/
OS_RBUF_HANDLE OS_rbufCreate(int buffSize);

/****************************************************************
*function:       OS_rbufDestroy
*description:   destroy the object created by OS_rbufCreate
*parameter:
*       handle------the handle create by OS_rbufCreate
*       
*
*return:
*   
*   
******************************************************************/
void OS_rbufDestroy(OS_RBUF_HANDLE handle);


/****************************************************************
*function:       
*description:
*parameter:
*       handle------the handle create by OS_rbufCreate
*       pOutBuff----
*
*return:
*   <=0---failed
*   >0----realy get buff length
******************************************************************/

int OS_rbufClear(OS_RBUF_HANDLE handle);
//int OS_rbufReqSegment(OS_RBUF_HANDLE handle, int32_t size, int32_t *segId);

/****************************************************************
*function:       
*description:
*parameter:
*       handle------the handle create by OS_rbufCreate
*       pInBuff-----the buffer content to set
*       inSize-------the in buffer length
*
*return:
*   <=0---failed
*   >0----the real buff length set
******************************************************************/
int OS_rbufSetBuff(OS_RBUF_HANDLE handle, uint8_t *pInBuff, int32_t inSize);


/****************************************************************
*function:       OS_rbufGetBuff
*description:  get buffer content from the ring buffer
*parameter:
*       handle------the handle create by OS_rbufCreate
*       pOutBuff----the buffer to fill the got content
*       maxBuffLen--the max buffer space
*
*return:
*   <=0---failed
*   >0----the real buff length got
******************************************************************/
int OS_rbufGetBuff(OS_RBUF_HANDLE handle, uint8_t *pOutBuff, int32_t maxBuffLen);


/****************************************************************
*function:       OS_rbufGetFreeLength
*description:   get the buffer space left
*parameter:
*       handle------the handle create by OS_rbufCreate
*       outFreeLen---the return free space length
*
*return:
*   OS_ERROR---failed
*   OS_OK ------success
******************************************************************/
int OS_rbufGetFreeLength(OS_RBUF_HANDLE handle, int32_t *outFreeLen);

/****************************************************************
*function:       OS_rbufsetPriority
*description:   set the buffer write priority
*parameter:
*       handle------the handle create by OS_rbufCreate
*       priority------the priority
*
*return:
*   OS_ERROR---failed
*   OS_OK ------success
******************************************************************/
int OS_rbufsetPriority(OS_RBUF_HANDLE handle, OS_RBUF_PRO_E priority);



#if 0
char * OS_rbuf_create(int size,int align_size);

int OS_calculate_free_size(char * rbuf_id, int *size_after_end, int *size_before_first);

char * OS_rbuf_alloc(char * rbuf_id, int size);
char * OS_rbuf_pend_alloc(char * rbuf_id,int size);

int OS_rbuf_last_resize(char * rbuf_id, char *p,int new_size);

int OS_rbuf_free(char * rbuf_id,char *p);
int OS_rbuf_free_head(char * rbuf_id);
int OS_rbuf_free_last(char * rbuf_id);

char * OS_rbuf_get_head(char * rbuf_id, int *allocate_size);
char * OS_rbuf_get_last(char * rbuf_id, int *allocate_size);

int OS_rbuf_show(char * rbuf_id);

int OS_rbuf_delete(char * rbuf_id);
#endif


#ifdef __cplusplus
}
#endif

#endif //_OS_RBUF_H

