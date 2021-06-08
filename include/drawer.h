#ifndef _DRAWER_H_
#define _DRAWER_H_
#include <SDL2/SDL.h>

class Drawer
{
    private:
        SDL_Renderer* renderer;
        SDL_Window* window;
        SDL_Rect screenRect;
    public:
        Drawer(SDL_Window* window, SDL_Renderer* renderer);
        
        /* Clears the screen by filling it white */
        void clear();
        
        /* Applies all drawing changes on screen */
        void update();

        /* Drawing functions */
        /** Resets the rendering color */
        void reset_color();
        void draw_point(int x, int y, SDL_Color* color);
};

#endif