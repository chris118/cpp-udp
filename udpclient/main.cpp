#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <zconf.h>

int main() {
    int sock = socket(AF_INET, SOCK_DGRAM, 0);//IPV4  SOCK_DGRAM 数据报套接字（UDP协议）
    if(sock < 0)
    {
        perror("socket\n");
        return 2;
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port= 8888;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    socklen_t len = sizeof(server_addr);
    char buf[1024];
    char* msg = "i'm client";
    while(1)
    {
        if (sendto(sock, msg, strlen(msg), 0, (struct sockaddr*)&server_addr, len) < 0 )
        {
            perror("send:");
            exit(3);
        }
        struct sockaddr_in tmp;
        len = sizeof(tmp);
        int ret = recvfrom(sock, buf, sizeof(buf)-1, 0, (struct sockaddr*)&tmp ,&len);
        if(ret > 0)
        {
            buf[ret] = 0;
            printf("server echo#:%s\n",buf);
            break;
        }
    }
    close(sock);
    return 0;
}