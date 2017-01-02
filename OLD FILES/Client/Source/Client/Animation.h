#ifndef ANIMATION_H
#define ANIMATION_H
#include <SDL.h>

class Animation {
    int currentTick;
    int currentFrame;
    int ticksPerFrame;
public:
    Animation();
    void IncrementTick();
    SDL_Texture* GetCurrentFrameTexture();
};

#endif