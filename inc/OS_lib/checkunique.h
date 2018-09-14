#ifndef	CHECK_UNIQUE_H
#define	CHECK_UNIQUE_H


#ifdef __cplusplus
extern "C" {
#endif

/*******************************
*target:  check if this process has started
*
*
*return: -1,  failed for this process has exist
*           0,   success for this process not exist
*********************************/
int OS_uniquityCheck(const char *name);

//!!! this must call before process exit, or rm /dev/shm/sem.name
void OS_uniquityClear(void);

#ifdef __cplusplus
}
#endif

#endif   /*CHECK_UNIQUE_H*/
