#include <SDL_net.h>
#include <iostream>
#include "Network.h"
#include <string>

TCPsocket Network::connection;
SDLNet_SocketSet Network::server;
char Network::buffer[1028];
int Network::networkID = -1;
bool Network::connected = false;

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

    connected = true;
    std::cout << "Connected to server!" << std::endl;
}

void Network::Disconnect() {
    if(connected) {
        SendMessage("5 \n");
        SDLNet_TCP_Close(connection);
        SDLNet_FreeSocketSet(server);
        connected = false;
    }
}

void Network::SendMessage(std::string msg) {
    int len = SDLNet_TCP_Send(connection, msg.c_str(), msg.size());
    if(len != msg.size()) {
        std::cout << "Could not send message correctly" << std::endl;
    }
}

void Network::SendGameData() {

}

void Network::ReceiveMessage() {
    if(connection != NULL && connected) {
        while(SDLNet_CheckSockets(server, 0) > 0 && SDLNet_SocketReady(connection)) {
            SDLNet_TCP_Recv(connection, buffer, 1024);
            std::cout << buffer << std::endl;
            
            int msgNum;
            sscanf(buffer, "%d ", &msgNum);

            switch(msgNum)
            {
            case 0:     //Successful confirmation message from server with id
                
                sscanf(buffer, "%*d %d", &networkID);
                std::cout << "Network ID: " << networkID << std::endl;
                break;
            case 1:     //Some game data only to this client
                //
                break;
            case 2:     //Some game data to every client
                //
                break;
            case 3:     //Server is full
                std::cout << "The server you are trying to connect to is full" << std::endl;
                Disconnect();
                break;
            case 4:     //Someone Timed out
                std::cout << "Timed out from server" << std::endl;
                Disconnect();
                break;
            case 5:     //Someone disconnected
                break;
            }
        }
    }
}