#ifndef ENTITY_H
#define ENTITY_H
#include <SDL.h>
#include "Util.h"
#include "Animation.h"

class Entity {
    Vector2f position;
    Vector2f velocity;
    float speed;
    SDL_Texture* texture;
    Animation anim;
public:
    int id;
    static int curID;
    Entity();
    virtual void Draw();
    virtual void Update();
};

#endif