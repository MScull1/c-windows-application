#ifndef SPRITE_HEADER_
#define SPRITE_HEADER_

#include <SDL2/SDL.h>
#include <stdbool.h>
#include <stdint.h>
#include "mymath.h"

typedef struct Sprite
{
    uint16_t texture_id;
    uint8_t depth;
    float angle;
    Vector2 size;
    Vector2 offset;
    bool use_screen_position;
    SDL_RendererFlip flip;
    SDL_Color color;
} Sprite;

Sprite** sprite_array;
unsigned int sprite_array_size;

void sprite_system_init(void);
void sprite_system_terminate(void);

Sprite* sprite_create(float x, float y, float w, float h, float angle, SDL_RendererFlip flip, uint8_t depth, uint16_t texture_id, bool use_screen_position, bool visible);
void sprite_destroy(Sprite* sprite);

#endif