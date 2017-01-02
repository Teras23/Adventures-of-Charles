#include "Client.h"
#include <iostream>

Client::Client() {

}

Client::Client(TCPsocket s, int t, int i)
{
    socket = s;
    timeout = t;
    id = i;
}

void Client::SendTCPMessage(char* msg) {
    int len = SDLNet_TCP_Send(socket, msg, strlen(msg) + 1);
    if(strlen(msg) + 1 != len) {
        //Could not send whole message (is client disconnected?)
    }
}