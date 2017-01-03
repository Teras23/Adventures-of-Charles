#include "Lua/EucolusLua.h"

#include "Utility/Utility.h"

#include <iostream>
#include <LuaBridge.h>
#include <fstream>

using namespace luabridge;

namespace Eucolus
{
	LuaManager::LuaManager()
	{
		m_L = luaL_newstate();

		luaL_dofile(m_L, "test.lua");
		luaL_openlibs(m_L);
		lua_pcall(m_L, 0, 0, 0);

		LuaRef s = getGlobal(m_L, "tests");

		std::cout << s.cast<std::string>();

		getGlobalNamespace(m_L)
			.beginNamespace("Console")
			.addFunction("Print", Console::Print)
			.endNamespace();

		LuaRef initFunction = getGlobal(m_L, "Init");
		initFunction();

		LuaRef renderFunction = getGlobal(m_L, "Render");

		std::cout << "LuaManager Initialized" << std::endl;
	}

	LuaManager::~LuaManager()
	{
	}

	bool LuaManager::Init()
	{
		return false;
	}

	void LuaManager::Update()
	{
	}

	bool LuaManager::Quit()
	{
		lua_close(m_L);
		return false;
	}
}
