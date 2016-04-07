#ifndef GUIBOX_H
#define GUIBOX_H
#include "GUIElement.h"

class GUIBox : public GUIElement {
public:
    static SDL_Texture* texture;

    Vector2i position;
    Vector2i size;

    GUIBox();
    GUIBox(Vector2i position, Vector2i size);
    void Draw();
};

#endif