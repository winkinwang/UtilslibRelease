/*********************************************************************/
/* Filename:    os_crypto.h                                                                               	   */
/*                                                                                                                  */
/*                                                                                                                  */
/* Description: the description os crypto  module		                                     */
/*                                                                                                                  */
/*  Author:      wangyunjin                                                                                */
/*   Create:   2016-10-18                                                           		          */
/**********************************************************************/

/*********************************************************************/
/* Change History:                                                                                          */
/*     2016-10-18     wangyunjin  Created                                                             */
/*********************************************************************/

#ifndef _OS_CRYPTO_H
#define _OS_CRYPTO_H


#ifdef __cplusplus
extern "C" {
#endif

/*
* function:  OS_crypto_encode
* Target: encrypt encode srcData by secretKey
*
* para: srcData---the source string
* 	    srcDataLen---the source string length
* 	    secretKey---the encode secret string
* 	    secretKeyLen---the encode secret string length
* 	    dstData---the output buffer after encode
* 	    dstDataMaxLen---the output buffer max length
*
* return: =srcDataLen---successful
* 		other ---failed
*/
DLLEXPORT int  OS_crypto_encode(char *srcData, int srcDataLen, char *secretKey, int secretKeyLen, char *dstData, int dstDataMaxLen);

/*
* function:  OS_crypto_decode
* Target: encrypt decode srcData by secretKey
*
* para: srcData---the source string
* 	    srcDataLen---the source string length
* 	    secretKey---the encode secret string
* 	    secretKeyLen---the decode secret string length
* 	    dstData---the output buffer after decode
* 	    dstDataMaxLen---the output buffer max length
*
* return: =srcDataLen---successful
* 		other ---failed
*/

DLLEXPORT int  OS_crypto_decode(char *srcData, int srcDataLen, char *secretKey, int secretKeyLen, char *dstData, int dstDataMaxLen);


#ifdef __cplusplus
}
#endif


#endif	//_OS_CONF_H

