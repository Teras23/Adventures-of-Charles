#ifndef GUIELEMENT_H
#define GUIELEMENT_H
#include <SDL.h>
#include "Util.h"
#include "Game.h"

class GUIElement {
private:
    std::string name;
public:
    bool visible;
    bool clickable;
    bool clicked;
    Vector2i position;
    Vector2i size;

    GUIElement();
    void AddElement(GUIElement* element);
    virtual void Draw();

    virtual void SetText(std::string text);
    virtual std::string GetText();

    void SetName(std::string name);
    std::string GetName();

    void OnHover();
    void OnClick();
};

#endif