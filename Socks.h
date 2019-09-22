//
// Created by fffei on 2019/9/19.
//

#ifndef SOCKET_SOCKS_H
#define SOCKET_SOCKS_H

#include "winsock2.h"
#include "iostream"
using namespace std;

class Socks {
protected:
    WSADATA data;
    SOCKET client;
    sockaddr_in ServerAdder;
    char Buffer[MAXBYTE];

public:
    Socks();
    ~Socks();
    string serversRequest(int type,const char* data);
};


#endif //SOCKET_SOCKS_H
