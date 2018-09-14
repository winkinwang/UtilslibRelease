#ifndef _SYS_CDEFS_H_
#define _SYS_CDEFS_H_

#include <stdio.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

#define BIT_SET(f, b)		((f) |= (b))
#define BIT_RESET(f, b)		((f) &= ~(b))
#define BIT_FLIP(f, b)		((f) ^= (b))
#define BIT_TEST(f, b)		((f) & (b))

#ifdef IS_BIG_ENDIAN

#define SYS_NTOHL(x) (x)
#define SYS_NTOHS(x) (x)
#define SYS_HTONL(x) (x)
#define SYS_HTONS(x) (x)

#else		// IS_LITTLE_ENDIAN 

#define SYS_NTOHL(x) ((((x) & 0xFF000000)>>24) |  (((x) & 0x00FF0000)>>8) | (((x) & 0x0000FF00)<<8 ) |  (((x) & 0x000000FF)<<24))

#define SYS_NTOHS(x)  ((((x)& 0xFF00)>>8) |  (((x) & 0x00FF)<<8))
 
#define SYS_HTONL(x)  SYS_NTOHL(x)
#define SYS_HTONS(x)  SYS_NTOHS(x)

#endif



#ifdef WIN32

_CRTIMP void __cdecl _assert(void *, void *, unsigned);

#define SYS_ASSERT(_Good_Condition_)		do{											\
	if (!(_Good_Condition_)) {															\
		_assert(#_Good_Condition_, __FILE__, __LINE__);										\
	}																					\
}while (0)

/*
#define RETURN_IF_ASSERT_FAIL(_Good_Condition_)		do{								\
	if (!(_Good_Condition_)) {															\
		_assert(#_Good_Condition_, __FILE__, __LINE__);										\
		return;																			\
	}																					\
}while (0)
*/
#define RETURN_VALUE_IF_ASSERT_FAIL(_Good_Condition_, rtn_val)		do{					\
	if (!(_Good_Condition_)) {															\
		_assert(#_Good_Condition_, __FILE__, __LINE__);										\
		return (rtn_val);																	\
	}																					\
}while (0)

#else

#define SYS_ASSERT(_Good_Condition_)		do{											\
	if (!(_Good_Condition_)) {															\
		printf("ASSERT FAILURE in FILE %s LINE %u %s\n", __FILE__,__LINE__,#_Good_Condition_);	\
	}																					\
}while (0)


#define RETURN_IF_ASSERT_FAIL(_Good_Condition_)		do{								\
	if (!(_Good_Condition_)) {															\
		printf("ASSERT FAILURE in FILE %s LINE %u %s\n", __FILE__,__LINE__,#_Good_Condition_);	\
		return ;																			\
	}																					\
}while (0)

#define RETURN_VALUE_IF_ASSERT_FAIL(_Good_Condition_, rtn_val)		do{					\
	if (!(_Good_Condition_)) {															\
		printf("ASSERT FAILURE in FILE %s LINE %u %s\n", __FILE__,__LINE__,#_Good_Condition_);	\
		return (rtn_val);																	\
	}																					\
}while (0)

#endif

#ifdef __cplusplus
}
#endif

#endif  /*#ifndef _SYS_CDEFS_H_*/

