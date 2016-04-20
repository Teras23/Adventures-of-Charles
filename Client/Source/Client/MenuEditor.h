#ifndef MENUEDITOR_H
#define MENUEDITOR_H
#include <vector>

#include "../Shared/Util.h"

#include "GUIElement.h"
#include "GUIBox.h"
#include "GUIText.h"
#include "GUIButton.h"
#include "GUICheckbox.h"
#include "GUITextBox.h"
#include "GUITexture.h"

class MenuEditor {
private:
    static bool isVisible;
    static std::vector<GUIElement*> elements;
public:
    static int selectedTile;
    static int selectedLayer;

    static void SetVisibility(bool visibility);
    static void Init();
    static void Update();

    static void NextTile();
    static void PrevTile();

    static void NextLayer();
    static void PrevLayer();

    static void EditTile(Vector2i tile);
};

#endif