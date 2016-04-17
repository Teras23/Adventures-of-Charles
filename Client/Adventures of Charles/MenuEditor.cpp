#include "MenuEditor.h"
#include "World.h"

int MenuEditor::selectedTile = 0;
int MenuEditor::selectedLayer = 0;
bool MenuEditor::isVisible = true;
std::vector<GUIElement*> MenuEditor::elements;

//
//General Functions
//
void MenuEditor::Init() {
#if DEBUG
    GUIBox* box = new GUIBox(Vector2i(0, Game::screenSize.y - 204), Vector2i(300, 100));
    elements.push_back(box);

    GUITexture* texture = new GUITexture(Vector2i(box->GetPosition().x + 70, box->GetPosition().y + 10), Vector2i(32, 32), Game::textures["Tilemap"]);
    elements.push_back(texture);

    GUIText* layer = new GUIText("0", Vector2i(box->GetPosition().x + 80, box->GetPosition().y + 50));
    elements.push_back(layer);

    GUIButton* prevTexture = new GUIButton("Prev", Vector2i(box->GetPosition().x + 10, box->GetPosition().y + 10), Vector2i(50, 20));
    prevTexture->SetName("PrevTexture");
    elements.push_back(prevTexture);

    GUIButton* nextTexture = new GUIButton("Next", Vector2i(box->GetPosition().x + 110, box->GetPosition().y + 10), Vector2i(50, 20));
    nextTexture->SetName("NextTexture");
    elements.push_back(nextTexture);

    GUIButton* prevLayer = new GUIButton("Prev", Vector2i(box->GetPosition().x + 10, box->GetPosition().y + 50), Vector2i(50, 20));
    prevLayer->SetName("PrevLayer");
    elements.push_back(prevLayer);

    GUIButton* nextLayer = new GUIButton("Next", Vector2i(box->GetPosition().x + 110, box->GetPosition().y + 50), Vector2i(50, 20));
    nextLayer->SetName("NextLayer");
    elements.push_back(nextLayer);
    
    SetVisibility(isVisible);
#endif
}

void MenuEditor::Update() {
#if DEBUG
    elements[1]->source->x = selectedTile % 8 * 32;
    elements[1]->source->y = selectedTile / 8 * 32;
    elements[2]->SetText(std::to_string(selectedLayer));
#endif
}

void MenuEditor::SetVisibility(bool vis) {
    isVisible = vis;

    for(int i = 0; i < elements.size(); i++) {
        elements[i]->SetVisibility(vis);
    }
}

#define TILESETTILES 63

void MenuEditor::NextTile() {
    if(selectedTile + 1 > TILESETTILES) {
        selectedTile = 0;
    }
    else {
        selectedTile++;
    }
}

void MenuEditor::PrevTile() {
    if(selectedTile - 1 < 0) {
        selectedTile = TILESETTILES;
    }
    else {
        selectedTile--;
    }
}

void MenuEditor::NextLayer() {
    if(selectedLayer + 1 <= 4) {
        selectedLayer++;
    }
}

void MenuEditor::PrevLayer() {
    if(selectedLayer - 1 >= 0) {
        selectedLayer--;
    }
}