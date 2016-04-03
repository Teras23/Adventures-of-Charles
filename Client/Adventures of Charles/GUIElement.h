#ifndef GUIELEMENT_H
#define GUIELEMENT_H
#include <SDL.h>
#include "Util.h"
#include "Game.h"

class GUIElement {
public:
    SDL_Texture* texture;
    SDL_Rect* rect;
    bool visible;
    GUIElement();
    GUIElement(SDL_Texture*, SDL_Rect*);
    virtual void Draw();
};

#endif