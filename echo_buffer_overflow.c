#include <WINSOCK2.H>
#include <stdio.h>
#include <string>
using namespace std;
#pragma comment(lib, "ws2_32.lib")
void echo(SOCKET sclient, char * msg)
{
    char buff[50] = {0};
    strcpy(buff, msg);//溢出
    send(sclient, buff, strlen(buff), 0);
}
int main()
{
    char * buff = new char[1024];
    memset(buff, 0, 1024);
    _snprintf(buff, 255, "%x", (unsigned)buff);
    WSADATA wsaData;
    if(WSAStartup(MAKEWORD(1,1),&wsaData)!=0)
    {
        printf("WSAStartup wrong\n");
        exit(0);
    }
    SOCKET locals;
    STARTUPINFO si;
    PROCESS_INFORMATION  pi;
    struct sockaddr_in   s_sin;
    locals = WSASocket(AF_INET, SOCK_STREAM, 0, NULL, NULL, NULL);
    s_sin.sin_family= AF_INET;
    s_sin.sin_port= htons(4444);
    s_sin.sin_addr.s_addr= htonl(INADDR_ANY);
    if(SOCKET_ERROR == bind(locals, (sockaddr*)&s_sin, sizeof(s_sin)))
    {
        printf("bind wrong.");
        exit(0);
    }
    listen(locals,2);
    SOCKET sClient = accept(locals, NULL, NULL);
    if(sClient == INVALID_SOCKET)
    {
        printf("accept wrong.");
        exit(0);
    }
    send(sClient, buff, strlen(buff), 0);
    memset(buff, 0, 1024);
    while (recv(sClient, buff, 1024, 0) > 0)
    {
        echo(sClient, buff);
    }
    return 0;
}

