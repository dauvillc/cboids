#include "sdl_methods.h"

/* Initializes the SDL library.
- window, renderer: adresses into which the window and renderer
will be saved. 
*/
int init_SDL(SDL_Window** window, SDL_Renderer** renderer) {
    SDL_Init(SDL_INIT_VIDEO);
    return SDL_CreateWindowAndRenderer(600, 600, SDL_WINDOW_SHOWN,
        window, renderer);
}