#include <SDL2/SDL.h>
#include "window.h"
#include "entity.h"
#include "texture.h"
#include "renderer.h"

void renderer_render()
{
    SDL_FRect entity_dst_rect;
    //Render terrain


    //Render entities.
    SDL_SetRenderDrawColor(renderer, 40, 40, 40, 255);
    SDL_RenderClear(renderer);

    for (int i = 0; i < entity_array_size; i++)
    {
        if (entity_array[i]->active == false)
        {
            continue;
        }

        entity_dst_rect.x = entity_array[i]->position.x - entity_array[i]->sprite.size.x / 2;
        entity_dst_rect.y = entity_array[i]->position.y - entity_array[i]->sprite.size.y / 2;
        entity_dst_rect.w = entity_array[i]->sprite.size.x;
        entity_dst_rect.h = entity_array[i]->sprite.size.y;

        if (tex_array[entity_array[i]->sprite.texture_id] == NULL)
        {
            SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255); //if texture id = 0, render pink.
            SDL_RenderFillRectF(renderer, &entity_dst_rect);
        }
        else
        {
            SDL_SetTextureColorMod(tex_array[entity_array[i]->sprite.texture_id], entity_array[i]->sprite.color.r, entity_array[i]->sprite.color.g, entity_array[i]->sprite.color.b);
            SDL_RenderCopyExF(renderer, tex_array[entity_array[i]->sprite.texture_id], NULL, &entity_dst_rect, entity_array[i]->sprite.angle, NULL, entity_array[i]->sprite.flip);
        }
    }

    //Render Gizmos
    

/*     SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawLineF(renderer, maya->position.x, maya->position.y, maya->position.x + velocity.x, maya->position.y + velocity.y);
    SDL_SetRenderDrawColor(renderer, 255, 128, 128, 255);
    SDL_RenderDrawLineF(renderer, 0, 0, maya->position.x, maya->position.y); */


    
    SDL_RenderPresent(renderer); //render it.
}