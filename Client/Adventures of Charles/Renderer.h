#ifndef RENDERER_H
#define RENDERER_H
#include <SDL.h>
#include <SDL_opengl.h>
#include <gl\GLU.h>

class Renderer {
public:
    static SDL_GLContext context;
    static void Init();
    static void Quit();
    static void Render();
};

#endif