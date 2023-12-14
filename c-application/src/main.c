#include <stdio.h>
#include <stdbool.h>
#include <glad/glad.h>
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>

#define WINDOWHEIGHT 600;
#define WINDOWWIDTH 800;

int main(int argc, char *argv[])
{
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("Could not init SDL: %s\n", SDL_GetError());
        exit(1);
    }

    SDL_Window *window = SDL_CreateWindow("MyApp", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_OPENGL);
    
    if (!window)
    {
        printf(("Failed to init window: %s\n", SDL_GetError()));
        exit(1);
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);

    if (!renderer)
    {
        printf(("Failed to init renderer: %s\n", SDL_GetError()));
        exit(1);
    }

    SDL_GL_CreateContext(window);
    
    if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress))
    {
        printf("Failed to load GL: %s\n", SDL_GetError());
        exit(1);
    }
    
    printf("Vendor:   %s\n", glGetString(GL_VENDOR));
    printf("Renderer: %s\n", glGetString(GL_RENDERER));
    printf("Version:  %s\n", glGetString(GL_VERSION));

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
            printf("Key press detected.\n");
            if (velX == 0)
            {
                velX = 1;
                break;
            }

            velX = -velX;

            break;
            case SDL_KEYUP:
            velX = 0;
            velY = 0;
            printf("Key release detected.\n");
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