#include <stdio.h>
#include <stdbool.h>
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <glad/glad.h>

#include "constants.h"
#include "engine/window.h"
#include "engine/events.h"
#include "engine/input.h"

float delta_time;
Uint64 last_frame_time = 0;
bool should_quit = false;

void setup()
{
    //To do 
}

void pre_update() //Lock fps and calculate deltatime.
{
    int time_to_wait = TARGET_FRAME_TIME - (SDL_GetTicks() - last_frame_time);

    if (time_to_wait > 0 && time_to_wait <= TARGET_FRAME_TIME)
    {
        SDL_Delay(time_to_wait);
    }
    //To do
    float delta_time = (SDL_GetTicks() - last_frame_time) / 1000.0f;
    printf("Deltatime = %f\n", delta_time);
}

void update()
{

}

void post_update()
{
    last_frame_time = SDL_GetTicks();
}

void render()
{

    glClearColor(1.0, 0.5, 0.5, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);




    /* //Render stuff.
    SDL_Surface* rect_surface;
    SDL_Color rect_color;
    rect_color.r = 10;
    rect_color.g = 10;
    rect_color.b = 10;
    SDL_Rect rect;
    rect.h = 128;
    rect.w = 256;
    rect.x = 100;
    rect.y = 100;

    SDL_SetRenderDrawColor(renderer, 10, 10, 10, 255); //set color to red

    SDL_RenderFillRect(renderer, &rect); */

    SDL_GL_SwapWindow(window);

    
/*     SDL_RenderPresent(renderer); //render it. */
}

int main(int argc, char *argv[])
{
    /// INITIALIZE WINDOW AND RENDERER ETC
    initialize_window(FULLSCREEN, WINDOW_WIDTH, WINDOW_HEIGHT);
    setup();

    printf("Entering main loop...\n");
    while (!should_quit)
    {
        if (event_system())
        {
            break;
        }

        pre_update();
        update();
        post_update();
        render();
    }



    destroy_window();

    return 0;
}

