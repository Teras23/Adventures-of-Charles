#include "Player.h"
#include "Game.h"
#include "Input.h"

Player::Player() {
    texture = Game::textures["PlayerTexture"];
    position = Vector2f(Game::screenSize.x / 2 - TILESIZE / 2, Game::screenSize.y / 2 - TILESIZE / 2);
    position = Vector2f(0, 0);
    health = 100;
    speed = 20.0f;
}

void Player::Draw() {
    if(texture == NULL) {
        Console::Print("Missing texture!");
    }
    else {
        SDL_Rect* dest = new SDL_Rect();
        //dest->x = position.x + velocity.x * Game::interpolation;
        //dest->y = position.y + velocity.y * Game::interpolation;

        //Center the player on the screen
        dest->x = Game::screenSize.x / 2 - TILESIZE / 2;
        dest->y = Game::screenSize.y / 2 - TILESIZE / 2;
        dest->w = TILESIZE;
        dest->h = TILESIZE;

        SDL_Rect* source = new SDL_Rect();
        source->x = 0;
        source->y = 0;
        source->w = TILESIZE;
        source->h = TILESIZE;
        SDL_RenderCopy(Game::renderer, texture, source, dest);
        delete dest;
        delete source;
    }
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