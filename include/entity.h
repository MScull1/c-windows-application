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

typedef struct Entity
{
    bool active;
    Vector2 position;
    Sprite sprite;
} Entity;

Entity** entity_array;
unsigned int entity_array_size;

void entity_system_init(void);
void entity_system_terminate(void);

Entity* entity_create(float x, float y, float w, float h, float angle, SDL_RendererFlip flip, uint8_t depth, uint16_t texture_id, bool active);
void entity_destroy(Entity* entity);

Sprite* sprite_create(float x, float y, float w, float h, float angle, SDL_RendererFlip flip, uint8_t depth, uint16_t texture_id, bool use_screen_position, bool visible);