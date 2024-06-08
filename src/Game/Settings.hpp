#ifndef SETTINGS
#define SETTINGS

#include "Globals.hpp"

#include <fstream>

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

    std::string fullscreen = "F: Fullscreen = ";
    std::string vsync = "V: VSync = ";
    std::string showFPS = "S: Show FPS = ";

    std::string fullscreenYN;
    std::string vsyncYN;
    std::string showFPSYN;

    std::fstream settingsFile;

    void WriteToSettings()
    {
        LOG("writing to settings file...");

        settingsFile << "fullscreen = " << (settings->fullscreen ? "true" : "false") << std::endl;
        settingsFile << "vsync = " << (settings->vsync ? "true" : "false") << std::endl;
        settingsFile << "showFPS = " << (settings->showFPS ? "true" : "false") << std::endl;
    }

    void ReadFromSettings()
    {
        LOG("reading from settings file...");

        if (settingsFile.peek() == std::fstream::traits_type::eof())
        {
            WARNING("variables in settings file not found! Setting to defaults:\n\tfullscreen = false\n\tvsync = true\n\tshowFPS = false");

            settings->fullscreen = false;
            settings->vsync = true;
            settings->showFPS = false;

            fullscreenYN = "N";
            vsyncYN = "Y";
            showFPSYN = "N";

            fullscreen.append(fullscreenYN);
            vsync.append(vsyncYN);
            showFPS.append(showFPSYN);
        }
        else
        {
            std::string line;
            while (std::getline(settingsFile, line))
            {
                if (line.find("fullscreen = true") != std::string::npos)
                {
                    settings->fullscreen = true;
                    fullscreen = "F: Fullscreen = ";
                    fullscreenYN = "Y";
                    fullscreen.append(fullscreenYN);
                }
                else if (line.find("fullscreen = false") != std::string::npos)
                {
                    settings->fullscreen = false;
                    fullscreen = "F: Fullscreen = ";
                    fullscreenYN = "N";
                    fullscreen.append(fullscreenYN);
                }
                else if (line.find("vsync = true") != std::string::npos)
                {
                    settings->vsync = true;
                    vsync = "V: VSync = ";
                    vsyncYN = "Y";
                    vsync.append(vsyncYN);
                }
                else if (line.find("vsync = false") != std::string::npos)
                {
                    settings->vsync = false;
                    vsync = "V: VSync = ";
                    vsyncYN = "N";
                    vsync.append(vsyncYN);
                }
                else if (line.find("showFPS = true") != std::string::npos)
                {
                    settings->showFPS = true;
                    showFPS = "S: ShowFPS = ";
                    showFPSYN = "Y";
                    showFPS.append(showFPSYN);
                }
                else if (line.find("showFPS = false") != std::string::npos)
                {
                    settings->showFPS = false;
                    showFPS = "S: ShowFPS = ";
                    showFPSYN = "N";
                    showFPS.append(showFPSYN);
                }
            }
        }
    }

    void OnStart() override
    {
        LOG("opening settings file...");
        settingsFile.open(settings->settingsFilepath);
        if (!settingsFile.is_open())
        { ERROR("failed to open settings file!"); }

        ReadFromSettings();

        fullscreenText.Create(window->GetRenderer(),
                            fullscreen.c_str(),
                            gv->fontBig.font,
                            { 255, 255, 255 },
                            SCREEN_WIDTH / 2,
                            100,
                            cc::Text::Alignment::CENTER);

        vsyncText.Create(window->GetRenderer(),
                            vsync.c_str(),
                            gv->fontBig.font,
                            { 255, 255, 255 },
                            SCREEN_WIDTH / 2,
                            200,
                            cc::Text::Alignment::CENTER);

        showFPSText.Create(window->GetRenderer(),
                            showFPS.c_str(),
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

        LOG("closing settings file...");
        settingsFile.close();
        if (settingsFile.is_open())
        { ERROR("failed to close settings file!"); }
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
                        WriteToSettings();
                        SwitchScene("mainMenu");
                        break;

                    case cc::Keyboard::CCK_F:
                        settings->fullscreen = !settings->fullscreen;
                        fullscreenYN = (settings->fullscreen ? "Y" : "N");
                        fullscreen.append(fullscreenYN);
                        fullscreenText.Update(fullscreen.c_str(),
                            gv->fontBig.font,
                            { 255, 255, 255 },
                            SCREEN_WIDTH / 2,
                            100);
                        break;

                    case cc::Keyboard::CCK_V:
                        settings->vsync = !settings->vsync;
                        vsyncYN = (settings->vsync ? "Y" : "N");
                        vsync.append(vsyncYN);
                        vsyncText.Update(vsync.c_str(),
                            gv->fontBig.font,
                            { 255, 255, 255 },
                            SCREEN_WIDTH / 2,
                            200);
                        break;

                    case cc::Keyboard::CCK_S:
                        settings->showFPS = !settings->showFPS;
                        showFPSYN = (settings->showFPS ? "Y" : "N");
                        showFPS.append(showFPSYN);
                        showFPSText.Update(showFPS.c_str(),
                            gv->fontBig.font,
                            { 255, 255, 255 },
                            SCREEN_WIDTH / 2,
                            300);
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
