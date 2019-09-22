#include "Socks.h"


int main() {

    Socks Client;
    string tmp;
    tmp=Client.serversRequest(1,"123");
    cout<<tmp;
}