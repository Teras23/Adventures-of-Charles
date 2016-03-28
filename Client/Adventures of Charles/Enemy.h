#ifndef ENEMY_H
#define ENEMY_H
#include "Entity.h"

class EnemyBase : Entity {
    float attackTime;
    float currentAttackTime;
    bool isAttacking;
    int health;
};

class EnemySpider : EnemyBase {

};

#endif