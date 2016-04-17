#ifndef WORLD_H
#define WORLD_H
#include <vector>
#include "Entity.h"
#include "Tile.h"
#include "MapLayer.h"

class World {
private:
    static std::vector<Entity*> entities;
public:
    static std::vector<MapLayer> layers;

    static void Init();
    static void Draw();
    static void Update();
    static void AddEnemy();
    static void RemoveLastEnemy();
    static Entity* GetPlayer();
    static Vector2i GetGameMousePosition(Vector2i windowMousePosition);
};

#endif