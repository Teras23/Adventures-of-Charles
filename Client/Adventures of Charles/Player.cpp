#include "Player.h"
#include "Game.h"
#include "Input.h"

Player::Player() {
    texture = Game::textures["PlayerTexture"];
}

void Player::Draw() {
    Entity::Draw();
}

void Player::Update() {
    velocity.x = 0;
    velocity.y = 0;
    if(Input::WPressed) {
        velocity.y = -1 * speed * Game::deltaTime;
    }
    if(Input::SPressed) {
        velocity.y = 1 * speed * Game::deltaTime;
    }
    if(Input::DPressed) {
        velocity.x = 1 * speed * Game::deltaTime;
    }
    if(Input::APressed) {
        velocity.x = -1 * speed * Game::deltaTime;
    }
    position.x += velocity.x;
    position.y += velocity.y;
}