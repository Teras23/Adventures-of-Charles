#include "Enemy.h"

EnemyBase::EnemyBase() {
    
}

EnemySpider::EnemySpider() {

}

EnemySolder::EnemySolder() {
    EnemyBase::texture = Game::textures["SolderTexture"];
}