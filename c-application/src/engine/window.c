#include <stdio.h>
#include <stdbool.h>
#include <glad/glad.h>
#include <SDL2/SDL.h>

SDL_Window *window;
SDL_Renderer *renderer;
SDL_GLContext *context;

int initialize_window(bool fullscreen, int size_x, int size_y)
{
    printf("Initializing window...\n");
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        printf("Could not init SDL: %s\n", SDL_GetError());
        return 1;
    }

    SDL_WindowFlags fullscreenFlag = 0;

    if (fullscreen)
    {
        fullscreenFlag = SDL_WINDOW_FULLSCREEN_DESKTOP;
    }

    window = SDL_CreateWindow("game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, size_x, size_y, SDL_WINDOW_OPENGL | SDL_WINDOW_INPUT_FOCUS | fullscreenFlag);
    
    if (!window)
    {
        printf(("Failed to init window: %s\n", SDL_GetError()));
        return 1;
    }

    renderer = SDL_CreateRenderer(window, -1, 0);

    if (!renderer)
    {
        printf(("Failed to init renderer: %s\n", SDL_GetError()));
        return 1;    
    }

    context = SDL_GL_CreateContext(window);
    
    if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress))
    {
        printf("Failed to load GL: %s\n", SDL_GetError());
        return 1;
    }

    printf("Vendor:   %s\n", glGetString(GL_VENDOR));
    printf("Renderer: %s\n", glGetString(GL_RENDERER));
    printf("Version:  %s\n", glGetString(GL_VERSION));

    return 0;
}

void destroy_window()
{
    printf("Exiting program...");

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}