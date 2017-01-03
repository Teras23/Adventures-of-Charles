#pragma once


#include <memory>

/*extern "C" {
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
}*/
#include <lua.hpp>

namespace Eucolus
{
	class LuaManager
	{
	public:
		LuaManager();
		~LuaManager();

		bool Init();
		void Update();
		bool Quit();

	private:
		lua_State* m_L;
	};
}
