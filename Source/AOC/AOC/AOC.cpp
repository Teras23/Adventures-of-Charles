#include <iostream>
#include "EucolusCore/Game.h"
#include "EucolusCore/Utility/Utility.h"
#include "EucolusCore/Lua/EucolusLua.h"

int main(int argc, char* args[])
{
	auto lm = Eucolus::LuaManager();
	auto game = Eucolus::Game::GetGame();

	if (!game->Init("AOC", Eucolus::Vector2f(SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED), Eucolus::Vector2f(300, 300)))
	{
		game->Run();
	}
	return 0;
}
