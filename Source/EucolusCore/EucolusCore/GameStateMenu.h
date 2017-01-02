#ifndef GAMESTATEMENU_H
#define GAMESTATEMENU_H
#include "GameState.h"

namespace Eucolus {
    class GameStateMenu : GameState {
    public:
        GameStateMenu();
        ~GameStateMenu();

        bool Init();
        void Update();
        bool Quit();

    private:

    };
}

#endif