#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

#include "constants.h"
#include "window.h"
#include "events.h"
#include "input.h"
#include "entity.h"
#include "texture.h"
#include "renderer.h"

float delta_time;
float average_delta_time;
int average_delta_time_counter;
float frame_time;
Uint64 begin_frame_time = 0;
Uint64 end_frame_time = 0;
bool should_quit = false;

int prev_key_f = 0;

Entity* enemy;
Entity* maya;

Vector2 acceleration;
Vector2 velocity;

void setup();
void pre_update();
void update();
void input();
void post_update();
void render();
void game_shutdown();
void game_initialize();

void setup()
{
    enemy = entity_create(69, 69, 69, 69, 0, SDL_FLIP_NONE, 1, 0, true);
    maya = entity_create(200, 200, 69, 69, 0, SDL_FLIP_NONE, 1, 0, true);
    maya->sprite.color.g = 0;
    enemy->sprite.color.r = 0;
    maya->sprite.color.b = 0;
}

void pre_update() //Lock fps and calculate deltatime.
{
    begin_frame_time = SDL_GetTicks();
}

void input()
{
    if (key_ctrl_l && key_w)
    {
        game_shutdown();
        return;
    }

    if (key_f - prev_key_f > 0)
    {
        if (fullscreen)
        {
            printf("Changing to windowed mode...\n\n");
            fullscreen = false;
            SDL_SetWindowSize(window, WINDOW_WIDTH, WINDOW_HEIGHT);
            SDL_SetWindowFullscreen(window, 0);
        }
        else
        {
            printf("Changing to fullscreen mode...\n\n");
            fullscreen = true;
            SDL_SetWindowSize(window, 1920, 1080);
            SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
        }
    }

    prev_key_f = key_f;
}

void update() // Game stuff
{
    input();

    float max_velocity = 200.0f;

    Vector2 input;
    Vector2 normalized_input;

    input.x = (key_right - key_left);
    input.y = (key_down - key_up);

    normalized_input = mymath_vector2_normalize(&input);
    
    acceleration.x = normalized_input.x * 500.0f;
    acceleration.y = normalized_input.y * 500.0f;  //acceleration range is <-1000, 1000>

    acceleration.x -= velocity.x * delta_time * max_velocity;
    acceleration.y -= velocity.y * delta_time * max_velocity;
  
    velocity.x += acceleration.x * delta_time; //Velocity gets added approx. <-4, 4> which on 240 [fps] 0.0041 [spf] every frame.
    velocity.y += acceleration.y * delta_time;

    maya->position.x += velocity.x * delta_time;
    maya->position.y += velocity.y * delta_time;
}

void post_update()
{
    end_frame_time = SDL_GetTicks();

    //frame_time = (float)(end_frame_time - begin_frame_time) / (float)SDL_GetPerformanceFrequency() * 1000.0f; //in ms
    frame_time = end_frame_time - begin_frame_time; // in ms

    SDL_Delay((int)abs((TARGET_FRAME_TIME - frame_time))); // wait the rest of the needed time

    delta_time = (SDL_GetTicks() - begin_frame_time) / 1000.0f; // in s

    char entry[200] = "Life Game v0.01, FPS = ";

    char buf1[50];

    char buf2[50];

    average_delta_time += delta_time; // sum of deltatime

    average_delta_time_counter++;

    if (average_delta_time_counter >= AVERAGE_DELTA_TIME_COUNT)
    {
        average_delta_time /= AVERAGE_DELTA_TIME_COUNT;

        average_delta_time_counter = 0;

        gcvt(1.0f / average_delta_time, 5, buf1);

        strcat(entry, buf1);

        strcat(entry, ", Delta time = ");

        gcvt(average_delta_time, 5, buf2);

        strcat(entry, buf2);

        SDL_SetWindowTitle(window, entry);
    }
}

int main(int argc, char *argv[])
{
    /// INITIALIZE GAME AND RENDERER ETC
    game_initialize();

    while (!should_quit)
    {
        if (event_system())
        {
            break;
        }

        pre_update();
        update();
        post_update();
        renderer_render();
    }

    game_shutdown();
    return 0;
}

void game_initialize()
{
    initialize_window(FULLSCREEN, WINDOW_WIDTH, WINDOW_HEIGHT);
    tex_load_all();
    entity_system_init();
    setup();
}

void game_shutdown()
{
    entity_system_terminate();
    tex_unload_all();
    destroy_window();
}