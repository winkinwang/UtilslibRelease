/*********************************************************************/
/* Filename:    os_XML.h                                                                               	   */
/*                                                                                                                  */
/*                                                                                                                  */
/* Description: the description os parse xml buffer module					    */
/*                                                                                                                  */
/*  Author:      wangyunjin                                                                                */
/*   Create:   2014-07-30                                                           		          */
/**********************************************************************/

/*********************************************************************/
/* Change History:                                                                                          */
/*     2014-07-30   wangyunjin  Created                                                             */
/*********************************************************************/
#ifndef _OS_XML_H_
#define _OS_XML_H_

#include "os_global.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
��XML�ַ����л�ȡһ����ǩ�ڵ��ַ�����Ʃ��:

in_xmlָ��ָ��:
<a>
	<b>xxx</b>
</a>

�������get_xml_node_str(xmlbuf,"a",outbuf,20); ��󷵻ص���<b>xxx</b>
�������get_xml_node_str(xmlbuf,"b",outbuf,20); ��󷵻ص���xxx

����˵��:
in_xml  -- ����xmlָ�룬ע�������xml�м�һ�Σ���һ��Ҫ������xml
node    -- xml node���ƣ����ܳ���56�ֽڣ�������ǰ���<>������Ҫ��ǰ��<>֮�䲻���пո�
out_buf -- ���buf
len       -- ���buf����
p_tail   -- �����ɷ���ʱָ��λ�á�����������һ�εĲ���

������ȱ��˵��:
����������ʺϼ򵥶���Ч�ʸߡ��ʺϷ���һ��������ڲ�xmlͨ�ŵ�
�����ͽ���

ע��:   node name�ĳ�����಻�ó���56�ֽ�
*/
DLLEXPORT int OS_xml_get_node_value(char * in_xml,char *node,char *out_buf,int len, char ** p_tail);


//��ȡ����ָ�뿪ʼ�ĵ�һ���ڵ�����������ָ��ָ����β
// ע��: �����ȡ��xml���治����ע�ͣ���ע�͵Ļ����ܻ����
DLLEXPORT int OS_xml_get_first_node_name(char * in_xml,char *node_name,int len, char ** p_tail);

/*
*�ú����Ĺ����Ǹı�XML�ַ�����һ����ǩ�ڵ�ֵ
*���磺
in_xmlָ��ָ��
<a> 
	<b>xxx</b>
<a>
node��ֵΪ��b�� valueΪ��ֵ��yyy��
��ôout_xmlΪ��
<a>
	<b>yyy</b>
</a>

���� in_xml�а��������ͬ�ı�ǩ����ô��Ҫʹ���������������е�һ�����p_tail,����ú����ı����in_xml�еĵ�һ����nodeƥ��ı�ǩ�ڵ�ֵ

ע�⣺ in_xml��out_xml����Ϊͬһ��buffer
*/

DLLEXPORT int OS_xml_set_node_value(char *in_xml, char *out_xml, int outBufLen, char *node, char *value);

#ifdef __cplusplus
}
#endif

#endif


