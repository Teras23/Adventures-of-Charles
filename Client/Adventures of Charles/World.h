#ifndef WORLD_H
#define WORLD_H
#include <vector>
#include "Entity.h"

class World {
    //private
    static std::vector<Entity> entities;
public:
    static Draw();
};

#endif