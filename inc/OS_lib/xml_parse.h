#ifndef _XML_PARSE_H_
#define _XML_PARSE_H_


#ifdef __cplusplus
extern "C" {
#endif

int xml_attach_file(char *filename);
int xml_attach_msg(char *msg);
int xml_element_get(char *outbuf,int *outlen,int *rec_num,char *node0,char *node1,char *node2);
int xml_getelement_seq(char *outbuf,int *outlen,char *node0,char *node1,char *node2);
int xml_getelement_next();
int xml_detach();


#ifdef __cplusplus
}
#endif

#endif
