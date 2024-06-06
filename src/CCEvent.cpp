#include "CCEvent.hpp"

#include <SDL2/SDL_events.h>
#include <SDL2/SDL_keycode.h>

namespace cc
{
    int Event::PollEvent(CCEvent *event)
    { return SDL_PollEvent(event); }
}
