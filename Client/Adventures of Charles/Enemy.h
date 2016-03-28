#ifndef ENEMY_H
#define ENEMY_H
#include "Entity.h"

class EnemyBase : public Entity {
    float attackTime;
    float currentAttackTime;
    bool isAttacking;
    int health;
public:
    EnemyBase();
};

class EnemySpider : EnemyBase {

};

class EnemySolder : EnemyBase {

};

#endif