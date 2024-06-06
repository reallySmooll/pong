#ifndef CC_FONT
#define CC_FONT

#include <SDL2/SDL_ttf.h>

namespace cc
{
    class Font
    {
        public:
            ~Font();

            void Create(const char *filepath, int fontSize);
            void SetSize(int fontSize);
            void Destroy();

            TTF_Font *font = nullptr;
        private:
            const char *mFilepath = nullptr;
    };
}

#endif // CC_FONT
