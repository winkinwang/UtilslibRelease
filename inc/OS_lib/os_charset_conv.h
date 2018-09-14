/*********************************************************************/
/* Filename:    os_charset_conv.h                                                                               	   */
/*                                                                                                                  */
/*                                                                                                                  */
/* Description: the description os character set convert module					    */
/*                                                                                                                  */
/*  Author:      wangyunjin                                                                                */
/*   Create:   2014-08-13                                                           		          */
/**********************************************************************/

/*********************************************************************/
/* Change History:                                                                                          */
/*     2014-08-13   wangyunjin  Created                                                             */
/*********************************************************************/

#ifndef	OS_CHARSET_CONV_H
#define	OS_CHARSET_CONV_H

#ifdef WIN32

#else

#endif

#ifdef __cplusplus
extern "C" {
#endif

#include "os_global.h"


/****************************************************************
*function:      OS_charSetConv_gb2uni 
*description:  convert gb string to unicode string
*parameter:
*		inGbBuff------the source string encoding by gb
*            inBuffSize-----the source string byte length
*		outUniBuff-----out to the dest string encoding by unicode
*            maxOutSize-----the dest buff max u16-byte length(the real byte len=inBuffSize*2)
*		
*
*return:
*	<0---failed
*	Other----the real unicode string u16-bytes after convert(the real byte len=return*2)
******************************************************************/
int32_t OS_charSetConv_gb2uni(uint8_t *inGbBuff, uint32_t inBuffSize, uint16_t *outUniBuff, uint32_t maxU16OutSize);



/****************************************************************
*function:      OS_charSetConv_uni2utf8 
*description:  convert unicode string to utf8
*parameter:
*		inUniBuff------the source string encoding by gb
*            inBuffSize-----the source string u16-byte length(the real byte len=inBuffSize*2)
*		outUtf8Buff-----out to the dest string encoding by unicode
*            maxOutSize-----the dest buff max bytes length
*		
*
*return:
*	<0---failed
*	Other----the real utf-8 string bytes after convert
******************************************************************/
int32_t OS_charSetConv_uni2utf8(uint16_t *inUniBuff, uint32_t inU16BuffSize, uint8_t *outUtf8Buff, uint32_t maxOutSize);


/****************************************************************
*function:      OS_charSetConv_utf82uni 
*description:  convert utf8 string to  unicode
*parameter:
*		inUtf8Buff------the source string encoding by gb
*            inBuffSize-----the source string bytes length
*		outUniBuff-----out to the dest string encoding by unicode
*            maxUniOutSize-----the dest buff max bytes length(the real byte len=maxUniOutSize*2)
*		
*
*return:
*	<0---failed
*	Other----the real u16 string bytes after convert(the real byte len=return*2)
******************************************************************/
int32_t OS_charSetConv_utf82uni(uint8_t *inUtf8Buff, uint32_t inBuffSize, uint16_t *outUniBuff, uint32_t maxUniOutSize);


/****************************************************************
*function:      OS_charSetConv_uni2gb 
*description:  convert unicode string to gb
*parameter:
*		inUniBuff------the source string encoding by gb
*            inU16BuffSize-----the source string u16-byte length(the real byte len=inBuffSize*2)
*		outGbBuff-----out to the dest string encoding by unicode
*            maxOutSize-----the dest buff max bytes length
*		
*
*return:
*	<0---failed
*	Other----the real gb string bytes after convert
******************************************************************/
int32_t OS_charSetConv_uni2gb(uint16_t *inUniBuff, uint32_t inU16BuffSize, uint8_t *outGbBuff, uint32_t maxOutSize);



#ifdef __cplusplus
}
#endif
#endif  /*OS_CHARSET_CONV_H*/


