#ifndef GUITEXTBOX_H
#define GUITEXTBOX_H
#include "GUIElement.h"

class GUITextBox : public GUIElement {
public:
    static SDL_Texture* texture;

    std::string text;
    Vector2i position;
    Vector2i size;

    GUITextBox();
    GUITextBox(std::string text, Vector2i position, Vector2i size);
    void Draw();
};

#endif