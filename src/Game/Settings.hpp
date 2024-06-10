#ifndef SETTINGS
#define SETTINGS

#include "Globals.hpp"

#include <fstream>
#include <filesystem>
#include <ios>

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

    void WriteToSettings()
    {
        LOG("writing to settings file...");

        // open settings file in overwrite mode.
        settings->file.open(settings->filepath, std::ios_base::out);
        if (!settings->file.is_open())
        { ERROR("failed to open settings file for writing!"); }

        // write "true" or "false" based on value of settings
        // variables to settings file.
        settings->file << "fullscreen = " << (settings->fullscreen ? "true" : "false") << std::endl;
        settings->file << "vsync = " << (settings->vsync ? "true" : "false") << std::endl;
        settings->file << "showFPS = " << (settings->showFPS ? "true" : "false") << std::endl;

        // close settings file after writing.
        settings->file.close();
    }

    void ReadFromSettings()
    {
        LOG("reading from settings file...");

        // open the file in read mode.
        settings->file.open(settings->filepath, std::ios_base::in);
        if (!settings->file.is_open())
        { ERROR("failed to open settings file for reading!"); }

        // if settings file is empty, set variables to defaults,
        // they'll be written to the file on scene switch.
        // if not empty, read all lines and set variables based
        // on true or false values.
        if (std::filesystem::is_empty(settings->filepath))
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
            while (std::getline(settings->file, line))
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

        // close the file after reading,
        // writing will open the file in different
        // modes.
        settings->file.close();
    }

    void OnStart() override
    {
        // if file does not exist, create it without
        // writing anything to it and close file
        // immediately.
        if (!std::filesystem::exists(settings->filepath))
        {
            std::ofstream f(settings->filepath);
            f.close();
        }

        // read and set settings variables,
        // check function definition for more info.
        ReadFromSettings();

        LOG(fullscreen);
        LOG(vsync);
        LOG(showFPS);

        // create cc::Text objects for settings and
        // exit option.
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
        // destroy cc::Text objects.
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
                        gv->selectSFX.Play();
                        WriteToSettings();
                        SwitchScene("mainMenu");
                        break;

                    case cc::Keyboard::CCK_F:
                        gv->selectSFX.Play();
                        settings->fullscreen = !settings->fullscreen;
                        window->ToggleFullscreen(settings->fullscreen);
                        fullscreenYN = (settings->fullscreen ? "Y" : "N");
                        fullscreen = "F: Fullscreen = ";
                        fullscreen.append(fullscreenYN);
                        fullscreenText.Update(fullscreen.c_str(),
                            gv->fontBig.font,
                            { 255, 255, 255 },
                            SCREEN_WIDTH / 2,
                            100);
                        break;

                    case cc::Keyboard::CCK_V:
                        gv->selectSFX.Play();
                        settings->vsync = !settings->vsync;
                        window->ToggleVSync(settings->vsync);
                        vsyncYN = (settings->vsync ? "Y" : "N");
                        vsync = "V: VSync = ";
                        vsync.append(vsyncYN);
                        vsyncText.Update(vsync.c_str(),
                            gv->fontBig.font,
                            { 255, 255, 255 },
                            SCREEN_WIDTH / 2,
                            200);
                        break;

                    case cc::Keyboard::CCK_S:
                        gv->selectSFX.Play();
                        settings->showFPS = !settings->showFPS;
                        gv->showDebug = !gv->showDebug;
                        showFPSYN = (settings->showFPS ? "Y" : "N");
                        showFPS = "S: Show FPS = ";
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

        gv->selectSFX.Expire();

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
