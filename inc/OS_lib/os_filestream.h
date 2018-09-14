/*********************************************************************/
/* Filename:    os_filestream.h                                                                               	   */
/*                                                                                                                  */
/*                                                                                                                  */
/* Description: the description os filestream  module					    */
/*                                                                                                                  */
/*  Author:      wangyunjin                                                                                */
/*   Create:   2014-07-25                                                          		          */
/**********************************************************************/

/*********************************************************************/
/* Change History:                                                                                          */
/*     2014-07-25   wangyunjin  Created                                                             */
/*********************************************************************/
#ifndef _OS_FILE_STREAM_H
#define _OS_FILE_STREAM_H


#include <stdio.h>
#include <string.h>
#include "os_global.h"

class OS_fileStream
{
public:
    typedef enum
    {
        EN_FILE_OPEN_RO,
        EN_FILE_OPEN_RW,
        EN_FILE_OPEN_ARW
    }FILE_STRAM_OPEN_TYPE_E;
    
public:
    OS_fileStream();
    OS_fileStream(const char *filePath);

    ~OS_fileStream();
    
    OS_RET_E  setFilePath(const char *filePath);
    OS_RET_E  open(FILE_STRAM_OPEN_TYPE_E type);
    void close();
    OS_RET_E  isOpen();
    int64_t  length();    
    static OS_RET_E  exist(const char * fullFilePath);
    OS_RET_E seekTo(int64_t pos);
    int64_t getPosition();

    void flush();
    int64_t read(void *ptr, int64_t maxLen);
    OS_RET_E write(const void *ptr,int64_t len);
    OS_RET_E rewind();    

private:
    FILE *m_fd;
    char *m_filePath;

};


#endif// #ifndef _OS_FILE_STREAM_H
