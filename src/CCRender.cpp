#include "CCRender.hpp"

#include <SDL2/SDL_render.h>

namespace cc
{
    int Render::RenderClear(SDL_Renderer *renderer)
    { return SDL_RenderClear(renderer); }

    void Render::RenderPresent(SDL_Renderer *renderer)
    { return SDL_RenderPresent(renderer); }
}
