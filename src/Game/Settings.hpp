#ifndef SETTINGS
#define SETTINGS

#include "Globals.hpp"

#include <fstream>
#include <stdexcept>

class SettingsScene : public cc::Scene
{
    using cc::Scene::Scene;

    cc::Window *window = cc::Window::GetInstance();

    Gamevars *gv = Gamevars::GetInstance();
    Gamevars::Settings *settings = Gamevars::Settings::GetInstance();

    cc::Text fullscreenText;
    cc::Text vsyncText;
    cc::Text showFPSText;
    cc::Text exitText;

    //std::fstream settingsFile;

    //void OnCreate() override
    //{
    //    settingsFile.open(settings->settingsFilepath);
    //    if (!settingsFile.is_open())
    //    { throw std::runtime_error("failed to open settings file!"); }
    //}

    //void OnDestroy() override
    //{
    //    settingsFile.close();
    //    if (settingsFile.is_open())
    //    { throw std::runtime_error("failed to close settings file!"); }
    //}

    void OnStart() override
    {
        fullscreenText.Create(window->GetRenderer(),
                            "F: Fullscreen = N",
                            gv->fontBig.font,
                            { 255, 255, 255 },
                            SCREEN_WIDTH / 2,
                            100,
                            cc::Text::Alignment::CENTER);

        vsyncText.Create(window->GetRenderer(),
                            "V: VSync = Y",
                            gv->fontBig.font,
                            { 255, 255, 255 },
                            SCREEN_WIDTH / 2,
                            200,
                            cc::Text::Alignment::CENTER);

        showFPSText.Create(window->GetRenderer(),
                            "S: Show FPS = N",
                            gv->fontBig.font,
                            { 255, 255, 255 },
                            SCREEN_WIDTH / 2,
                            300,
                            cc::Text::Alignment::CENTER);

        exitText.Create(window->GetRenderer(),
                            "ESCAPE: Back to main menu",
                            gv->fontBig.font,
                            { 255, 255, 255 },
                            SCREEN_WIDTH / 2,
                            SCREEN_HEIGHT / 2 + SCREEN_HEIGHT / 4,
                            cc::Text::Alignment::CENTER);
    }

    void OnExit() override
    {
        fullscreenText.Destroy(); 
        vsyncText.Destroy();
        showFPSText.Destroy();
        exitText.Destroy();
    }

    void OnHandleInput() override
    {
        while (cc::Event::PollEvent(&gv->e))
        {
            if (gv->e.type == cc::Event::CC_QUIT)
            { Quit(); }
            if (gv->e.type == cc::Event::CC_KEYDOWN)
            {
                switch (gv->e.key.keysym.sym)
                {
                    case cc::Keyboard::CCK_ESCAPE:
                        SwitchScene("mainMenu");
                        break;

                    default:
                        break;
                }
            }
        }
    }

    void OnUpdate() override
    {
        gv->gTime.UpdateClock();

        gv->DebugUpdate();
    }

    void OnRender() override
    {
        fullscreenText.Render();
        vsyncText.Render();
        showFPSText.Render();
        exitText.Render();

        gv->DebugRender();
    }
};

#endif // SETTINGS
