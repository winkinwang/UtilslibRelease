#ifndef		_BUF_MEM_H_
#define		_BUF_MEM_H_


#define BUF_MEM_ALIGN_SIZE			16

#ifdef __cplusplus
extern "C" {
#endif

typedef struct
{
	unsigned int check_crashed;
	unsigned int align_mem_size;			/*the real size after alloc and 16 bytes align*/
	unsigned int max_used_mem;			/*the max used mem,during running*/
	unsigned int cur_used;				/*current used, used to prevent the override*/
	unsigned int last_alloc_size;		/*using during free, when free point+last_alloc_size==cur_alloc_point										
										, we can backword the cur_alloc_point*/
	char * alloc_p;
	char * align_start_point;	/* the point after alloc and 16 bytes align*/
	char * cur_alloc_point;	/*the point after the last alloc*/
}BUF_MEM_DATA;


BUF_MEM_DATA * buf_mem_init(int size);
void buf_mem_free(BUF_MEM_DATA *p_mem_data,void *p );
void * buf_mem_malloc(BUF_MEM_DATA *p_mem_data,int i_size );
void buf_mem_cleanup(BUF_MEM_DATA *p_mem_data);
void buf_mem_release(BUF_MEM_DATA *p_mem_data);
void show_buf_mem_used(BUF_MEM_DATA *p_mem_data);
void buf_mem_enable_crash_check(BUF_MEM_DATA *p_mem_data);
void buf_mem_disable_crash_check(BUF_MEM_DATA *p_mem_data);

#ifdef __cplusplus
}
#endif

#endif  /*ifdef _BUF_MEM_H_*/

