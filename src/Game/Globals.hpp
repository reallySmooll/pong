#ifndef GLOBALS
#define GLOBALS

#include <fstream>
#include <string>

#include "../CC.hpp"

constexpr int SCREEN_WIDTH = 1280;
constexpr int SCREEN_HEIGHT = 720;

struct Gamevars
{
    struct Settings
    {
        std::fstream file;

        std::string filepath = "./resources/.settings";

        bool fullscreen;
        bool vsync;
        bool showFPS;

        static Settings *GetInstance()
        {
            static Settings instance;
            return &instance;
        }
    };

    float speed = 800.0f;

    std::string deltaTimeText = "DT: ";
    std::string frameTimeText = "FPS: ";

    const char *fontFilepath = "./resources/fonts/pixel-coleco-font/PixelColeco.ttf";

    bool showDebug = false;

    float timeStep = 1.0f / 60.0f;
    float accumulatedTime = 0.0f;

    cc::Window *gWindow = cc::Window::GetInstance();

    cc::Time gTime;

    cc::Font fontSmall;
    cc::Font fontBig;
    cc::Font fontHuge;

    cc::Text deltaTimeDebug;
    cc::Text frameTimeDebug;

    cc::Audio::SFX ballHitSFX;
    cc::Audio::SFX selectSFX;

    cc::Event::CCEvent e;

    static Gamevars *GetInstance()
    {
        static Gamevars gv;
        return &gv;
    }

    void SetWindow(cc::Window *window)
    { gWindow = window; }

    void DebugCreate()
    {
        deltaTimeDebug.Create(gWindow->GetRenderer(), deltaTimeText.c_str(), fontSmall.font, { 255, 255, 255 });
        frameTimeDebug.Create(gWindow->GetRenderer(), frameTimeText.c_str(), fontSmall.font, { 255, 255, 255 }, 0, 36);
    }

    void DebugUpdate()
    {
        if (showDebug)
        {
            deltaTimeText = "DT: ";
            frameTimeText = "FPS: ";

            deltaTimeText.append(std::to_string(gTime.GetDeltaTime()));
            frameTimeText.append(std::to_string(gTime.GetFrameTime()));

            deltaTimeDebug.Update(deltaTimeText.c_str(), fontSmall.font, { 255, 255, 255 }, 0, 0);
            frameTimeDebug.Update(frameTimeText.c_str(), fontSmall.font, { 255, 255, 255 }, 0, 36);
        }
    }

    void DebugRender()
    {
        if (showDebug)
        {
            deltaTimeDebug.Render();
            frameTimeDebug.Render();
        }
    }

    void DebugDestroy()
    {
        deltaTimeDebug.Destroy();
        frameTimeDebug.Destroy();
    }
};

#endif // GLOBALS
