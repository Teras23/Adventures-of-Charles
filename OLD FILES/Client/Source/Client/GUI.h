#ifndef GUI_H
#define GUI_H
#include <SDL.h>
#include <SDL_ttf.h>

#include <string>
#include <vector>
#include <map>

#include "../Shared/Util.h"

#include "GUIElement.h"
#include "GUIBox.h"
#include "GUIText.h"
#include "GUIButton.h"
#include "GUICheckbox.h"
#include "GUITextBox.h"
#include "GUITexture.h"

class GUI {
private:
    static std::map<std::string, GUIElement*> elements;
    static std::vector<std::string> elementOrder;
    static GUIElement* clickedElement;
public:
    static void Init();
    static void Draw();
    static void Update();

    static GUIElement* GetElementUnderMouse();

    static void RenameElement(std::string oldName, std::string newName, GUIElement* element);
    static void AddElement(GUIElement* element);
    static void RemoveElement(std::string name);
    static GUIElement* GetElement(std::string name);

    static bool MouseEvent(SDL_Event evt);
};

#endif