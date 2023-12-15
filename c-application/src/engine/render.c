#include <stdio.h>
#include <stdbool.h>
#include <glad/glad.h>
#include <SDL2/SDL.h>
#include "render.h"

SDL_Window *window;
SDL_Renderer *renderer;

int InitializeWindow(bool fullscreen, int x, int y)
{
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("Could not init SDL: %s\n", SDL_GetError());
        exit(1);
    }

    window = SDL_CreateWindow("MyApp", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_OPENGL);
    
    if (!window)
    {
        printf(("Failed to init window: %s\n", SDL_GetError()));
        exit(1);
    }

    renderer = SDL_CreateRenderer(window, -1, 0);

    if (!renderer)
    {
        printf(("Failed to init renderer: %s\n", SDL_GetError()));
        exit(1);
    }

    SDL_GL_CreateContext(window);
    
    if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress))
    {
        printf("Failed to load GL: %s\n", SDL_GetError());
        exit(1);
    }

    printf("Vendor:   %s\n", glGetString(GL_VENDOR));
    printf("Renderer: %s\n", glGetString(GL_RENDERER));
    printf("Version:  %s\n", glGetString(GL_VERSION));
}