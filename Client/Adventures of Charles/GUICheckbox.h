#ifndef GUICHECKBOX_H
#define GUICHECKBOX_H
#include "GUIElement.h"

class GUICheckbox : public GUIElement {
public:
    Vector2i position;
    bool checked;

    GUICheckbox();
    GUICheckbox(std::string, Vector2i);
    void Draw();
};

#endif