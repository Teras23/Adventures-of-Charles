#include "Renderer.h"
#include "Game.h"
#include "Util.h"

SDL_GLContext Renderer::context = NULL;
GLuint Renderer::programId = 0;

GLuint vbo;
GLuint ibo;
GLint vertext2DLoc = -1;

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

    glClearColor(0.0f, 0.5f, 1.0f, 0.0f);

    const GLchar* vertexSource[] = { "#version 140\nin vec2 LVertexPos2D; void main() { gl_Position = vec4( LVertexPos2D.x, LVertexPos2D.y, 0, 1 ); }" };
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, vertexSource, NULL);
    glCompileShader(vertexShader);
    //TODO: Check if shader is compiled

    glAttachShader(programId, vertexShader);

    const GLchar* fragmentSource[] = { "#version 140\nout vec4 LFragment; void main() { LFragment = vec4( 1.0, 1.0, 1.0, 1.0 ); }" };
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, fragmentSource, NULL);
    glCompileShader(fragmentShader);
    //TODO: Check if shader is compiled

    glAttachShader(programId, fragmentShader);

    glLinkProgram(programId);
    //TODO: Check for errors

    GLfloat vertices[] = {
        -0.5f, -0.5f,
         0.5f, -0.5f, 
         0.5f, 0.5f,
        -0.5f, 0.5f,
    };

    GLuint index[] = { 0, 1, 2, 3 };

    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, 2 * 4 * sizeof(vertices), vertices, GL_STATIC_DRAW);

    glGenBuffers(1, &ibo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 4 * sizeof(index), index, GL_STATIC_DRAW);
    return 0;
}

void Renderer::Render() {
    glClearDepth(1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glUseProgram(programId);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    glEnableVertexAttribArray(0);
    
    glVertexAttribPointer(vertext2DLoc, 2, GL_FLOAT, GL_FALSE, NULL, NULL);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
    glDrawElements(GL_TRIANGLES, 4, GL_UNSIGNED_INT, NULL);

    glDisableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glUseProgram(NULL);

    SDL_GL_SwapWindow(Game::window);
}