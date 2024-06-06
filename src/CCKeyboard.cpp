#include "CCKeyboard.hpp"

#include <cstdint>

#include <SDL2/SDL_keyboard.h>

namespace cc
{
    const uint8_t *Keyboard::GetKeyboardState(int *numkeys)
    { return SDL_GetKeyboardState(numkeys); }
}
