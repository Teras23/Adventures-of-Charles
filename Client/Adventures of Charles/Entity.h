#ifndef ENTITY_H
#define ENTITY_H
#include <SDL.h>
#include "Util.h"

class Entity {
    Vector2f position;
    Vector2f velocity;
    float speed;
public:
    Entity();
    virtual void Draw();
    virtual void Update();
};

#endif