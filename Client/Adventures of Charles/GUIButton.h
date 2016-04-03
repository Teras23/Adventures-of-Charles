#ifndef GUIBUTTON_H
#define GUIBUTTON_H
#include "GUIElement.h"

class GUIButton : public GUIElement {
public:
    bool pressed;
    Vector2i position;
    Vector2i size;

    GUIButton();
    GUIButton(std::string, Vector2i);
    GUIButton(std::string, Vector2i, Vector2i);
    void Draw();
};

#endif