#ifndef GUIELEMENT_H
#define GUIELEMENT_H
#include <SDL.h>
#include "Util.h"
#include "Game.h"

class GUIElement {
private:
    std::string name;
protected:
    bool lastClickState;
    bool visible;
    bool clickable;
    bool clicked;
    Vector2i position;
    Vector2i size;
public:
    GUIElement();
    void AddElement(GUIElement* element);
    virtual void Draw();

    void Update();

    virtual void SetText(std::string text);
    virtual std::string GetText();

    bool IsPressed();
    void SetPressed(bool state);

    bool IsClickable();

    void SetName(std::string name);
    std::string GetName();

    Vector2i GetSize();
    Vector2i GetPosition();

    void OnHover();
    void OnClick();
};

#endif