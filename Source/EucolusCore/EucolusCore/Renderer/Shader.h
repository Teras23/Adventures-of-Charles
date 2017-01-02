#pragma once;

#include <gl/glew.h>
#include <string>

namespace Eucolus
{
	class Shader
	{
	public:
		Shader();
		Shader(std::string shaderPath);
		~Shader();

		void Bind();
		bool Compile(std::string shaderSource, GLuint shader);

	private:
		GLuint m_vertexShader;
		GLuint m_fragmentShader;

		GLuint m_program;

		GLuint projMatrixLocation;
		GLuint modelMatrixLocation;
	};
}
