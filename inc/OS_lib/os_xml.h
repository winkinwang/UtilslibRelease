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
从XML字符串中获取一个标签内的字符串，譬如:

in_xml指针指向:
<a>
	<b>xxx</b>
</a>

如果调用get_xml_node_str(xmlbuf,"a",outbuf,20); 最后返回的是<b>xxx</b>
如果调用get_xml_node_str(xmlbuf,"b",outbuf,20); 最后返回的是xxx

参数说明:
in_xml  -- 输入xml指针，注意可以是xml中间一段，不一定要完整的xml
node    -- xml node名称，不能超过56字节，不包括前后的<>，而且要求前后<>之间不能有空格
out_buf -- 输出buf
len       -- 输出buf长度
p_tail   -- 最后完成分析时指针位置。可用用作下一次的查找

函数优缺点说明:
这个函数很适合简单而且效率高。适合符合一定规则的内部xml通信的
分析和解析

注意:   node name的长度最多不得超过56字节
*/
DLLEXPORT int OS_xml_get_node_value(char * in_xml,char *node,char *out_buf,int len, char ** p_tail);


//获取输入指针开始的第一个节点名，并返回指针指向结点尾
// 注意: 这里获取的xml里面不能有注释，有注释的话可能会出错
DLLEXPORT int OS_xml_get_first_node_name(char * in_xml,char *node_name,int len, char ** p_tail);

/*
*该函数的功能是改变XML字符串中一个标签内的值
*例如：
in_xml指针指向：
<a> 
	<b>xxx</b>
<a>
node的值为“b” value为新值“yyy”
那么out_xml为：
<a>
	<b>yyy</b>
</a>

假如 in_xml中包含多个相同的标签，那么需要使用以上两个函数中的一个获得p_tail,否则该函数改变的是in_xml中的第一个和node匹配的标签内的值

注意： in_xml和out_xml不能为同一个buffer
*/

DLLEXPORT int OS_xml_set_node_value(char *in_xml, char *out_xml, int outBufLen, char *node, char *value);

#ifdef __cplusplus
}
#endif

#endif


