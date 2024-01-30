#include <stdbool.h>

int initialize_window(bool fullscreen, int x, int y);
void destroy_window();

extern bool fullscreen;

extern SDL_Window *window;
extern SDL_Renderer *renderer;
extern SDL_GLContext *context;