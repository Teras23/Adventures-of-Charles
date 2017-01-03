#include "Game/GameStatePlaying.h"

namespace Eucolus
{
	GameStatePlaying::GameStatePlaying()
	{
		m_isPaused = false;
	}

	GameStatePlaying::~GameStatePlaying()
	{
	}

	bool GameStatePlaying::Init()
	{
		return false;
	}

	void GameStatePlaying::Update()
	{
	}

	bool GameStatePlaying::Quit()
	{
		return false;
	}
}
