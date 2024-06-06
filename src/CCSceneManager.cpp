#include "CCSceneManager.hpp"
#include "CCKeyboard.hpp"
#include "CCScene.hpp"
#include "CCWindow.hpp"
#include "CCLog.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>

#include <string>

namespace cc
{
    const std::string &_end_cc = "_end_cc";

    SceneManager::~SceneManager()
    {
        for (auto &scene : mScenes)
        { scene.second()->OnDestroy(); }
    }

    void SceneManager::SwitchScene(const std::string &name)
    {
        if (mCurrentScene->mSceneName != name)
        {
            auto scene = mScenes.find(name);
            if (scene == nullptr)
            {
                ERROR("Scene with id: ", name, " does not exist!");
                exit(-1);
            }
            else
            {
                mCurrentScene = scene->second();
                mCurrentScene->OnCreate();
            }
        }
    }

    void SceneManager::Run()
    {
        bool running = true;

        mCurrentScene = mScenes.begin()->second();
        mCurrentScene->OnCreate();

        while (running)
        {
            if (mCurrentScene->mSceneName != _end_cc)
            {
                if (mCurrentScene != nullptr)
                {
                    if (!mCurrentScene->started)
                    {
                        mCurrentScene->OnStart();
                        mCurrentScene->started = true;
                        mCurrentScene->mQuitting = false;
                    }

                    mCurrentScene->OnHandleInput();

                    mCurrentScene->keyStates = cc::Keyboard::GetKeyboardState();
                    if (!mCurrentScene->handleKeyStatesAlone)
                    { mCurrentScene->OnHandleKeyStates(); }

                    mCurrentScene->OnUpdate();

                    SDL_RenderClear(cc::Window::GetInstance()->GetRenderer());

                    mCurrentScene->OnRender();

                    SDL_RenderPresent(cc::Window::GetInstance()->GetRenderer());

                    if (mCurrentScene->mQuitting)
                    {
                        mCurrentScene->OnExit();
                        mCurrentScene->started = false;
                        mCurrentScene->mQuitting = true;
                    }
                }
            }
            else
            { running = false; }
        }
    }
}
