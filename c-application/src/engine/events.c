#include <SDL2/SDL.h>
#include <stdbool.h>
#include "input.h"
#include "events.h"

bool event_system(void)
{
    SDL_Event event;
    SDL_KeyboardEvent *key = NULL;
    SDL_PollEvent(&event);

    switch (event.type)
    {
        case SDL_QUIT:
        return true;
        break;

        case SDL_KEYDOWN:
        key = &event.key;
        key_down_event(key);
        break;

        case SDL_KEYUP:
        key = &event.key;
        key_release_event(key);
        break;

        case SDL_MOUSEBUTTONDOWN:
        break;

        case SDL_MOUSEBUTTONUP:
        break;        

        default:
        break;
    }

    return false;
}