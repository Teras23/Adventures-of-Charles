#include "Renderer.h"
#include "Game.h"
#include "../Shared/Util.h"

#include <fstream>

SDL_GLContext Renderer::context = NULL;
GLuint Renderer::programId = 0;
GLuint Renderer::vertexShader;
GLuint Renderer::fragmentShader;


GLuint vbo;
GLuint ibo;
GLint vertext2DLoc = 0;

bool Renderer::Init() {
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);

    GLenum glewError = glewInit();

    if(glewError != GLEW_OK) {
        //TODO: GET ERROR PRINTED
        Console::PrintError("Error initing GLEW");
        return -1;
    }

    glClearColor(0.0f, 1.0f, 1.0f, 0.0f);

    programId = glCreateProgram();

    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER); 
    if(vertexShader == 0) {
        Console::PrintError("Could not create vertex shader");
    }

    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    if(fragmentShader == 0) {
        Console::PrintError("Could not create fragment shader");
    }
    
    CompileShader("Resources/Shaders/colorShading.vert", vertexShader);
    CompileShader("Resources/Shaders/colorShading.frag", fragmentShader);
    

    glBindAttribLocation(programId, 0, "vertexPosition");

    //
    //Linking shaders
    //
    glAttachShader(programId, vertexShader);
    glAttachShader(programId, fragmentShader);

    glLinkProgram(programId);

    GLint isLinked = 0;
    glGetProgramiv(programId, GL_LINK_STATUS, &isLinked);
    if(isLinked == GL_FALSE) {
        GLint maxLength = 0;
        glGetProgramiv(programId, GL_INFO_LOG_LENGTH, &maxLength);

        std::vector<char> errorLog(maxLength);
        glGetProgramInfoLog(programId, maxLength, &maxLength, &errorLog[0]);

        Console::PrintError("Shaders failed to link");
        std::printf("%s\n", &errorLog[0]);

        glDeleteProgram(programId);
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
        return -1;
    }

    glDetachShader(programId, vertexShader);
    glDetachShader(programId, fragmentShader);


    GLfloat vertices[] = {
         0.0f,  0.5f,
         0.5f, -0.5f, 
        -0.5f, -0.5f,
    };

    float index[] = { 0, 1, 2 };

    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glGenBuffers(1, &ibo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(index), index, GL_STATIC_DRAW);
    return 0;
}

void Renderer::Quit() {

}

void Renderer::Render() {
    glClearDepth(1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glUseProgram(programId);
    

    //Start Drawing
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    glDisableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    //End of drawing

    
    glUseProgram(0);

    SDL_GL_SwapWindow(Game::window);
}

int Renderer::CompileShader(std::string path, GLuint shader) {
    std::ifstream file(path);
    if(file.fail()) {
        Console::PrintError("Failed to open file " + path);
        return -1;
    }
    std::string contents = "";
    std::string line;

    while(std::getline(file, line)) {
        contents += line + "\n";
    }

    file.close();

    const char* shaderSource = contents.c_str();

    glShaderSource(shader, 1, &shaderSource, NULL);
    glCompileShader(shader);

    GLint success = 0;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if(success == GL_FALSE) {
        GLint maxLength = 0;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &maxLength);

        std::vector<char> errorLog(maxLength);
        glGetShaderInfoLog(shader, maxLength, &maxLength, &errorLog[0]);

        Console::PrintError("Could not compile shader");
        std::printf("%s\n", &errorLog[0]);

        glDeleteShader(shader);
        return -1;
    }

    return 0;
}