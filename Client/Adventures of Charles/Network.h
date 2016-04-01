#ifndef NETWORK_H
#define NETWORK_H

class Network {
    static SDLNet_SocketSet server;
    static TCPsocket connection;
    static char buffer[1028];
    static int networkID;
public:
    static void Connect(std::string, int);
    static void Disconnect();
    static void SendMessage();
    static void ReceiveMessage();
};

#endif