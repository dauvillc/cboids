#include <iostream>
#include "sdl_methods.h"
#include "drawer.h"
#include "tests.h"


int main(int argc, char* argv[])
{
    /* =====================INIT=================== */
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    init_SDL(&window, &renderer);
    SDL_Event evt;
    bool quit = false;

    Drawer drawer(window, renderer); 
    drawer.clear();
    drawer.update();
    
    /* =====================LOOP=================== */
    while (!quit) {
        while (SDL_PollEvent(&evt) != 0) {
            switch (evt.type) {
                case SDL_QUIT:
                    quit = true;
                    break;
                case SDL_KEYUP:
                    switch(evt.key.keysym.sym) {
                        case SDLK_ESCAPE:
                            quit = true;
                            break;
                    } // END SWITCH(EVT KEY)
            } // END SWITCH(EVT.TYPE)
        }
    }

    /* ======================QUIT================== */
    SDL_DestroyWindow(window);
    window = NULL;
    SDL_DestroyRenderer(renderer);
    renderer = NULL;
    SDL_Quit();
    return EXIT_SUCCESS;
}