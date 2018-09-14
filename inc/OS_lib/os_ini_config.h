  
/*********************************************************************/
/* Filename:    ini_config.h                                                                                   */
/*                                                                                                                  */
/*                                                                                                                  */
/* Description: declarations/definitions   for   reading   configuration   files                       */
/*                                                                                                                  */
/*  Author:      wangyunjin                                                                                */
/*   Create:   2014-03-4                                                                          */
/**********************************************************************/

/*********************************************************************/
/* Change History:                                                                                          */
/*     2014-03-4   wangyunjin  Created                                                             */
/*********************************************************************/

    
#ifndef   _INI_CONFIG_H_   
#define   _INI_CONFIG_H_   

#include "os_global.h"

#ifdef __cplusplus
extern "C" {
#endif

/*   
*   Set   line   length   in   configuration   files     
*/   
#define   MAX_FILENAME_LEN   128   


/*   
*   Define   return   error   code   value   
*/   
#define   ERR_NONE   0                 /*   read   configuration   file   successfully   */   
#define   ERR_NOFILE   2             /*   not   find   or   open   configuration   file   */   
#define   ERR_RWFILE   3         /*   error   occur   in   reading or writing  configuration   file   */   
#define   ERR_FORMAT   4             /*   invalid   format   in   configuration   file   */   
#define   ERR_NOTHING   5           /*   not   find   section   or   key   name   in   configuration   file   */   

/*
sample for configure file content:

[section1]
keyname1=keyvalue1
keyname2=keyvalue2
[section2]
keyname3=keyvalue3
keyname4=keyvalue4
*/

    
/* ***********************************************
*** function:   OS_getconfigstr
*** target:      Read   the   value   of   key   name   in   string   form
*** para:     section--the area of []
***             keyname---the key name underin section
***             keyvalue---the key value of the keyname
***             maxLen---the key value buffer len
***             fileName---the file path of the configure file
*** return:   0--success
***              ERR_*** -- failed
*/   
DLLEXPORT int OS_getconfigstr(const char*section,
                        const char*keyName, 
                        char*   keyValue,             
                        unsigned   int   maxLen,        
                        const   char*   fileName); 



/* ***********************************************
*** function:   getconfigint
*** target:      Read   the   value   of   key   name   in   integer   form
*** para:     section--the area of []
***             keyname---the key name underin section
***             keyvalue---the key value of the keyname
***             maxLen---the key value buffer len
***             fileName---the file path of the configure file
*** return:   0--success
***              ERR_*** -- failed
*/   

DLLEXPORT int OS_getconfigint(const char* section,
                        const char* keyName, 
                        int* keyValue, 
                        const char* fileName); 

/* ***********************************************
*** function:   setconfigstr
*** target:      write   the   value   of   key   name   in   string   form
*** para:     section--the area of []
***             keyname---the key name underin section
***             keyvalue---the key value of the keyname
***             maxLen---the key value buffer len
***             fileName---the file path of the configure file
*** return:   0--success
***              ERR_*** -- failed
*/   
DLLEXPORT int OS_setconfigstr(const char*section,
                        const char*keyName, 
                        char*   keyValue,
                        const   char*   fileName); 



/* ***********************************************
*** function:   setconfigint
*** target:      write   the   value   of   key   name   in   integer   form
*** para:     section--the area of []
***             keyname---the key name underin section
***             keyvalue---the key value of the keyname
***             maxLen---the key value buffer len
***             fileName---the file path of the configure file
*** return:   0--success
***              ERR_*** -- failed
*/   

DLLEXPORT int OS_setconfigint(const char* section,
                        const char* keyName, 
                        int keyValue, 
                        const char* fileName); 


    
#ifdef __cplusplus
}
#endif
#endif   

