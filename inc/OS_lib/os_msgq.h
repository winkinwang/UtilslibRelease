

/*********************************************************************/
/* Filename:    os_msgq.h                                                                               	   */
/*                                                                                                                  */
/*                                                                                                                  */
/* Description: the description os msg queue module					    */
/*                                                                                                                  */
/*  Author:      wangyunjin                                                                                */
/*   Create:   2014-03-4                                                           		          */
/**********************************************************************/

/*********************************************************************/
/* Change History:                                                                                          */
/*     2014-03-4   wangyunjin  Created                                                             */
/*********************************************************************/

#ifndef _OS_MSGQ_H
#define  _OS_MSGQ_H

#include "os_global.h"

#ifdef __cplusplus
extern "C" {
#endif

//#define OS_msgqPush			OS_msgqSend_head_nonblock
//#define OS_msgqPop			OS_msgqRecv_nonblock

DLLEXPORT char * OS_msgqCreate(int count,int size);
DLLEXPORT int OS_msgqDelete(char * msgq_id);

DLLEXPORT int OS_msgqSend(char * msgq_id,void *p_msg);
DLLEXPORT int OS_msgqSend_nonblock(char * msgq_id,void *p_msg);

//int OS_msgqSend_head(char * msgq_id,void *p_msg);
//int OS_msgqSend_head_nonblock(char * msgq_id,void *p_msg);

DLLEXPORT int OS_msgqRecv(char * msgq_id,void *p_msg);
DLLEXPORT int OS_msgqRecv_nonblock(char * msgq_id,void *p_msg);

//int OS_msgqPeek(char * msgq_id,void *p_msg);
//int OS_msgqShow(char * msgq_id);

//int OS_msgqPush(char * msgq_id,void *p_msg);
//int OS_msgqPop(char * msgq_id,void *p_msg);

DLLEXPORT int OS_msgqGetMsgCnt(char *msgq_id);

#ifdef __cplusplus
}
#endif

#endif //_OS_MSGQ_H

