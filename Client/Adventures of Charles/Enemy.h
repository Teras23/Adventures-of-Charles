#ifndef ENEMY_H
#define ENEMY_H
#include "Entity.h"
#include "Game.h"

class EnemyBase : public Entity {
    float attackTime;
    float currentAttackTime;
    bool isAttacking;
    int health;
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
};

#endif