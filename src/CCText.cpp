#include "CCText.hpp"
#include "CCLog.hpp"

#include <SDL2/SDL_error.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_ttf.h>

namespace cc
{
    Text::~Text()
    {
        if (mTextTexture != nullptr)
        { Destroy(); }
        else
        { WARNING("failed to destroy text! text already destroyed."); }
    }

    void Text::Create(SDL_Renderer *renderer, const char *text, TTF_Font *font, SDL_Color color, int x, int y, Alignment textAlignment)
    {
        OnCreate(renderer, text, font, color, x, y, textAlignment);

        LOG("creating text texture with text: \"", text, "\"...");
        mTextSurface = TTF_RenderUTF8_Solid(font, text, color);
        if (mTextSurface == nullptr)
        { ERROR("failed to create text surface!\n\tsdl_ttf error: ", TTF_GetError()); }

        LOG("getting text offset from text: \"", text, "\"...");
        int textWidth, textHeight;
        if (TTF_SizeUTF8(font, text, &textWidth, &textHeight) != 0)
        { ERROR("failed to get text size!\n\tsdl_ttf error: ", TTF_GetError()); }

        mTextOffsetX = textWidth / 2;

        mTextTexture = SDL_CreateTextureFromSurface(mRenderer, mTextSurface);
        if (mTextTexture == nullptr)
        {
            ERROR("failed to create text texture from surface!\n\tsdl error: ", SDL_GetError());
            SDL_FreeSurface(mTextSurface);
            mTextSurface = nullptr;
        }

        int w, h;

        SDL_QueryTexture(mTextTexture, nullptr, nullptr, &w, &h);

        SetAlignment(mAlignment);
        mTextRect.y = y;
        mTextRect.w = w;
        mTextRect.h = h;

        TEXT_WIDTH  = w;
        TEXT_HEIGHT = h;
        TEXT_CENTER_W = w / 2;
        TEXT_CENTER_H = h / 2;

        SDL_FreeSurface(mTextSurface);
        mTextSurface = nullptr;
    }

    void Text::Update(const char *text, TTF_Font *font, SDL_Color color, int x, int y)
    {
        mText = text;

        mX = x;

        if (mTextTexture != nullptr)
        {
            SDL_DestroyTexture(mTextTexture);
            mTextTexture = nullptr;
        }

        mTextSurface = TTF_RenderUTF8_Solid(font, text, color);
        if (mTextSurface == nullptr)
        { ERROR("failed to update text surface!\n\tsdl_ttf error: ", TTF_GetError()); }

        int textWidth, textHeight;
        if (TTF_SizeUTF8(font, text, &textWidth, &textHeight) != 0)
        { ERROR("failed to get text size!\n\tsdl_ttf error: ", TTF_GetError()); }

        mTextOffsetX = textWidth / 2;

        mTextTexture = SDL_CreateTextureFromSurface(mRenderer, mTextSurface);
        if (mTextTexture == nullptr)
        {
            ERROR("failed to update text (\"", text, "\") texture from surface!\n\tsdl error: ", SDL_GetError());
            SDL_FreeSurface(mTextSurface);
            mTextSurface = nullptr;
        }

        int w, h;

        SDL_QueryTexture(mTextTexture, nullptr, nullptr, &w, &h);

        SetAlignment(mAlignment);
        mTextRect.y = y;
        mTextRect.w = w;
        mTextRect.h = h;

        TEXT_WIDTH  = w;
        TEXT_HEIGHT = h;
        TEXT_CENTER_W = w / 2;
        TEXT_CENTER_H = h / 2;

        SDL_FreeSurface(mTextSurface);
        mTextSurface = nullptr;
    }

    void Text::SetX(int x)
    {
        mX = x;
        SetAlignment(mAlignment);
    }

    void Text::SetY(int y)
    { mTextRect.y = y; }

    void Text::SetPosition(int x, int y)
    {
        mX = x;
        SetAlignment(mAlignment);

        mTextRect.y = y;
    }

    void Text::SetAlignment(Alignment textAlignment)
    {
        mAlignment = textAlignment;

        switch (textAlignment)
        {
            case Alignment::LEFT:
                mTextRect.x = mX;
                break;

            case Alignment::CENTER:
                mTextRect.x = mX - mTextOffsetX;
                break;

            default:
                break;
        }
    }

    void Text::Render()
    { SDL_RenderCopy(mRenderer, mTextTexture, nullptr, &mTextRect); }

    void Text::Destroy()
    {
        WARNING("destroying text: \"", mText, "\"...");
        SDL_DestroyTexture(mTextTexture);

        mTextTexture = nullptr;
    }

    void Text::OnCreate(SDL_Renderer *renderer, const char *text, TTF_Font *font, SDL_Color color, int x, int y, Alignment textAlignment)
    {
        mRenderer = renderer;
        mText = text;
        mFont = font;
        mColor = color;
        mX = x;
        mY = y;
        mAlignment = textAlignment;
    }
}
