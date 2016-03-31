#ifndef CLIENT_H
#define CLIENT_H
#include <SDL_net.h>
#include <string>

class Client {
public:
    TCPsocket socket;
    int timeout;
    int id;

    inline bool operator==(const Client& left) {
        if(id == left.id) {
            return true;
        }
        return false;
    }

    Client();
    Client(TCPsocket, int, int);
    void SendTCPMessage(char*);
};

#endif
