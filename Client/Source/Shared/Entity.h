#ifndef ENTITY_H
#define ENTITY_H
#include <SDL.h>
#include "../Shared/Util.h"
#include "../Client/Sprite.h"
#include "../Client/Animation.h"

enum EntityType {
    ENTITY_UNDEFINED,
    ENTITY_PLAYER,
    ENTITY_ENEMY_UNDEFINED,
    ENTITY_ENEMY_SOLDER,
    ENTITY_ENEMY_SPIDER
};

class Entity {
protected:
    Vector2f position;
    Vector2f velocity;

    int maxHealth;
    int health;

    float speed;

    bool isAlive;
    bool isVisible;
    bool isStatic;
    bool isCollidable;

    Sprite sprite;
    Rect collider;

    int id;
    static int curId;
    EntityType type;
public:
    Entity();

    virtual void Use();
    virtual void Draw();
    virtual void Update();

    EntityType GetType();

    Vector2f GetPosition();
    void SetPosition(Vector2f position);

    Rect GetCollider();
};

#endif