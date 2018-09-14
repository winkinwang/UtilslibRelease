#ifndef OS_VMSGQ_H
#define OS_VMSGQ_H

#define VMSG_Q_INIT_FLAG 0x00A59375

#define DEFAULT_ALIGN_MODEL 16
#define DEFAULT_ALIGN_MODEL_ARG 4

struct vmsgq
{
	int initFlag;
	int free_size;
	int size;
	int send_block_size;
	int recv_block_count;
	char * empty_sem;
	char * mutexId;
	char * mutexId_send;
	char * full_sem;

	char *pbuf;
	char *sendMsg;
	char *recvMsg;
	char *last;
};

typedef struct vmsgq VMSGQ;
#include "os_global.h"

#ifdef __cplusplus
extern "C" {
#endif

DLLEXPORT char * OS_vmsgqCreate(int size);

DLLEXPORT int OS_vmsgqSend(char * vmsgqid,char *buf,int len);
DLLEXPORT int OS_vmsgqSend_nonblock(char * vmsgqid,char *buf,int len);

DLLEXPORT int OS_vmsgqRecv(char * vmsgqid,char *buf,int len,int *msglen);
DLLEXPORT int OS_vmsgqRecv_nonblock(char * vmsgqid,char *buf,int len,int *msglen);

DLLEXPORT int OS_vmsgqPeek(char * vmsgqid,char *buf,int len,int *msglen);

DLLEXPORT int OS_vmsgqShow(char * vmsgqid);

DLLEXPORT int OS_vmsgqDelete(char * vmsgqid);

DLLEXPORT int OS_vmsgqGetFreeSize(char * vmsgqid);

#ifdef __cplusplus
}
#endif

#endif //OS_VMSGQ_H

