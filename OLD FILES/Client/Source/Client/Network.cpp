#include <SDL_net.h>
#include <iostream>
#include <string>

#include "Network.h"
#include "../Shared/Util.h"

TCPsocket Network::connection;
SDLNet_SocketSet Network::server;
char Network::buffer[1028];
int Network::networkID = -1;
bool Network::connected = false;

void Network::Connect(std::string serverIP, int port) {
    IPaddress ip;

    Console::Print("Connecting to: " + serverIP + ":" + std::to_string(port));

    //Resolve host
    if(SDLNet_ResolveHost(&ip, serverIP.c_str(), port) == -1) {
        Console::PrintError("Error resolving to host", SDLNet_GetError());
        return;
    }

    //Make connection
    connection = SDLNet_TCP_Open(&ip);
    if(connection == NULL) {
        Console::PrintError("Error connection to server (Wrong IP or Server Down)", SDLNet_GetError());
        return;
    }
    else {
        server = SDLNet_AllocSocketSet(1);
        SDLNet_TCP_AddSocket(server, connection);
    }

    connected = true;
    Console::Print("Connected to server!");
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
        Console::Print("Could not send message correctly");
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
                Console::Print("Network ID: " + std::to_string(networkID));
                break;
            case 1:     //Some game data only to this client
                //
                break;
            case 2:     //Some game data to every client
                //
                break;
            case 3:     //Server is full
                Console::Print("The server you are trying to connect to is full");
                Disconnect();
                break;
            case 4:     //Someone Timed out
                Console::Print("Timed out from server");
                Disconnect();
                break;
            case 5:     //Someone disconnected
                break;
            }
        }
    }
}