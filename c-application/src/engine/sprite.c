#include "sprite.h"

unsigned int sprite_array_size = 0;

void sprite_system_init(void)
{
    sprite_array = calloc(1, sizeof(Sprite)); //Create memory for 1 entity.
    if (!sprite_array) 
    {
        perror("Could not allocate memory for sprites\n");
    }
}

void sprite_system_terminate(void)
{
    for (int i = 0; i < sprite_array_size; i++)
    {
        free(sprite_array[i]);
    }

    free(sprite_array);
}

Sprite* sprite_create(float x, float y, float w, float h, float angle, SDL_RendererFlip flip, uint8_t depth, uint16_t texture_id, bool use_screen_position, bool visible)
{
    sprite_array_size++;

    Sprite** sprite_new_array;

    SDL_Color color;
    color.r = 255;
    color.g = 255;
    color.b = 255;
    color.a = 255;

    if (sprite_array_size != 1) //if not at first element. Create new element.
    {
        sprite_new_array = realloc(sprite_array, sprite_array_size * sizeof(Sprite*));
        if (!sprite_new_array)
        {
            perror("Could not reallocate more memory for entities\n");
        }

        sprite_array = sprite_new_array;
    }

    Sprite* new_sprite_pointer = (Sprite*)malloc(sizeof(Sprite));

    new_sprite_pointer->angle = angle;
    new_sprite_pointer->flip = flip;
    new_sprite_pointer->depth = depth;
    new_sprite_pointer->color = color;
    new_sprite_pointer->size.x = w;
    new_sprite_pointer->size.y = h;
    new_sprite_pointer->texture_id = texture_id;

    sprite_array[sprite_array_size - 1] = new_sprite_pointer;

    printf("New entity pointer: %zu\n", new_sprite_pointer);

    return new_sprite_pointer;
}

void sprite_destroy(Sprite* sprite)
{
    
}
