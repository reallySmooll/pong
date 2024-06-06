#ifndef MAIN_MENU
#define MAIN_MENU

#include "Globals.hpp"

struct MainMenuScene : public cc::Scene
{
    using cc::Scene::Scene;

    cc::Window *window = cc::Window::GetInstance();

    cc::Text mainMenuText;
    cc::Text playerVsPlayerText;
    cc::Text optionsText;
    cc::Text exitText;

    Gamevars *gv = Gamevars::GetInstance();

    void OnCreate() override
    {
        gv->fontSmall.Create(gv->fontFilepath, 36);
        gv->fontBig.Create(gv->fontFilepath, 72);
        gv->fontHuge.Create(gv->fontFilepath, 128);

        gv->ballHitSFX.Load("./resources/sfx/ball_hit.wav");
        gv->selectSFX.Load("./resources/sfx/select.wav");

        gv->DebugCreate();
    }

    void OnDestroy() override
    {
        gv->fontSmall.Destroy();
        gv->fontBig.Destroy();
        gv->fontHuge.Destroy();
    }

    void OnStart() override
    {
        mainMenuText.Create(window->GetRenderer(),
                            "PONG",
                            gv->fontHuge.font,
                            { 255, 255, 255 },
                            SCREEN_WIDTH / 2,
                            SCREEN_HEIGHT / 2 - SCREEN_HEIGHT / 3,
                            cc::Text::Alignment::CENTER);

        playerVsPlayerText.Create(window->GetRenderer(),
                                  "ENTER: Player vs Player",
                                  gv->fontBig.font,
                                  { 255, 255, 255 },
                                  SCREEN_WIDTH / 2,
                                  SCREEN_HEIGHT / 2 - 50,
                                  cc::Text::Alignment::CENTER);

        optionsText.Create(window->GetRenderer(),
                           "S: Settings",
                           gv->fontBig.font,
                           { 255, 255, 255 },
                           SCREEN_WIDTH / 2,
                           SCREEN_HEIGHT / 2 + SCREEN_HEIGHT / 4 - 150,
                           cc::Text::Alignment::CENTER);

        exitText.Create(window->GetRenderer(),
                        "ESCAPE: Exit",
                        gv->fontBig.font,
                        { 255, 255, 255 },
                        SCREEN_WIDTH / 2,
                        SCREEN_HEIGHT / 2 + SCREEN_HEIGHT / 4,
                        cc::Text::Alignment::CENTER);
    }

    void OnExit() override
    {
        mainMenuText.Destroy();
        playerVsPlayerText.Destroy();
        optionsText.Destroy();
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
                        Quit();
                        break;

                    case cc::Keyboard::CCK_RETURN:
                        SwitchScene("game");
                        break;

                    case cc::Keyboard::CCK_S:
                        SwitchScene("settings");
                        break;

                    case cc::Keyboard::CCK_F:
                        window->SetFullscreenOrWindowed();
                        break;

                    case cc::Keyboard::CCK_F3:
                        gv->showDebug = !gv->showDebug;
                        break;

                    case cc::Keyboard::CCK_V:
                        window->EnableVSync();
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
        mainMenuText.Render();
        playerVsPlayerText.Render();
        optionsText.Render();
        exitText.Render();

        gv->DebugRender();
    }
};

#endif // MAIN_MENU
