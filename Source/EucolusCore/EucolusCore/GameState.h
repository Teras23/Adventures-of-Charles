#ifndef GAMESTATE_H
#define GAMESTATE_H

namespace Eucolus {
    class GameState {
    public:
        GameState();
        ~GameState();

        virtual bool Init();
        virtual void Update();
        virtual bool Quit();

    private:

    };
}

#endif