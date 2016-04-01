//#include "Util.h"
#include <iostream>
#include <SDL.h>
#include "Server.h"

#define SERVER true

int main(int argc, char* argv[]) {
    //Console::Print("test");
    //Vector2f vec;
    if(Server::Init() == 0) {
        Server::Loop();
    }
    return 0;
}