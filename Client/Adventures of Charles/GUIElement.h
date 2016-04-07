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

    GUIElement();
    void AddElement(GUIElement* element);
    virtual void Draw();

    virtual void SetText(std::string text);
    virtual std::string GetText();

    void SetName(std::string name);
    std::string GetName();
};

#endif