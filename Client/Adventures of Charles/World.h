#ifndef WORLD_H
#define WORLD_H
#include <vector>
#include "Entity.h"
#include "Tile.h"

class World {
private:
    
    static std::vector<Entity*> entities;
public:
    static std::vector<std::vector<Tile>> tiles;
    static void Init();
    static void Draw();
    static void Update();
    static void AddEnemy();
    static void RemoveLastEnemy();
    static Entity* GetPlayer();
};

#endif