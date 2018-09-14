#ifndef _ERR_LIST_H
#define _ERR_LIST_H


#ifdef	__cplusplus
extern "C"
{
#endif

#define MIN_ERR_DESC_LEN		64
#define errAdd(err_idx)	(*(g_err_list+err_idx))++
#define errGet(err_idx)	(*(g_err_list+err_idx))
#define errSet(err_idx,x)	*(g_err_list+err_idx)=x

extern int * g_err_list;

int err_list_create(int max_err_index,int desc_len);
int errReg(int index,char *desc);
int errShow(int mode);
int errInfo();
void errClr();


#ifdef	__cplusplus
}   /*extern "C"*/
#endif

#endif /*_ERR_LIST_H*/

