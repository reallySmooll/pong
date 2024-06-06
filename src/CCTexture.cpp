#include "CCTexture.hpp"
#include "CCLog.hpp"

#include <cstdint>
#include <string.h>

#include <SDL2/SDL_blendmode.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_surface.h>

namespace cc
{
    BlendMode Texture::BLENDMODE_NONE  = SDL_BLENDMODE_NONE;
    BlendMode Texture::BLENDMODE_BLEND = SDL_BLENDMODE_BLEND;
    BlendMode Texture::BLENDMODE_ADD   = SDL_BLENDMODE_ADD;
    BlendMode Texture::BLENDMODE_MOD   = SDL_BLENDMODE_MOD;
    BlendMode Texture::BLENDMODE_MUL   = SDL_BLENDMODE_MUL;

    Texture::~Texture()
    { Destroy(); }

    bool Texture::Create(SDL_Renderer *renderer, const char *filepath)
    {
        Destroy();

        mRenderer = renderer;

        mFilepath = filepath;

        LOG("creating texture from file ", filepath, "...");

        SDL_Texture *texture = nullptr;

        SDL_Surface *surface = IMG_Load(filepath);
        if (surface == nullptr)
        { ERROR("failed to load texture from file ", filepath, "!\n\tsdl_image error: ", IMG_GetError()); }

        SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, 0, 0xff, 0xff));

        texture = SDL_CreateTextureFromSurface(mRenderer, surface);
        if (texture == nullptr)
        { ERROR("failed to create texture!\n\tsdl_image error: ", IMG_GetError()); }

        textureQuad.w = surface->w;
        textureQuad.h = surface->h;

        textureCenterX = textureQuad.x + (textureQuad.w / 2);
        textureCenterY = textureQuad.y + (textureQuad.h / 2);

        SDL_FreeSurface(surface);

        mTexture = texture;

        return mTexture != nullptr;
    }

    void Texture::SetColor(SDL_Color color)
    { SDL_SetTextureColorMod(mTexture, color.r, color.g, color.b); }

    void Texture::SetBlendMode(SDL_BlendMode blendMode)
    { SDL_SetTextureBlendMode(mTexture, blendMode); }

    void Texture::SetAlpha(uint8_t a)
    { SDL_SetTextureAlphaMod(mTexture, a); }

    void Texture::SetPosition(int x, int y)
    {
        textureQuad.x = x;
        textureQuad.y = y;
    }

    void Texture::Render(SDL_Rect *clip)
    {
        if (clip != nullptr)
        {
            textureQuad.w = clip->w;
            textureQuad.h = clip->h;
        }

        SDL_RenderCopy(mRenderer, mTexture, clip, &textureQuad);
    }

    void Texture::Destroy()
    {
        if (mTexture != nullptr)
        {
            WARNING("destroying texture from file ", mFilepath, "...");

            SDL_DestroyTexture(mTexture);

            textureQuad = { 0, 0, 0, 0 };

            mFilepath = nullptr;
        }
    }
}
