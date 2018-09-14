#ifndef _OS_GLOBAL_H
#define _OS_GLOBAL_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef WIN32
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>
#define DLLEXPORT 
#else
#include <windows.h> 
#define DLLEXPORT __declspec(dllimport) 
#define __func__ __FUNCTION__
#define sleep(x) Sleep(1000*x)
#define usleep(x) Sleep(x/1000)
#endif

/*define wait forever constant for mutex/semaphore*/
#ifndef OS_WAIT_FOREVER
	#define OS_WAIT_FOREVER -1	/*mutex/semaphore will wait forever when use it to take*/
#endif

#define HAVE_STDINT_H 1

#ifdef HAVE_STDINT_H
#include <stdint.h>
#else
#ifndef __int8_t_defined
#define __int8_t_defined
	typedef char          int8_t;
	typedef long long     int64_t;
#endif

	typedef unsigned char uint8_t;
	typedef int           int32_t;
	typedef short int     int16_t;
	typedef unsigned short int  uint16_t;

#ifndef __uint32_t_defined
#define __uint32_t_defined
	typedef unsigned int  uint32_t;
#endif

#ifndef __int8_t_defined
#define __int8_t_defined
	typedef long long     int64_t;
#endif 

#ifndef __uint64_t_defined
#define __uint64_t_defined
	typedef unsigned long long uint64_t;
#endif

#endif

#ifndef MAX_FILE_PATH
#define MAX_FILE_PATH 256
#endif

typedef enum
{
    OS_EXIT=-3,
    OS_TIMEOUT,
    OS_ERROR,
    OS_OK
}OS_RET_E;

typedef enum
{
    OS_FALSE,
    OS_TRUE
}OS_BOOL_E;


DLLEXPORT void OS_verShow();

DLLEXPORT char *OS_get_version();

#ifdef __cplusplus
}
#endif

#endif/*_OS_GLOBAL_H*/

