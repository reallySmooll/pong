#include "CCWindow.hpp"
#include "CCLog.hpp"

#include <SDL2/SDL_hints.h>
#include <cstdint>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <cstdio>

namespace cc
{
    SDL_Window *Window::mWindow = nullptr;

    SDL_Renderer *Window::mRenderer = nullptr;

    int Window::mWidth = 0;
    int Window::mHeight = 0;

    int Window::CC_POSITION_UNDEFINED = SDL_WINDOWPOS_UNDEFINED;
    int Window::CC_POSITION_CENTERED  = SDL_WINDOWPOS_CENTERED;

    uint32_t Window::CC_WINDOW_SHOWN              = SDL_WINDOW_SHOWN;
    uint32_t Window::CC_WINDOW_HIDDEN             = SDL_WINDOW_HIDDEN;
    uint32_t Window::CC_WINDOW_FULLSCREEN         = SDL_WINDOW_FULLSCREEN;
    uint32_t Window::CC_WINDOW_BORDERLESS         = SDL_WINDOW_BORDERLESS;
    uint32_t Window::CC_WINDOW_RESIZABLE          = SDL_WINDOW_RESIZABLE;
    uint32_t Window::CC_WINDOW_MINIMIZED          = SDL_WINDOW_MINIMIZED;
    uint32_t Window::CC_WINDOW_MAXIMIZED          = SDL_WINDOW_MAXIMIZED;
    uint32_t Window::CC_WINDOW_INPUT_FOCUS        = SDL_WINDOW_INPUT_FOCUS;
    uint32_t Window::CC_WINDOW_MOUSE_FOCUS        = SDL_WINDOW_MOUSE_FOCUS;
    uint32_t Window::CC_WINDOW_ALWAYS_ON_TOP      = SDL_WINDOW_ALWAYS_ON_TOP;
    uint32_t Window::CC_WINDOW_SKIP_TASKBAR       = SDL_WINDOW_SKIP_TASKBAR;
    uint32_t Window::CC_WINDOW_FOREIGN            = SDL_WINDOW_FOREIGN;
    uint32_t Window::CC_WINDOW_FULLSCREEN_DESKTOP = SDL_WINDOW_FULLSCREEN_DESKTOP;
    uint32_t Window::CC_WINDOW_ALLOW_HIGHDPI      = SDL_WINDOW_ALLOW_HIGHDPI;

    void Window::Create(const char *title, int width, int height, int x, int y, uint32_t flags)
    {
        mTitle = title;
        mWidth = width;
        mHeight = height;
        mX = x;
        mY = y;
        mFlags = flags;

        // initialize sdl
        LOG("initializing sdl...");
        if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
        { ERROR("could not initialize sdl!\n\terror: ", SDL_GetError()); }

        // initialize sdl_image
        LOG("initializing sdl_image...");
        int imgFlags = IMG_INIT_PNG;
        if (!(IMG_Init(imgFlags) & imgFlags))
        {
            ERROR("could not initialize sdl_image!\n\tsdl_image error: ", IMG_GetError());
            SDL_Quit();
        }

        // initialize sdl_ttf
        LOG("initializing sdl_ttf...");
        if (TTF_Init() == -1)
        {
            ERROR("could not initialize sdl_ttf!\n\tsdl_ttf error: ", TTF_GetError());
            IMG_Quit();
            SDL_Quit();
        }

        // initialize sdl_mixer
        LOG("initializing sdl_mixer...");
        if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
        {
            ERROR("could not initialize sdl_mixer!\n\tsdl_mixer error: ", Mix_GetError());
            IMG_Quit();
            TTF_Quit();
            SDL_Quit();
        }

        // create window
        LOG("creating window...");
        mWindow = SDL_CreateWindow(mTitle, mX, mY, mWidth, mHeight, mFlags);
        if (mWindow == nullptr)
        {
            ERROR("could not create window!\n\terror: ", SDL_GetError());
            IMG_Quit();
            TTF_Quit();
            Mix_Quit();
            SDL_Quit();
        }

        // create renderer
        LOG("creating renderer...");
        mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        if (mRenderer == nullptr)
        {
            ERROR("could not create renderer!\n\terror: ", SDL_GetError());
            SDL_DestroyWindow(mWindow);
            IMG_Quit();
            TTF_Quit();
            Mix_Quit();
            SDL_Quit();
        }

        // set renderer draw color (background color)
        SDL_SetRenderDrawColor(mRenderer, 0x00, 0x00, 0x00, 0x00);
    }

    void Window::Destroy()
    {
        // close audio playback
        LOG("closing audio playback device...");
        Mix_CloseAudio();

        // destroy renderer
        LOG("destroying renderer...");
        SDL_DestroyRenderer(mRenderer);
        mRenderer = nullptr;

        // destroy window
        LOG("destroying window...");
        SDL_DestroyWindow(mWindow);
        mWindow = nullptr;

        // quit sdl
        LOG("quitting sdl and it's subsystems...");
        IMG_Quit();
        TTF_Quit();
        Mix_Quit();
        SDL_Quit();
    }

    Window::~Window()
    { Destroy(); }

    void Window::SetTitle(const char *title)
    { SDL_SetWindowTitle(mWindow, title); }

    void Window::SetSize(int width, int height)
    { SDL_SetWindowSize(mWindow, width, height); }

    void Window::ToggleFullscreen(bool fullscreen)
    {
        if (!fullscreen)
        { SDL_SetWindowFullscreen(mWindow, 0); }
        else
        { SDL_SetWindowFullscreen(mWindow, SDL_WINDOW_FULLSCREEN); }
    }

    void Window::ToggleVSync(bool vsync)
    {
        if (vsync)
        { SDL_RenderSetVSync(mRenderer, 1); }
        else
        { SDL_RenderSetVSync(mRenderer, 0); }
    }
}
