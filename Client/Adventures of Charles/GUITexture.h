#ifndef GUITEXTURE_H
#define GUITEXTURE_H
#include "GUIElement.h"

class GUITexture : public GUIElement {
public:
    SDL_Texture* texture;

    GUITexture();
    GUITexture(Vector2i position, Vector2i size, SDL_Texture* texture);
    void Draw();
};

#endif