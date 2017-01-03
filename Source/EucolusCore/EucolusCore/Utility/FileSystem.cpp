#include "Utility/FileSystem.h"
#include "Utility/Utility.h"	

namespace Eucolus
{
	std::string FileSystem::LoadShader(std::string path)
	{
		std::ifstream file(path);
		if (file.fail())
		{
			Console::PrintError("Could not load " + path);
			return "";
		}

		std::string contents = "";
		std::string line;

		while (std::getline(file, line))
		{
			contents += line + "\n";
		}

		file.close();
		return contents;
	}
}
