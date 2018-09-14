
/*********************************************************************/
/* Filename:    os_log.h                                                                               	   */
/*                                                                                                                  */
/*                                                                                                                  */
/* Description: the description os log module					    */
/*                                                                                                                  */
/*  Author:      wangyunjin                                                                                */
/*   Create:   2014-03-4                                                           		          */
/**********************************************************************/

/*********************************************************************/
/* Change History:                                                                                          */
/*     2014-03-4   wangyunjin  Created                                                             */
/*********************************************************************/

#ifndef __OS_LOG_H_
#define __OS_LOG_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "os_global.h"

/* log levels */
#define LVL_FATAL       16  /* 1<<4 */
#define LVL_ERR         8   /* 1<<3 */
#define LVL_WRN         4   /* 1<<2 */
#define LVL_INFO        2   /* 1<<1 */
//#define LVL_TRACE       1
#define LVL_TRACE       32


#define OS_LOG_NUM_OF_LEVELS      5
#define OS_LOG_FULL_LEVEL_MASK    0x1F  /* in binary: 11111 */

//log show domain
#define OS_LOG_DOMAIN_MOD           8   /* 1<<3 */
#define OS_LOG_DOMAIN_TIME          4   /* 1<<2 */
#define OS_LOG_DOMAIN_APPNAME       2   /* 1<<1 */
#define OS_LOG_DOMAIN_LEVEL         1
#define OS_LOG_DOMAIN_ALL           OS_LOG_DOMAIN_LEVEL|OS_LOG_DOMAIN_APPNAME|OS_LOG_DOMAIN_TIME|OS_LOG_DOMAIN_MOD


/* input vaules for printSwitch parameter of slogInit() */
#define OS_LOG_PRINT_ON           1
#define OS_LOG_PRINT_OFF          0

#define OS_LOG_MAX_LOG_STR_LEN          1000
#define OS_LOG_EVENT_LOG_ENTRY          WS_EVENT_USER_BASE
#define OS_LOG_MIN_FILE_SIZE            8192
#define OS_LOG_DEFAULT_MAX_FILE_SIZE    512*1024
#define OS_LOG_MAX_FILE_SIZE            512*1024*1024   /*the max file size is 512M*/
#define OS_LOG_DEFAULT_MAX_BACKUPS      4      /* must > 0 */
#define OS_LOG_MAX_BACKUPS              10000   /*the max backup file numbers*/
#define OS_LOG_SKT_SND_BUF_SIZE         65536  /* 64 KB, max: 252 KB */

#define OS_LOG_MAX_APP_NAME_LEN         32
#define OS_LOG_MAX_MODNAME_LEN          32
#define OS_LOG_MAX_MOD_NUM              32   /*the max module number is 32*/

#define OS_LOG_REMOTE_PORT 12564
#define OS_LOGI(mod, fmt, ...)  OS_log(LVL_INFO, mod, "%s(line:%d) "fmt, __func__,__LINE__, ##__VA_ARGS__);
#define OS_LOGW(mod, fmt, ...)  OS_log(LVL_WRN, mod, "%s(line:%d) "fmt, __func__,__LINE__, ##__VA_ARGS__);
#define OS_LOGE(mod, fmt, ...)  OS_log(LVL_ERR, mod, "%s(line:%d) "fmt, __func__,__LINE__, ##__VA_ARGS__);
#define OS_LOGD(mod, fmt, ...)  OS_log(LVL_TRACE, mod, "%s(line:%d) "fmt, __func__,__LINE__, ##__VA_ARGS__);


DLLEXPORT int OS_logModReg(unsigned int mod,const char *modname);
DLLEXPORT int OS_logInit(const char *remoteIp,const char *localFile,int   printSwitch);
DLLEXPORT int OS_logSetGrade(unsigned int  mod,unsigned int  grade);
DLLEXPORT void OS_log(unsigned int  level,unsigned int  mod,const char   *fmt, ...);

//if use, must call before OS_logInit
DLLEXPORT int OS_logSetParam(unsigned int maxFileSize,unsigned int maxBackup);
DLLEXPORT int OS_logSetPrint(int printSwitch);
//int OS_logSetMask(unsigned int  mod,unsigned int  levelMask);
//unsigned int OS_logGetMask(unsigned int mod);
//int OS_logSetSysPri(unsigned int facility,unsigned int level);
DLLEXPORT void OS_logSetAppName(const char *appName);
DLLEXPORT void OS_logFlush();

//void OS_logStatus();
//void OS_logHelp();

DLLEXPORT int OS_logSetRemote(const char *remoteIp);
DLLEXPORT int OS_logSetLocalFile(const char *localFile);

DLLEXPORT int OS_logSetDomainMask(uint32_t mod,uint32_t domainMask);
DLLEXPORT uint32_t OS_logGetDomainMask(uint32_t mod);



//de-init oslog
DLLEXPORT void OS_logDeInit();

#ifdef __cplusplus
}
#endif

#endif /* __OS_LOG_H_ */

