#include "Renderer\Shader.h"
#include "Utility\Utility.h"

#include <vector>

namespace Eucolus {
	Shader::Shader() {

	}

	Shader::Shader(std::string shaderPath) {
		m_program = glCreateProgram();

		m_vertexShader = glCreateShader(GL_VERTEX_SHADER);
		if(m_vertexShader == 0) {
			Console::PrintError("Could not create vertex shader");
		}

		m_fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		if(m_fragmentShader == 0) {
			Console::PrintError("Could not create fragment shader");
		}

		Compile(FileSystem::LoadShader(shaderPath + ".vert"), m_vertexShader);
		Compile(FileSystem::LoadShader(shaderPath + ".frag"), m_fragmentShader);

		glBindAttribLocation(m_program, 0, "inVertexPosition");
		glBindAttribLocation(m_program, 1, "inColor");
		glBindAttribLocation(m_program, 2, "inTextureCoord");

		//Linking Shaders
		glAttachShader(m_program, m_vertexShader);
		glAttachShader(m_program, m_fragmentShader);

		glLinkProgram(m_program);

		GLint isLinked = 0;
		glGetProgramiv(m_program, GL_LINK_STATUS, &isLinked);
		if(isLinked == GL_FALSE) {
			GLint maxLength = 0;
			glGetProgramiv(m_program, GL_INFO_LOG_LENGTH, &maxLength);

			std::vector<char> errorLog(maxLength);
			glGetProgramInfoLog(m_program, maxLength, &maxLength, &errorLog[0]);

			Console::PrintError("Shaders failed to link");
			std::printf("%s\n", &errorLog[0]);

			glDeleteProgram(m_program);
			glDeleteShader(m_vertexShader);
			glDeleteShader(m_fragmentShader);
		}

		glDetachShader(m_program, m_vertexShader);
		glDetachShader(m_program, m_fragmentShader);
    }

	Shader::~Shader() {
		glDeleteProgram(m_program);
		glDeleteShader(m_vertexShader);
		glDeleteShader(m_fragmentShader);
    }

    void Shader::Bind() {
		glUseProgram(m_program);
    }

	bool Shader::Compile(std::string shaderSource, GLuint shader) {

		const char* shaderCode = shaderSource.c_str();

		glShaderSource(shader, 1, &shaderCode, NULL);
		glCompileShader(shader);

		//Check for errors
		GLint success = 0;
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		if(success == GL_FALSE) {
			GLint maxLength = 0;
			glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &maxLength);

			std::vector<char> errorLog(maxLength);
			glGetShaderInfoLog(shader, maxLength, &maxLength, &errorLog[0]);

			Console::PrintError("Could not compile shader: " + shaderSource);
			std::printf("%s\n", &errorLog[0]);

			glDeleteShader(shader);
			return true;
		}

		return false;
	}
}