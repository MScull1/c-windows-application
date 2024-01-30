#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "constants.h"
#include "window.h"

SDL_Window *window;
SDL_Renderer *renderer;
bool fullscreen = FULLSCREEN;

int initialize_window(bool _fullscreen, int size_x, int size_y)
{
    SDL_WindowFlags fullscreenFlag = 0;
    
    printf("Initializing window...\n");

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        printf("Could not init SDL: %s\n", SDL_GetError());
        return 1;
    }

    if (_fullscreen)
    {
        fullscreenFlag = SDL_WINDOW_FULLSCREEN_DESKTOP;
    }

    window = SDL_CreateWindow("game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, size_x, size_y, SDL_WINDOW_INPUT_FOCUS | fullscreenFlag);

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


    printf("SDL Version:   %d.%d\n", SDL_MAJOR_VERSION, SDL_MINOR_VERSION);

    IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);

    return 0;
}

void destroy_window()
{
    printf("Exiting program...");
    IMG_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}