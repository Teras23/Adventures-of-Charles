#include "Utility\Console.h"

#include <iostream>

namespace Eucolus {
	void Console::Print(std::string message) {
		std::cout << message << std::endl;
    }

	void Console::PrintError(std::string error) {
		std::cout << error << std::endl;
	}
}