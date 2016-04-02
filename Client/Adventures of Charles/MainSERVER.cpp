#include <iostream>
#include <SDL.h>
#include "Server.h"

int main(int argc, char* argv[]) {
    if(Server::Init() == 0) {
        Server::Loop();
    }
    return 0;
}