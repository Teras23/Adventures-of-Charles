#pragma once;

#include <gl/glew.h>
#include <string>
#include "Utility/Utility.h"

namespace Eucolus
{
	class Shader
	{
	public:
		Shader();
		Shader(std::string shaderPath);
		~Shader();

		void Bind(Vector2f);

	private:
		GLuint m_vertexShader;
		GLuint m_fragmentShader;

		GLuint m_program;

		GLuint projMatrixLocation;
		GLuint modelMatrixLocation;

		bool Compile(std::string shaderSource, GLuint shader);
	};
}
