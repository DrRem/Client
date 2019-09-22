//
// Created by fffei on 2019/9/19.
//

#include <inaddr.h>
#include "Socks.h"

Socks::Socks() {
    WSAStartup(MAKEWORD(2,2),&data);
    memset(&this->ServerAdder,0, sizeof(this->ServerAdder));        //初始化地址结构体
    this->client=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    this->ServerAdder.sin_family=PF_INET;       //设置服务器地址
    this->ServerAdder.sin_addr.S_un.S_addr=inet_addr("127.0.0.1");
    this->ServerAdder.sin_port=htons(8848);
    connect(this->client,(SOCKADDR*)&this->ServerAdder, sizeof(SOCKADDR));
}

Socks::~Socks() {
    closesocket(this->client);
    WSACleanup();
}

string Socks::serversRequest(int type, const char *data) {
    ZeroMemory(this->Buffer,MAXBYTE);       //清空buffer
    string tmp=to_string(type)+data;
    const char *p=tmp.data();
    send(this->client,p,MAXBYTE,0);         //发送请求
    recv(this->client,this->Buffer,MAXBYTE,0);          //接收回复
    tmp=this->Buffer;
    return tmp;
}
