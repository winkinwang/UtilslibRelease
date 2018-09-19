
/*********************************************************************/
/* Filename:    urpc_engine.h                                                                               	   */
/*                                                                                                                  */
/*                                                                                                                  */
/* Description: the header of urpc_engine , a engine for rpc base on UDP					    */
/*                                                                                                                  */
/*  Author:      wangyunjin                                                                                */
/*   Create:   2018-07-13                                                           		          */
/**********************************************************************/

/*********************************************************************/
/* Change History:                                                                                          */
/*     2018-07-13   wangyunjin  Created                                                             */
/*********************************************************************/


/***WARNING*******WARNING********WARNING********WARNING*********WARNING***
If used in MFC, please call AfxSocketInit() before using these functions

not use signal(SIGPIPE, SIG_IGN);

************************************************************************/


#ifndef _URPC_ENGINE_H_
#define _URPC_ENGINE_H_

#ifndef NULL
#define NULL 0
#endif

#ifndef IN
#define IN
#endif

#ifndef OUT
#define OUT
#endif

#ifndef INOUT
#define INOUT
#endif


#ifndef WIN32
#include <stdint.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>
#define DLLEXPORT 
#else
#include <windows.h> 
#define DLLEXPORT __declspec(dllimport) 
#endif


#if __cplusplus
extern "C"
{       
#endif

#define MAX_URPC_ENGINE_BUFFER_LEN  (64-1)*1024 //The max length of send buffer

typedef enum
{
    EN_URPC_ERR = -1,  //normal msg from client to server, or server to client
    EN_URPC_FAILED = EN_URPC_ERR,
    EN_URPC_OK,   //reply msg , this msg after a normal msg calling and reply
    EN_URPC_SUCCESS = EN_URPC_OK
}URPC_RESULT_TYPE_E;

typedef enum
{
	EN_URPC_SOCK_EVT_TYPE_REGISTER=0x1000,//for server, new client register
	EN_URPC_SOCK_EVT_TYPE_UNREGISTER,     //for server, client unregister
	EN_URPC_SOCK_EVT_TYPE_MAX 
}URPC_SOCK_EVT_TYPE_E;

typedef void * URPCHandle;
typedef void (*URPC_FUNC_EVT_CB)(IN URPCHandle handle, IN int32_t cliHandle, IN URPC_SOCK_EVT_TYPE_E evtType);
typedef void (*URPC_FUNC_MSG_CB)(IN URPCHandle handle, IN int32_t cliHandle, IN uint8_t *inBuff, IN int32_t inBuffLen, OUT uint8_t *outBuff, INOUT int32_t *outBuffLen);

//Show the version of urpc lib
DLLEXPORT void urpc_verShow();

DLLEXPORT const char *urpc_get_version();

/*
* function:  urpc_server_init
* Target: initialize the server and get the handle
*
* para: handle---return handle of the server instanse
* 	    listenPort---the port for tcp listen
*
* return: URPC_RESULT_TYPE_E, see URPC_RESULT_TYPE_E defined
*
*/
DLLEXPORT URPC_RESULT_TYPE_E urpc_server_init(OUT URPCHandle *handle, IN int32_t listenPort);

/*
* function: urpc_server_set_callback
* Target: set the callback function for receive the event and msg from the engine to user
*
* para: handle---obtain by urpc_server_init
* 	     evtCb---receive event callback
*	     msgCb --- receive massage callback
*
* return: URPC_RESULT_TYPE_E, see URPC_RESULT_TYPE_E defined
*
*/
DLLEXPORT URPC_RESULT_TYPE_E urpc_server_set_callback(IN URPCHandle handle, IN URPC_FUNC_EVT_CB evtCb, IN URPC_FUNC_MSG_CB msgCb);


/*
* function: urpc_server_get_client_ip
* Target:  get the host ip by connection specializing by cliHandle
*
* para: handle---obtain by urpc_server_init
* 	    cliHandle---obtain by URPC_FUNC_EVT_CB(), for one server has more client, a client equal a cliHandle
*         outIp-----return buffer for ip string
*         maxLen----return buffer max length
*
* return: URPC_RESULT_TYPE_E, see URPC_RESULT_TYPE_E defined
*
*/
DLLEXPORT URPC_RESULT_TYPE_E urpc_server_get_client_info(IN URPCHandle handle, IN int32_t cliHandle, OUT char *outIp, IN int32_t maxLen, OUT int32_t *outPort);

/*
* function: urpc_server_deinit
* Target: free the initialized instanse
*
* para: pHandle---obtain by urpc_server_init, Take care: the pointer of the handle
*
* return: URPC_RESULT_TYPE_E, see URPC_RESULT_TYPE_E defined
*
*/
DLLEXPORT URPC_RESULT_TYPE_E urpc_server_deinit(INOUT URPCHandle *pHandle);



/*
* function:  urpc_client_init
* Target: initialize the client instanse and get the handle
*
* para: handle---return handle of the client instanse
* 	    remoteIp---remote server IP addr
* 	    remotePort---remote server port listening by server
*
* return: URPC_RESULT_TYPE_E, see URPC_RESULT_TYPE_E defined
*
*/
DLLEXPORT URPC_RESULT_TYPE_E urpc_client_init(IN URPCHandle *handle, IN const char *remoteIp, IN int32_t remotePort);

/*
* function: urpc_client_start
* Target:   start the client work tasks
*
* para: handle---obtain by urpc_client_init
*
* return: URPC_RESULT_TYPE_E, see URPC_RESULT_TYPE_E defined
*
*/
DLLEXPORT URPC_RESULT_TYPE_E urpc_client_start(IN URPCHandle handle);

/*
* function: urpc_client_send_msg
* Target:  send msg buff to server
*
* para: handle---obtain by urpc_client_init
*	    inBuff --- msg buff need send
*	    inBuffLen --- msg buff length
*	    outBuff --- buff to fill the receive data which server return
*	    inBuffLen ---  the out buff max length when in, and  it presents return msg lenth when output
*         timeOutMs--- block max time(millisecond) to receive the return msg; when timeOutMs <= 0, not block
*
* return: URPC_RESULT_TYPE_E, see URPC_RESULT_TYPE_E defined
*
*/
DLLEXPORT URPC_RESULT_TYPE_E urpc_client_send_msg(IN URPCHandle handle, IN char *inBuff, IN int32_t inBuffLen, OUT char *outBuff, OUT int32_t *outBuffLen, IN int32_t  timeOutMs);

/*
* function: urpc_client_deinit
* Target: free the client instanse by urpc_client_init
*
* para: handle---obtain by urpc_client_init
*
* return: URPC_RESULT_TYPE_E, see URPC_RESULT_TYPE_E defined
*
*/
DLLEXPORT URPC_RESULT_TYPE_E urpc_client_deinit(INOUT URPCHandle *pHandle);


#if __cplusplus
}
#endif

#endif

