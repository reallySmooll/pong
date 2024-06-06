#ifndef CC_TEXTURE
#define CC_TEXTURE

#include <cstdint>

#include <SDL2/SDL_blendmode.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>

namespace cc
{
    using BlendMode = SDL_BlendMode;
    using Rect = SDL_Rect;
    using Color = SDL_Color;

    class Texture
    {
        public:
            ~Texture();

            bool Create(SDL_Renderer *renderer, const char *filepath);

            // color modulation
            void SetColor(SDL_Color color);

            // set blending
            void SetBlendMode(SDL_BlendMode blendMode);

            // alpha modulation
            void SetAlpha(uint8_t a);

            void SetPosition(int x, int y);

            void Render(SDL_Rect *clip = nullptr);

            void Destroy();

            SDL_Rect textureQuad = { 0, 0, 0, 0 };

            int textureCenterX = 0;
            int textureCenterY = 0;

            static BlendMode BLENDMODE_NONE;
            static BlendMode BLENDMODE_BLEND;
            static BlendMode BLENDMODE_ADD;
            static BlendMode BLENDMODE_MOD;
            static BlendMode BLENDMODE_MUL;
            static BlendMode BLENDMODE_SUB;
            static BlendMode BLENDMODE_MIN;
            static BlendMode BLENDMODE_MAX;
        private:
            SDL_Renderer *mRenderer = nullptr;

            SDL_Texture *mTexture = nullptr;

            const char *mFilepath = nullptr;
    };
}

#endif // CC_TEXTURE
