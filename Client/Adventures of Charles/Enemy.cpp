#include "Enemy.h"

EnemyBase::EnemyBase() {
    
}




//
//Spider
//
EnemySpider::EnemySpider() {
    
}




//
//Solder
//
EnemySolder::EnemySolder() {
    EnemyBase::texture = Game::textures["SolderTexture"];
    health = 50;
    path = 0;
    orgPos = position;
    velocity = Vector2f(1, 0);
}

void EnemySolder::Update() {
    Console::Print(std::to_string(orgPos.x) + " " + std::to_string(position.x));
    
    if(position.x - orgPos.x  > 100) {
        velocity = Vector2f(-1, 0);
    }
    else if(position.x - orgPos.x < 0) {
        velocity = Vector2f(1, 0);
    }
    
    Entity::Update();
}