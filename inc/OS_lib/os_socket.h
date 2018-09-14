

#ifndef  SOCKET_UTILS_H
#define  SOCKET_UTILS_H

#include "os_global.h"

#ifdef __cplusplus
extern "C" {
#endif

DLLEXPORT int32_t checkNetworkIfStatus(char* ifName); //"eth0"

//int32_t getLocalIP(char *localIp, int32_t maxLen) ;
DLLEXPORT int32_t getLocalIp(char *localIp, int32_t maxLen, char *hwInterface) ;//hwInterface: eth0, eth1,wlan0....

DLLEXPORT int32_t getHostNameIP(const char *hostName, char *outIp, int32_t maxLen);

//// please use the below with prefix "tcp_socket_XXXX"
/*int32_t create_tcp_socket();
int32_t socket_bind_port(int32_t sockFd, int32_t port);
int32_t wait_for_request(int32_t sockFd);
int32_t wait_for_connection(int32_t sockFd, uint32_t *netIp);
int32_t connect_server(int32_t sockFd,char *ipAddr, int32_t port);
int32_t read_msg_with_peek(int32_t sockFd, char *buff, int32_t peekLen);
int32_t read_msg_waitall(int32_t sockFd, char *buff, int32_t maxLen);
int32_t read_msg(int32_t sockFd, char *buff, int32_t maxLen);
int32_t send_msg(int32_t sockFd, const char *buff, int32_t len);*/
/////end

DLLEXPORT int32_t tcp_socket_create();
DLLEXPORT int32_t tcp_socket_bind_port(int32_t sockFd, int32_t port);
DLLEXPORT int32_t tcp_socket_bind_port_all(int32_t sockFd, char *localIp, int32_t port, int32_t reuseaddrFlag);
//int32_t tcp_socket_wait_for_connection(int32_t sockFd, uint32_t *netIp);
DLLEXPORT int32_t tcp_socket_wait_for_connection(int32_t sockFd, char *remoteNetIp);
DLLEXPORT int32_t tcp_socket_connect_server(int32_t sockFd,char *ipAddr, int32_t port);
DLLEXPORT int32_t tcp_socket_read_msg_with_peek(int32_t sockFd, char *buff, int32_t peekLen);
DLLEXPORT int32_t tcp_socket_read_msg_waitall(int32_t sockFd, char *buff, int32_t maxLen);
DLLEXPORT int32_t tcp_socket_read_msg(int32_t sockFd, char *buff, int32_t maxLen);
DLLEXPORT int32_t tcp_socket_send_msg(int32_t sockFd, const char *buff, int32_t len);



DLLEXPORT int32_t udp_create_socket();
//suggest to abandon and use new:udp_socket_bind_port_reuse()
DLLEXPORT int32_t udp_socket_bind_port(int32_t sockFd, int32_t port);
DLLEXPORT int32_t udp_socket_bind_port_reuse(int32_t sockFd, char *localIp, int32_t port, int32_t reuseaddrFlag);
DLLEXPORT int32_t udp_socket_read_msg(int32_t sockFd, char *buff, int32_t maxLen, char *outRemoteIp);
DLLEXPORT int32_t udp_socket_read_msg_all(int32_t sockFd, char *buff, int32_t maxLen, char *outRemoteIp, int32_t *outRemotePort);
DLLEXPORT int32_t udp_socket_send_msg(int32_t sockFd, char *remoteIp, int32_t remotePort, char *buff, int32_t maxLen);


DLLEXPORT int32_t close_connection(int32_t sockFd);
DLLEXPORT int32_t check_connection_and_timeout(int32_t sockFd, int32_t sec, int32_t ms);
DLLEXPORT int32_t check_connections_and_timeout(int32_t sockFds[], int32_t size, int32_t sec, int32_t ms);


#ifdef __cplusplus
}
#endif 


#endif
