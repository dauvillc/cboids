#include "drawer.h"

Drawer::Drawer(SDL_Window* window, SDL_Renderer* renderer) :
window(window), renderer(renderer)
{   
    /* Sets the rendering color to white */
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderGetClipRect(renderer, &screenRect);
}

void Drawer::clear() {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
    reset_color();
}

void Drawer::update() {
    SDL_RenderPresent(renderer);
}

/** Resets the rendering color */
void Drawer::reset_color() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
}

void Drawer::draw_point(int x, int y, SDL_Color* color) {
    if (color != NULL)
        SDL_SetRenderDrawColor(renderer, color->a, color->g,
            color->b, color->a);
    SDL_Rect rect = {x, y, 5, 5};
    SDL_RenderFillRect(renderer, &rect);
    reset_color();
}