#ifndef GUIBUTTON_H
#define GUIBUTTON_H
#include "GUIElement.h"

class GUIButton : public GUIElement {
public:
    static TTF_Font* font;
    std::string text;
    bool pressed;
    Vector2i position;
    Vector2i size;

    GUIButton();
    GUIButton(std::string text, Vector2i position, Vector2i size);
    void Draw();
};

#endif