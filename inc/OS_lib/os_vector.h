/*********************************************************************/
/* Filename:    os_vector.h                                                                           	   */
/*                                                                                                                  */
/*                                                                                                                  */
/* Description: the header description of Vector                     				    */
/*                                                                                                                  */
/*  Author:      wangyunjin                                                                                */
/*   Create:   2016-07-05                                                          		          */
/**********************************************************************/

/*********************************************************************/
/* Change History:                                                                                          */
/*     2016-07-05   wangyunjin  Created                                                             */
/*********************************************************************/



#ifndef __OS_VECTOR_H_
#define __OS_VECTOR_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "os_global.h"


typedef void *citerator;  
typedef void *OS_VEC_HANDLE;  
  
DLLEXPORT OS_VEC_HANDLE   OS_vector_create   (const int32_t size);  
DLLEXPORT void      OS_vector_destroy  (OS_VEC_HANDLE *pHandle);  
DLLEXPORT int32_t   OS_vector_length   (const OS_VEC_HANDLE handle);  
DLLEXPORT int32_t   OS_vector_pushback (const OS_VEC_HANDLE handle, void *memb);  
DLLEXPORT int32_t   OS_vector_popback  (const OS_VEC_HANDLE handle, void *memb);  
DLLEXPORT int32_t   OS_vector_iter_at  (const OS_VEC_HANDLE handle, citerator iter);  
DLLEXPORT int32_t   OS_vector_iter_val (const OS_VEC_HANDLE handle, citerator iter, void *memb);  
DLLEXPORT citerator OS_vector_begin    (const OS_VEC_HANDLE handle);  
DLLEXPORT citerator OS_vector_end      (const OS_VEC_HANDLE handle);  
DLLEXPORT citerator OS_vector_next     (const OS_VEC_HANDLE handle, citerator iter);
DLLEXPORT int32_t   OS_vector_val(const OS_VEC_HANDLE handle, citerator iter, void *memb);
DLLEXPORT int32_t   OS_vector_val_at   (const OS_VEC_HANDLE handle, int32_t index, void *memb);  
DLLEXPORT int32_t   OS_vector_insert   (const OS_VEC_HANDLE handle, citerator iter, void *memb);  
DLLEXPORT int32_t   OS_vector_insert_at(const OS_VEC_HANDLE handle, int32_t index, void *memb);  
DLLEXPORT int32_t   OS_vector_rm       (const OS_VEC_HANDLE handle, citerator iter);  
DLLEXPORT int32_t   OS_vector_rm_at    (const OS_VEC_HANDLE handle, int32_t index);
DLLEXPORT int32_t   OS_vector_update(const OS_VEC_HANDLE handle, citerator iter, void *memb);
DLLEXPORT int32_t   OS_vector_update_at(const OS_VEC_HANDLE handle, int32_t index, void *memb);


/* for test  */  
DLLEXPORT void      cv_dump_info          (const OS_VEC_HANDLE handle);  
 

#ifdef __cplusplus
}
#endif

#endif /* __OS_VECTOR_H_ */

