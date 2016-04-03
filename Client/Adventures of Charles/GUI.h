#ifndef GUI_H
#define GUI_H
#include <SDL.h>
#include <SDL_ttf.h>

#include <string>
#include <vector>

#include "Util.h"
#include "GUIElement.h"
#include "GUIBox.h"
#include "GUIText.h"
#include "GUIButton.h"
#include "GUICheckbox.h"
#include "GUITextBox.h"

class GUI {
public:
    static std::vector<GUIElement*> elements;
    static void Init();
    static void DrawText(std::string, Vector2i);
    static void DrawBox(Vector2i, Vector2i);
    static void Draw();
};

#endif