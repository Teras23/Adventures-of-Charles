#ifndef PLAYER_H
#define PLAYER_H
#include "Entity.h"

class Player : Entity {
    string name;
public:
    Player();
    Draw();
    Update();
};

#endif