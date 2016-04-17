#ifndef ENTITY_H
#define ENTITY_H
#include <SDL.h>
#include "Util.h"
#include "Animation.h"

class Entity {
protected:
    Vector2f position;
    Vector2f velocity;
    int health;
    float speed;
    SDL_Texture* texture;
    Animation anim;
public:
    int id;
    static int curID;
    Entity();

    virtual void Draw();
    virtual void Update();

    Vector2f GetPosition();
    void SetPosition(Vector2f position);
};

#endif