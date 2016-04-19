#include "Enemy.h"

EnemyBase::EnemyBase() {
    type = ENTITY_ENEMY_UNDEFINED;
}




//
//Spider
//
EnemySpider::EnemySpider() {
    type = ENTITY_ENEMY_SPIDER;
}




//
//Solder
//
EnemySolder::EnemySolder() {
    type = ENTITY_ENEMY_SOLDER;
    EnemyBase::sprite.texture = Game::textures["SolderTexture"];
    health = 50;
    path = 0;
    orgPos = position;
    velocity = Vector2f(1, 0);
}

void EnemySolder::Update() {
    if(position.x - orgPos.x  > 100) {
        velocity = Vector2f(-1, 0);
    }
    else if(position.x - orgPos.x < 0) {
        velocity = Vector2f(1, 0);
    }
    
    Entity::Update();
}