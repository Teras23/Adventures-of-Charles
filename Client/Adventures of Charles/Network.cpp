#include <SDL_net.h>
#include <iostream>
#include "Network.h"
#include <string>

TCPsocket Network::connection;
SDLNet_SocketSet Network::server;
char Network::buffer[1028];

void Network::Connect(std::string serverIP, int port) {
    IPaddress ip;

    //Resolve host
    if(SDLNet_ResolveHost(&ip, serverIP.c_str(), port) == -1) {
        std::cout << "Error resolving to host " << SDLNet_GetError() << std::endl;
        return;
    }

    //Make connection
    std::cout << "Connecting to: " << serverIP << ":" << std::to_string(port) << std::endl;
    connection = SDLNet_TCP_Open(&ip);
    if(connection == NULL) {
        std::cout << "Error connection to server (Wrong IP or Server Down)" << std::endl;
        return;
    }
    else {
        server = SDLNet_AllocSocketSet(1);
        SDLNet_TCP_AddSocket(server, connection);
    }
    std::cout << "Connected to server!" << std::endl;
}

void Network::Disconnect() {
    SDLNet_TCP_Send(connection, "2 \n", 4);
    SDLNet_TCP_Close(connection);
    SDLNet_FreeSocketSet(server);
}

void Network::SendMessage() {
    
}

void Network::ReceiveMessage() {
    if(connection != NULL) {
        while(SDLNet_CheckSockets(server, 0) > 0 && SDLNet_SocketReady(connection)) {
            SDLNet_TCP_Recv(connection, buffer, 1024);
            std::cout << buffer << std::endl;
            std::cout << "NEED MESSAGE" << std::endl;
        }
    }
}