#include "CCFont.hpp"
#include "CCLog.hpp"

#include <SDL2/SDL_ttf.h>

namespace cc
{
    Font::~Font()
    {
        if (font != nullptr)
        { Destroy(); }
        else
        { WARNING("failed to destroy font! font already destroyed."); }
    }

    void Font::Create(const char *filepath, int fontSize)
    {
        mFilepath = filepath;

        LOG("creating font from file: \"", filepath, "\" with size of font: ", fontSize, "...");
        font = TTF_OpenFont(filepath, fontSize);
        if (font == nullptr)
        { ERROR("failed to create a font!\n\tsdl_ttf error: ", TTF_GetError()); }
    }

    void Font::SetSize(int fontSize)
    {
        LOG("setting font size to ", fontSize, "...");
        TTF_SetFontSize(font, fontSize);
    }

    void Font::Destroy()
    {
        WARNING("destroying font: \"", mFilepath, "\"...");
        TTF_CloseFont(font);

        font = nullptr;
    }
}
