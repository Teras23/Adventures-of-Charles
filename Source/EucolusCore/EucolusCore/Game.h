#pragma once

#include "Renderer/Renderer.h"
#include "Window.h"
#include "GameState.h"
#include "GUI/GUI.h"

#include <memory>

namespace Eucolus
{
	class Game
	{
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

		static std::shared_ptr<Game> GetGame();

	private:
		bool m_isRunning;
		static std::shared_ptr<Game> _gameSingleton;
	};
}
