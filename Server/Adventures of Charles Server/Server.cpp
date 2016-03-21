#include "Server.h"
#include <iostream>
#include <cstring>

int Server::currentID;
bool Server::running;
SDL_Event Server::sdlEvent;
int Server::maxPlayers;
int Server::playerAmount;
int Server::port;
SDLNet_SocketSet Server::sockets;
TCPsocket Server::server;
char Server::buffer[1028];
std::vector<Client> Server::clients;
int Server::timeoutTime;

/*
0 - new connection
1 - tell everyone
2 - tell server
3 - disconnect
4 - timout
*/

int Server::Init() {
    maxPlayers = 32;
    port = 1234;
    timeoutTime = 5000;
    if(SDLNet_Init() < 0) {
        std::cout << "Could not init SDL_net " << SDLNet_GetError() << std::endl;
        return -1;
    }
    IPaddress ipAddress;
    if(SDLNet_ResolveHost(&ipAddress, NULL, port)) {
        std::cout << "Could not resolve host " << SDLNet_GetError() << std::endl;
    }

    sockets = SDLNet_AllocSocketSet(maxPlayers);
    server = SDLNet_TCP_Open(&ipAddress);

    std::cout << "Server initialized" << std::endl;
    return 0;
}

void Server::Quit() {
    //Close connections and
}

void Server::Loop() {
    while(running) {
        while(SDL_PollEvent(&sdlEvent)) {
            if(sdlEvent.type == SDL_QUIT) {
                running = false;
            }
        }

        /*for(if under 60 ticks) {
        Calculate()
        SendData()
        }*/

        //New connection
        TCPsocket tcpSocket = SDLNet_TCP_Accept(server);
        if(playerAmount < maxPlayers) {
            SDLNet_TCP_AddSocket(sockets, tcpSocket);
            sprintf(buffer, "0 %d \n", currentID);
            playerAmount++;
            currentID++;
        }
        else {
            sprintf(buffer, "3 \n");
        }

        SDLNet_TCP_Send(tcpSocket, buffer, strlen(buffer) + 1);
        
        //Disconnect player if timed out
        for(int i = 0; i < clients.size(); i++) {
            if(SDL_GetTicks() - clients[i].timeout > timeoutTime) {
                //Tell everyone who disconnected
                for(int j = 0; j < clients.size(); j++) {
                    //If not trying to send to client who sent the message
                    sprintf(buffer, "4 %d \n", clients[i].id);
                    clients[j].SendTCPMessage(buffer);
                    //SDLNet_TCP_Send(clients[j].socket, buffer, strlen(buffer) + 1);
                }
                //Remove from vectors and close connection
                DisconnectTCPClient(clients[i]);
            }
        }

        //Receive Data
        while(SDLNet_CheckSockets(sockets, 0) > 0) {
            for(int i = 0; i < clients.size(); i++) {
                if(SDLNet_SocketReady(clients[i].socket)) {
                    clients[i].timeout = SDL_GetTicks();
                    SDLNet_TCP_Recv(clients[i].socket, buffer, 1024);
                    int msgNum;
                    sscanf(buffer, "%d ", &msgNum);

                    //Send to everyone
                    if(msgNum == 1) {
                        //Send message to all clients
                        for(int j = 0; j < clients.size(); j++) {
                            //If not trying to send to client who sent the message
                            if(j != i) {
                                clients[j].SendTCPMessage(buffer);
                                //SDLNet_TCP_Send(clients[j].socket, buffer, strlen(buffer) + 1);
                            }
                        }
                    }
                    //Disconnect
                    else if(msgNum == 3) {
                        //Tell everyone you disconnected
                        for(int j = 0; j < clients.size(); j++) {
                            //If not trying to send to client who sent the message
                            if(j != i) {
                                clients[j].SendTCPMessage(buffer);
                                //SDLNet_TCP_Send(clients[j].socket, buffer, strlen(buffer) + 1);
                            }
                        }
                        //Remove from vectors and close connection
                        DisconnectTCPClient(clients[i]);
                    }
                    //Something to tell the server
                    else if(msgNum == 2) {
                        //Hit something?
                    }
                }
            }
        }
    }
    Quit();
}

void Server::DisconnectTCPClient(Client client) {
    SDLNet_TCP_DelSocket(sockets, client.socket);
    SDLNet_TCP_Close(client.socket);
    clients.erase(find(clients.begin(), clients.end(), client));
    playerAmount--;
}