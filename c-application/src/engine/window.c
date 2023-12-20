#include <stdio.h>
#include <stdbool.h>
#include <glad/glad.h>
#include <SDL2/SDL.h>

SDL_Window *window;
SDL_Renderer *renderer;

int InitializeWindow(bool fullscreen, int size_x, int size_y)
{
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        printf("Could not init SDL: %s\n", SDL_GetError());
        exit(1);
    }

    window = SDL_CreateWindow(NULL, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, size_x, size_y, SDL_WINDOW_OPENGL || SDL_WINDOW_BORDERLESS);
    
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