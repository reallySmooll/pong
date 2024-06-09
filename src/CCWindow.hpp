#ifndef CC_WINDOW
#define CC_WINDOW

#include <cstdint>

#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>

namespace cc
{
    class Window
    {
        public:
            ~Window();

            void Create(const char *title = nullptr, int width = 0, int height = 0, int x = SDL_WINDOWPOS_CENTERED, int y = SDL_WINDOWPOS_CENTERED, uint32_t flags = SDL_WINDOW_SHOWN);
            void Destroy();

            static SDL_Window *GetWindow() { return mWindow; }

            static SDL_Renderer *GetRenderer() { return mRenderer; }

            const char *GetTitle() { return mTitle; }

            static int GetWidth() { return mWidth; }
            static int GetHeight() { return mHeight; }

            void SetTitle(const char *title);
            void SetSize(int width, int height);

            void ToggleFullscreen(bool fullscreen = false);
            void ToggleVSync(bool vsync = true);

            static Window *GetInstance()
            {
                static Window window;
                return &window;
            }

            static int CC_POSITION_UNDEFINED;
            static int CC_POSITION_CENTERED;

            static uint32_t CC_WINDOW_SHOWN;
            static uint32_t CC_WINDOW_HIDDEN;
            static uint32_t CC_WINDOW_FULLSCREEN;
            static uint32_t CC_WINDOW_BORDERLESS;
            static uint32_t CC_WINDOW_RESIZABLE;
            static uint32_t CC_WINDOW_MINIMIZED;
            static uint32_t CC_WINDOW_MAXIMIZED;
            static uint32_t CC_WINDOW_INPUT_FOCUS;
            static uint32_t CC_WINDOW_MOUSE_FOCUS;
            static uint32_t CC_WINDOW_ALWAYS_ON_TOP;
            static uint32_t CC_WINDOW_SKIP_TASKBAR;
            static uint32_t CC_WINDOW_FOREIGN;
            static uint32_t CC_WINDOW_FULLSCREEN_DESKTOP;
            static uint32_t CC_WINDOW_ALLOW_HIGHDPI;
        private:
            static SDL_Window *mWindow;

            static SDL_Renderer *mRenderer;

            const char *mTitle = "";

            static int mWidth;
            static int mHeight;

            int mX = 0;
            int mY = 0;

            uint32_t mFlags = 0;
    };
}

#endif // CC_WINDOW
