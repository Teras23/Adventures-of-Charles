#include "Client.h"

Client::Client(TCPsocket s, int t, int i)
{
    socket = s;
    timeout = t;
    id = i;
}

void Client::SendTCPMessage(char* msg) {
    SDLNet_TCP_Send(socket, msg, strlen(msg) + 1);
}