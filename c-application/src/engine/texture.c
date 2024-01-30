#include <SDL2/SDL_image.h>
#include <stdlib.h>
#include "window.h"
char* tex_paths[] = { "assets/images/square_64.png" };
SDL_Texture** tex_array;

void tex_load_all()
{
    int array_length = sizeof(tex_paths) / sizeof(tex_paths[0]);

    tex_array = malloc(array_length * sizeof(SDL_Texture*));

    for (int i = 0; i < array_length; i++)
    {
        tex_array[i] = IMG_LoadTexture(renderer, tex_paths[i]);

        printf("Texture %d loaded. With path: %s\n", i, tex_paths[i]);
    }    
}

void tex_unload_all()
{
    free(tex_array);
    free(tex_paths);
}