
/*********************************************************************/
/* Filename:    trpc_engine.h                                                                             */
/*                                                                                                                  */
/*                                                                                                                  */
/* Description: the header of trpc_engine , a engine for rpc base on TCP				*/
/*                                                                                                                  */
/*  Author:      wangyunjin                                                                                */
/*   Create:   2014-05-21                                                           		          */
/**********************************************************************/

/*********************************************************************/
/* Change History:                                                                                          */
/*     2014-05-21   wangyunjin  Created                                                             */
/*********************************************************************/


/***WARNING*******WARNING********WARNING********WARNING*********WARNING***
If used in MFC, please call AfxSocketInit() before using these functions

not use signal(SIGPIPE, SIG_IGN);

************************************************************************/


#ifndef _TRPC_ENGINE_H_
#define _TRPC_ENGINE_H_

#ifndef NULL
#define NULL 0
#endif

#ifndef WIN32
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

#define MAX_TRPC_ENGINE_BUFFER_LEN  40*1024 //The max msg length when send

typedef enum
{
	EN_TRPC_SOCK_EVT_NEW_CONNECTION=0x1000,//for server, new client connect
	EN_TRPC_SOCK_EVT_STARTED,     //for client,  the recv thread start success
	EN_TRPC_SOCK_EVT_CONNECTION_CLOSE  //socket closed

}TRPC_SOCK_EVT_E;

typedef enum
{
    EN_TRPC_SOCK_MSG_TYPE_NORMAL,  //normal msg from client to server, or server to client
    EN_TRPC_SOCK_MSG_TYPE_RETURN   //reply msg , this msg after a normal msg calling and reply
}TRPC_SOCK_MSG_TYPE_E;

typedef void * TRPCHandle;

typedef struct
{
    TRPCHandle handle;    
    int cliHandle;  //for server,  sub client id
    void *userData;
}CB_BASE_INFO_S;


typedef void (*TRPC_FUNC_EVT_CB)(CB_BASE_INFO_S *info, TRPC_SOCK_EVT_E evt);
typedef void (*TRPC_FUNC_MSG_CB)(CB_BASE_INFO_S *info, char *inBuff, int inBuffLen);

//Show the version of trpc lib
DLLEXPORT void trpc_verShow();

DLLEXPORT const char *trpc_get_version();


//for server

/*
* function:  trpc_svr_init
* Target: initialize the server peer and get the handle
*
* para: handle---the return handle of the server instanse
* 	    listenPort---the port for tcp listen
*
* return: >0---successful
* 		-1---failed
*
*/
DLLEXPORT int trpc_svr_init(TRPCHandle *handle, int listenPort);

/*
* function: trpc_svr_set_cb
* Target: set the callback function for receive the event and msg from the engine to user
*
* para: handle---obtain by trpc_svr_init
* 	     evtCb---event message cb
*	     msgCb --- receive massage cb
*	     userData --- the private parameter for cb
*
* return: >0---successful
* 		-1---failed
*
*/
DLLEXPORT int trpc_svr_set_cb(TRPCHandle handle, TRPC_FUNC_EVT_CB evtCb, TRPC_FUNC_MSG_CB msgCb, void *userData);


/*
* function: trpc_svr_send_msg
* Target:  send msg buff to client
*
* para: handle---obtain by trpc_svr_init
* 	    cliHandle---obtain by TRPC_FUNC_EVT_CB(), for one server has more client, a client a cliHandle
*	    type --- msg type:normal or return
*	    msgBuff --- msg buff need send
*	    msgLen --- msg buff length
*
* return: =0---successful
* 		-1---failed
*
*/
DLLEXPORT int trpc_svr_send_msg(TRPCHandle handle, int cliHandle, TRPC_SOCK_MSG_TYPE_E type, char *msgBuff, int msgLen);

/*
* function: trpc_svr_get_client_ip
* Target:  get the host ip by connection specializing by cliHandle
*
* para: handle---obtain by trpc_svr_init
* 	    cliHandle---obtain by TRPC_FUNC_EVT_CB(), for one server has more client, a client a cliHandle
*         outIp-----the return buffer for ip string
*         maxLen----the return buffer max length
*
* return: 0---successful
* 		-1---failed
*
*/
DLLEXPORT int32_t trpc_svr_get_client_ip(TRPCHandle handle,int cliHandle, char *outIp, int32_t maxLen);


/*
* function: trpc_svr_close_connection
* Target:  close a connection specializing by cliHandle
*
* para: handle---obtain by trpc_svr_init
* 	    cliHandle---obtain by TRPC_FUNC_EVT_CB(), for one server has more client, a client a cliHandle
*
* return: =0---successful
* 		-1---failed
*
*/
DLLEXPORT int trpc_svr_close_connection(TRPCHandle handle,int cliHandle);

/*
* function: trpc_svr_deinit
* Target: free the initialized instanse
*
* para: handle---obtain by trpc_svr_init
*
* return: =0---successful
* 		-1---failed
*
*/
DLLEXPORT int trpc_svr_deinit(TRPCHandle *handle);


//for client

/*
* function:  trpc_client_init
* Target: initialize the client instanse and get the handle
*
* para: handle---the return handle of the server instanse
* 	    svrIp---the server IP addr
* 	    svrPort---the port listening by server
*
* return: >0---successful
* 		-1---failed
*
*/
DLLEXPORT int trpc_client_init(TRPCHandle *handle, char *svrIp, int svrPort);

/*
* function: trpc_client_start
* Target:   start the client receiving thread
*
* para: handle---obtain by trpc_client_init
*
* return: >0---successful
* 		-1---failed
*
*/
DLLEXPORT int trpc_client_start(TRPCHandle handle);

/*
* function: trpc_client_set_cb
* Target: set the callback function for receive the event and msg from the engine to user
*
* para: handle---obtain by trpc_client_init
* 	     evtCb---event message cb
*	     msgCb --- receive massage cb
*	     userData --- the private parameter for cb
*
* return: >0---successful
* 		-1---failed
*
*/
DLLEXPORT int trpc_client_set_cb(TRPCHandle handle, TRPC_FUNC_EVT_CB evtCb, TRPC_FUNC_MSG_CB msgCb, void *userData);

/*
* function: trpc_client_send_msg
* Target:  send msg buff to server
*
* para: handle---obtain by trpc_client_init
*	    type --- msg type:normal or return
*	    msgBuff --- msg buff need send
*	    msgLen --- msg buff length
*
* return: =0---successful
* 		-1---failed
*
*/
DLLEXPORT int trpc_client_send_msg(TRPCHandle handle, TRPC_SOCK_MSG_TYPE_E type, char *msgBuff, int msgLen);

/*
* function: trpc_client_wait_for_reply
* Target:  block to receive the reply msg from server for timeOutMs
*
* para: handle---obtain by trpc_client_init
*         msgBuff --- msg buff need send
*	    msgLen --- msg buff length
* 	    timeOutMs---block time (ms)
*	    outBuff --- output message buffer to fill
*	    outLen --- input buffer max length and output the real msg length
*
* return: >0---successful
* 		-1---failed
*
*/
//WRN:  suggest use mutex to protect calling after sending over   or  after recv replying(if with reply)  
DLLEXPORT int trpc_client_send_with_reply(TRPCHandle handle, char *msgBuff, int msgLen, char *outBuff, int *outLen, int timeOutMs);

/*
* function: trpc_client_deinit
* Target: free the initialized instanse by trpc_client_init
*
* para: handle---obtain by trpc_client_init
*
* return: >0---successful
* 		-1---failed
*
*/
DLLEXPORT int trpc_client_deinit(TRPCHandle *handle);


#if __cplusplus
}
#endif

#endif

