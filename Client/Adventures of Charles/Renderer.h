#ifndef RENDERER_H
#define RENDERER_H
#include <SDL.h>
#include <GL\glew.h>

class Renderer {
public:
    static GLuint programId;

    static SDL_GLContext context;
    static bool Init();
    static void Quit();
    static void Render();
};

#endif