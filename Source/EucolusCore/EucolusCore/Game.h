#ifndef GAME_H
#define GAME_H
#include "Renderer/Renderer.h"
#include "Window.h"
#include "GameState.h"
#include "GUI/GUI.h"

#include <memory>

namespace Eucolus {
    class Game {
    public:
        Game();
        ~Game();

        bool Init(std::string windowName, Vector2f windowPosition, Vector2f windowSize);
		void Run();
        void Update();
        bool Quit();

		std::shared_ptr<GameState> m_gameState;
		std::shared_ptr<Renderer> m_renderer;
		std::shared_ptr<Window> m_window;

    private:
        bool m_isRunning;
    };
}

#endif