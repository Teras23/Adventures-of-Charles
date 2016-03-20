#ifndef WORLD_H
#define WORLD_H
#include <vector>
#include "Entity.h"

class World {
    static std::vector<Entity*> entities;
public:
    static void Init();
    static void Draw();
    static void Update();
    static Entity* GetPlayer();
};

#endif