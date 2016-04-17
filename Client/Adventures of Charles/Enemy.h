#ifndef ENEMY_H
#define ENEMY_H
#include "Entity.h"
#include "Game.h"

class EnemyBase : public Entity {
    float attackTime;
    float currentAttackTime;
    bool isAttacking;
public:
    EnemyBase();
};

class EnemySpider : public EnemyBase {
public:
    EnemySpider();
};

class EnemySolder : public EnemyBase {
public:
    EnemySolder();
    float path;
    Vector2f orgPos;
    void Update();
};

#endif