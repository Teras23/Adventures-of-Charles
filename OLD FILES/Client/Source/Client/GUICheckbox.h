#ifndef GUICHECKBOX_H
#define GUICHECKBOX_H
#include "GUIElement.h"

class GUICheckbox : public GUIElement {
public:
    Vector2i position;
    bool checked;

    GUICheckbox();
    GUICheckbox(bool checked, Vector2i position);
    void Draw();
};

#endif