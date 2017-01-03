#pragma once

#include "GameState.h"

namespace Eucolus
{
	class GameStatePlaying : GameState
	{
	public:
		GameStatePlaying();
		~GameStatePlaying();

		bool Init();
		void Update();
		bool Quit();

	private:
		bool m_isPaused;
	};
}
