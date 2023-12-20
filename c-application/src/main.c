#include <stdio.h>
#include <stdbool.h>
#include <glad/glad.h>
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>

#include "constants.h"
#include "engine/window.h"

int main(int argc, char *argv[])
{
    /// INITIALIZE WINDOW AND RENDERER ETC
    InitializeWindow(false, WINDOW_WIDTH, WINDOW_HEIGHT);

    /// START FUNCTION

    bool should_quit = false;
    SDL_Event event;

    while (!should_quit)
    {
        SDL_PollEvent(&event);

        switch (event.type)
        {
            case SDL_QUIT:
            should_quit = true;
            break;
            case SDL_KEYDOWN:
            SDL_KeyboardEvent *key = &event.key;
            switch(event.key.keysym.sym) 
            {
                case SDLK_LEFT:

                break;
                case SDLK_RIGHT:
                break;
                case SDLK_UP:
                break;
                case SDLK_DOWN:
                break;
                default:
                break;
            }
            printf("\n%s", SDL_GetKeyName(key->keysym.sym));
            break;
            case SDL_KEYUP:
            switch(event.key.keysym.sym)
            {
                case SDLK_LEFT:
                break;
                case SDLK_RIGHT:
                break;
                case SDLK_UP:
                break;
                case SDLK_DOWN:
                break;
                default:
                break;
            }
            break;
            default:
            break;
        }

        SDL_SetRenderDrawColor(renderer, 128, 128, 128, 255); // set background color.
        SDL_RenderClear(renderer); //Sets the view to background color.

        //Render stuff.
        SDL_SetRenderDrawColor(renderer, 255, 10, 10, 255); //set color to red
        SDL_RenderDrawLine(renderer, 0, 300, 800, 300); //draw line

        SDL_SetRenderDrawColor(renderer, 50, 0, 255, 255);

        SDL_RenderPresent(renderer); //render it.
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}