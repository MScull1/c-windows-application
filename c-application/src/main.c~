#include <stdio.h>
#include <stdbool.h>
#include <glad/glad.h>
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include "engine/render.h"

int main(int argc, char *argv[])
{
    InitializeWindow(false, 800, 600);

    bool should_quit = false;
    SDL_Event event;

    int velX = 0;
    int velY = 0;

    int posX = 400;
    int posY = 280;

    while (!should_quit)
    {
        SDL_Delay(10);
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
                velX = -1;
                break;
                case SDLK_RIGHT:
                velX = 1;
                break;
                case SDLK_UP:
                velY = -1;
                break;
                case SDLK_DOWN:
                velY = 1;
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
                velX = 0;
                break;
                case SDLK_RIGHT:
                velX = 0;
                break;
                case SDLK_UP:
                velY = 0;
                break;
                case SDLK_DOWN:
                velY = 0;
                break;
                default:
                break;
            }
            break;
            default:
            break;
        }

        SDL_SetRenderDrawColor(renderer, 128, 128, 128, 255);
        SDL_RenderClear(renderer);

        //Render stuff.
        SDL_SetRenderDrawColor(renderer, 255, 10, 10, 255);

        SDL_RenderDrawLine(renderer, 0, 300, 800, 300); 

        SDL_Rect rect;
        rect.h = 32;
        rect.w = 32;

        posX = posX + velX;
        posY = posY + velY;
        rect.x = posX;
        rect.y = posY;

        const SDL_Rect *rectPointer = &rect;

        SDL_RenderFillRect(renderer, rectPointer); 

        SDL_RenderPresent(renderer);

    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
