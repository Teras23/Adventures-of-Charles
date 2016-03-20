#ifndef CLIENT_H
#define CLIENT_H
#include <SDL_net.h>

class Client {
public:
    TCPsocket socket;
    int timeout;
    int id;

    Client(TCPsocket, int, int);
};

#endif
