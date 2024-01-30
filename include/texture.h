#define TEX_SQUARE_64 1
#define TEX_CIRCLE_64 2

char* tex_paths[];
SDL_Texture** tex_array;
void tex_load_all();
void tex_unload_all();