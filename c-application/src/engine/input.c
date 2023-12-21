#include <SDL2/SDL.h>

uint8_t key_left = 0;
int key_right = 0;
int key_up = 0;
int key_down = 0;
int key_space = 0;
int key_w = 0;
int key_a = 0;
int key_s = 0;
int key_d = 0;

void key_down_event(SDL_KeyboardEvent *key)
{
    printf("Key pressed: %s\n", SDL_GetKeyName(key->keysym.sym));
    switch(key->keysym.sym)
    {
        case SDLK_LEFT:
        key_left = 1;
        break;
        case SDLK_RIGHT:
        key_right = 1;
        break;
        case SDLK_UP:
        key_up = 1;
        break;
        case SDLK_DOWN:
        key_down = 1;
        break;
        default:
        break;
    }
}
void key_release_event(SDL_KeyboardEvent *key)
{
    //printf("\nKey released: %s", SDL_GetKeyName(key->keysym.sym));

    switch(key->keysym.sym)
    {
        case SDLK_LEFT:
        key_left = 0;
        break;
        case SDLK_RIGHT:
        key_right = 0;
        break;
        case SDLK_UP:
        key_up = 0;
        break;
        case SDLK_DOWN:
        key_down = 0;
        break;
        default:
        break;
    }
}