#ifndef CC_TEXT
#define CC_TEXT

#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_ttf.h>

namespace cc
{
    class Text
    {
        public:
            enum Alignment { LEFT, CENTER };

            ~Text();

            void Create(SDL_Renderer *renderer, const char *text, TTF_Font *font, SDL_Color color = { 255, 255, 255 }, int x = 0, int y = 0, Alignment textAlignment = Alignment::LEFT);
            void Update(const char *text, TTF_Font *font, SDL_Color color = { 255, 255, 255 }, int x = 0, int y = 0);
            void SetX(int x = 0);
            void SetY(int y = 0);
            void SetPosition(int x = 0, int y = 0);
            void SetAlignment(Alignment textAlignment);
            void Render();
            void Destroy();

            int TEXT_WIDTH  = 0;
            int TEXT_HEIGHT = 0;
            int TEXT_CENTER_W = 0;
            int TEXT_CENTER_H = 0;
        private:
            void OnCreate(SDL_Renderer *renderer, const char *text, TTF_Font *font, SDL_Color color, int x, int y, Alignment textAlignment);

            SDL_Surface *mTextSurface = nullptr;

            SDL_Texture *mTextTexture = nullptr;

            SDL_Rect mTextRect;

            SDL_Renderer *mRenderer = nullptr;

            TTF_Font *mFont = nullptr;

            const char *mText = nullptr;

            int mTextOffsetX = 0;

            int mX = 0;
            int mY = 0;

            SDL_Color mColor = { 255, 255, 255 };

            Alignment mAlignment = LEFT;
    };
}

#endif // CC_TEXT
