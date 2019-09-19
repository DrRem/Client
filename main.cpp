#include "Socks.h"

using namespace std;

int main() {
    WSADATA data;
    SOCKET TCPLinker;
    SOCKET client;
    SOCKADDR clientAdder;
    sockaddr_in address{};
    int adderLen= sizeof(SOCKADDR);
    WSAStartup(MAKEWORD(2,2),&data);
    TCPLinker=socket(AF_INET,SOCK_STREAM,0);
    memset(&address,0, sizeof(address));
    address.sin_family=PF_INET;
    address.sin_addr.S_un.S_addr=inet_addr("127.0.0.1");
    address.sin_port=htons(8888);
    bind(TCPLinker,(SOCKADDR*)&address, adderLen);


    listen(TCPLinker,20);
    client=accept(TCPLinker,(SOCKADDR*)&clientAdder,&adderLen);
    char *str="123";
    send(client,str,strlen(str)* sizeof(char),NULL);
    closesocket(TCPLinker);
    closesocket(client);
    WSACleanup();
    return 0;
}