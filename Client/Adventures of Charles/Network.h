#ifndef NETWORK_H
#define NETWORK_H
#include <string>

class Network {
    static std::string name;
public:
    static void Connect(std::string);
    static void Disconnect();
    static void SendMessage();
};

#endif