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
std::vector<Client> Server::clients = std::vector<Client>();
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
        return -1;
    }

    sockets = SDLNet_AllocSocketSet(maxPlayers);
    server = SDLNet_TCP_Open(&ipAddress);

    std::cout << "Server initialized on port " << SDLNet_Read16(&ipAddress.port) << std::endl;

    clients = std::vector<Client>();

    running = true;
    Server::Loop();
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
        //If established connection
        if(tcpSocket != NULL) {
            //If server not full
            if(playerAmount < maxPlayers) {
                std::cout << "New Connection: " << GetIPFromSocket(tcpSocket) << std::endl;
                SDLNet_TCP_AddSocket(sockets, tcpSocket);
                sprintf(buffer, "0 %d \n", currentID);                      //Make new connection message
                SDLNet_TCP_Send(tcpSocket, buffer, strlen(buffer) + 1);     //Send message
                clients.push_back(Client(tcpSocket, SDL_GetTicks(), currentID));
                playerAmount++;
                currentID++;
            }
            else {
                sprintf(buffer, "3 \n");
                SDLNet_TCP_Send(tcpSocket, buffer, strlen(buffer) + 1);
            }
        }

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
        
        SDL_Delay(1);
    }
    Quit();
}

void Server::DisconnectTCPClient(Client client) {
    std::cout << "Disconnected: " << GetIPFromSocket(client.socket) << std::endl;
    SDLNet_TCP_DelSocket(sockets, client.socket);
    SDLNet_TCP_Close(client.socket);
    clients.erase(find(clients.begin(), clients.end(), client));
    playerAmount--;
}

std::string Server::GetIPFromSocket(TCPsocket sock) {
    IPaddress ipraw = *SDLNet_TCP_GetPeerAddress(sock);
    Uint8* ip = (Uint8*)&ipraw.host;
    return std::to_string(ip[0]) + "." + std::to_string(ip[1]) + "." + std::to_string(ip[2]) + "." + std::to_string(ip[3]);
}

//FUCKING BORKEN DON'T USE 
std::string Server::GetPortFromSocket(TCPsocket sock) {
    IPaddress ipraw = *SDLNet_TCP_GetPeerAddress(sock);
    std::cout << SDLNet_Read16(&ipraw.port);
    return std::to_string(SDLNet_Read16(&ipraw.port));
}