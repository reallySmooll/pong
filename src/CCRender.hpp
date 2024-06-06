#ifndef CC_RENDER
#define CC_RENDER

#include <SDL2/SDL_render.h>

namespace cc
{
    namespace Render
    {
        int RenderClear(SDL_Renderer *renderer);

        void RenderPresent(SDL_Renderer *renderer);
    }
}

#endif // CC_RENDER
