

/*********************************************************************/
/* Filename:    os_cli.h                                                                               	   */
/*                                                                                                                  */
/*                                                                                                                  */
/* Description: the description os cli debug function module					    */
/*                                                                                                                  */
/*  Author:      wangyunjin                                                                                */
/*   Create:   2014-03-4                                                           		          */
/**********************************************************************/

/*********************************************************************/
/* Change History:                                                                                          */
/*     2014-03-4   wangyunjin  Created                                                             */
/*********************************************************************/

#ifndef _OS_CLI_H_
#define _OS_CLI_H_

#ifdef __cplusplus
extern "C" {
#endif

#ifndef WIN32
#define	TRUE			1
#define	FALSE			0
#endif

#define MAX_CLI_REG_FUNC 16
#define MAX_CLI_FUNC_NAME 32
#define MAX_CLI_FUNC_PARA_NUM 5


typedef enum sec_type
{
    OS_SYMB_TYP_FUNC,
    OS_SYMB_TYP_DATA
}sec_type_e;


/* *********************************************************
*** function:   OS_cliInitWithAuth
*** target:      init the remote debug module on listening port
*** para:     listenPort--the listening socket port for debug-client
***             userName---the username of authority
***             userPassword---the password of authority
***             
*** return:   0--success
***              -1-- failed
************************************************************/
int OS_cliInitWithAuth(int listenPort, char *userName, char *userPassword);


/* *********************************************************
*** function:   OS_cliInit
*** target:      init the remote debug module on listening port
*** para:     listenPort--the listening socket port for debug-client
***
*** return:   0--success
***              -1-- failed
************************************************************/
int OS_cliInit(int listenPort);


/* *********************************************************
*** function:   OS_regSym,   This api not full-function
*** target:      register the user debug object(function or global-variant) into the module
*** para:     name--the name of the debug object
***             size---the value size, if the symbol is global variant
***             type---the type of the symbol of the addr
***             addr---the address of the symbol object
*** 
*** return:   0--success
***              -1 -- failed
************************************************************/
int OS_regSym(const char *name, int size, int type, void* addr);



//
/* *********************************************************
*** function:   OS_regFuncSym
*** target:      register the user debug function into the module
*** para:     name--the name of the debug object
***             funcAddr---the address of the function symbol
***             paraNum---the function para num, para only support char *, user can transfer it in func code
*** 
*** return:   0--success
***              -1 -- failed
************************************************************/
int OS_regFuncSym(const char *name, void* funcAddr, int paraNum);

//I--int32_t, L--long, S---string[char *], C---char, V--void exp: func(int, char *, c)==="ISC"
//int OS_regFuncSym(const char *name, void* funcAddr, char *funcParaType);


#ifdef __cplusplus
}
#endif
#endif  /* _OS_CLI_H_ */

