#ifndef GUI_H
#define GUI_H
#include <SDL.h>
#include <SDL_ttf.h>

#include <string>
#include <vector>
#include <map>

#include "Util.h"
#include "GUIElement.h"
#include "GUIBox.h"
#include "GUIText.h"
#include "GUIButton.h"
#include "GUICheckbox.h"
#include "GUITextBox.h"

class GUI {
private:
    static std::map<std::string, GUIElement*> elements;
public:
    static void Init();
    static void Draw();

    static void AddElement(GUIElement* element);
    static void RemoveElement(std::string name);
    static GUIElement* GetElement(std::string name);

    static bool MouseEvent(SDL_Event evt);
};

#endif