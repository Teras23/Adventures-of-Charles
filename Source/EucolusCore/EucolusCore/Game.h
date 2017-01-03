#pragma once

#include <memory>

#include "Game/GameState.h"
#include "Renderer/Renderer.h"
#include "Game/Window.h"
#include "GUI/GUI.h"
#include "World/World.h"

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
		std::shared_ptr<World> m_world;

	private:
		bool m_isRunning;
	};
}
