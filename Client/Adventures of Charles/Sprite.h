#ifndef SPRITE_H
#define SPRITE_H
#include <SDL.h>
#include "Util.h"
#include "Animation.h"

class Sprite {
public:
    SDL_Texture* texture;
    Animation animation;

    Sprite();
    void Draw(Vector2f position, Vector2f texturePosition);
};

#endif