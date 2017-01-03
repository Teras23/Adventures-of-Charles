#pragma once

#include <string>

namespace Eucolus
{
	class Console
	{
	public:
		static void Print(std::string message);
		static void PrintError(std::string error);
	};
}
