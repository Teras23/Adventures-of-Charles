#ifndef SERVER_H
#define SERVER_H
#include <SDL_net.h>

class Server {
    static int clientid;

public:
    static int Init();
    static void Start();
};

#endif
