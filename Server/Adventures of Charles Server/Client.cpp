#include "Client.h"

Client::Client(TCPsocket s, int t, int i)
{
    socket = s;
    timeout = t;
    id = i;
}