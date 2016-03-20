#ifndef ENTITY_H
#define ENTITY_H
#include <SDL.h>
#include "Util.h"

class Entity {
    Vector2 position;
    Vector2 velocity;
public:
    Entity();
    virtual void Draw();
    virtual void Update();
};

#endif