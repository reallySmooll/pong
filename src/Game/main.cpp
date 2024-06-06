#include "MainMenu.hpp"
#include "Game.hpp"
#include "Settings.hpp"
#include "Globals.hpp"

int main()
{
    cc::Window *window = cc::Window::GetInstance();
    window->Create("Pong", SCREEN_WIDTH, SCREEN_HEIGHT);

    cc::SceneManager *sm = cc::SceneManager::GetInstance();

    sm->Add<GameScene>("game");
    sm->Add<SettingsScene>("settings");

    sm->Add<MainMenuScene>("mainMenu");

    sm->Run();

    return 0;
}
