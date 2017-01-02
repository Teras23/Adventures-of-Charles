#ifndef SERVER_H
#define SERVER_H
#include <SDL_net.h>
#include <vector>
#include "Client.h"
#include "../Shared/Util.h"

class Server {
    static int currentID;
    static bool running;
    static SDL_Event sdlEvent;

    static int maxPlayers;
    static int playerAmount;
    static int port;

    static SDLNet_SocketSet sockets;
    static TCPsocket server;
    static char buffer[1028];

    static std::vector<Client> clients;
    static int timeoutTime;

public:
    static int Init();
    static void Loop();
    static void Quit();
    static void DisconnectTCPClient(Client);

    static std::string GetIPFromSocket(TCPsocket);
    static std::string GetPortFromSocket(TCPsocket);
};

#endif
