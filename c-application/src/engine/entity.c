#include <stdlib.h>
#include "entity.h"

unsigned int entity_array_size = 0;

void entity_system_init(void)
{
    entity_array = calloc(1, sizeof(Entity)); //Create memory for 1 entity.
    if (!entity_array) 
    {
        perror("Could not allocate memory for entities\n");
    }
}

Entity* entity_create(float x, float y, float w, float h, float angle, SDL_RendererFlip flip, uint8_t depth, uint16_t texture_id, bool active)
{
    entity_array_size++;

    Entity** entity_new_array;
    SDL_Color color;
    color.r = 255;
    color.g = 255;
    color.b = 255;
    color.a = 255;

    if (entity_array_size != 1) //if not at first element. Create new element.
    {
        entity_new_array = realloc(entity_array, entity_array_size * sizeof(Entity*));
        if (!entity_new_array)
        {
            perror("Could not reallocate more memory for entities\n");
        }

        entity_array = entity_new_array;
    }

    Entity* new_entity_pointer = (Entity*)malloc(sizeof(Entity));

    new_entity_pointer->sprite.angle = angle;
    new_entity_pointer->sprite.flip = flip;
    new_entity_pointer->sprite.depth = depth;
    new_entity_pointer->sprite.color = color;
    new_entity_pointer->position.x = x;
    new_entity_pointer->position.y = y;
    new_entity_pointer->sprite.size.x = w;
    new_entity_pointer->sprite.size.y = h;
    new_entity_pointer->sprite.texture_id = texture_id;
    new_entity_pointer->active = active;

    entity_array[entity_array_size - 1] = new_entity_pointer;

    printf("New entity pointer: %zu\n", new_entity_pointer);

    return new_entity_pointer;
}

void entity_system_terminate(void)
{
    for (int i = 0; i < entity_array_size; i++)
    {
        free(entity_array[i]);
    }
    

    free(entity_array);
}