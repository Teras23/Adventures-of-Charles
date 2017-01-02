#ifndef RENDERER_H
#define RENDERER_H
#include <SDL.h>
#include <GL\glew.h>
#include <string>

class Renderer {
public:
    static GLuint programId;
    static GLuint vertexShader;
    static GLuint fragmentShader;


    static SDL_GLContext context;
    static bool Init();
    static void Quit();
    static void Render();

    static int CompileShader(std::string path, GLuint shader);
};

#endif