//
// Created by fffei on 2019/9/19.
//

#include <inaddr.h>
#include "Socks.h"

Socks::Socks() {
    memset(&this->ServerAdder,0, sizeof(this->ServerAdder));
    this->ServerAdder.sin_family=PF_INET;
    this->ServerAdder.sin_addr.S_un.S_addr=inet_addr("127.0.0.1");
    this->ServerAdder.sin_port=htons(8848);
    connect(this->client,(SOCKADDR*)&this->ServerAdder, sizeof(SOCKADDR));
}

Socks::~Socks() {
    closesocket(this->client);
}

string Socks::serversRequest(int type, const char *data) {
    return std::__cxx11::string();
}
