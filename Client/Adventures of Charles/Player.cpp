#include "Player.h"
#include "Game.h"
#include "Input.h"

Player::Player() {
    type = ENTITY_PLAYER;
    sprite.texture = Game::textures["PlayerTexture"];
    position = Vector2f(Game::screenSize.x / 2 - TILESIZE / 2, Game::screenSize.y / 2 - TILESIZE / 2);
    position = Vector2f(0, 0);
    health = 100;
    speed = 20.0f;
}

void Player::Draw() {
    sprite.Draw(Vector2f(Game::screenSize.x / 2 - TILESIZE / 2, Game::screenSize.y / 2 - TILESIZE / 2), Vector2f());
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