#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <string>
#include <fstream>

namespace Eucolus {
    class FileSystem {
    public:
		static std::string LoadShader(std::string path);

    };
}

#endif