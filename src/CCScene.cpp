#include "CCScene.hpp"
#include "CCSceneManager.hpp"

namespace cc
{
    void Scene::SwitchScene(const std::string &name)
    {
        mQuitting = true;
        cc::SceneManager::GetInstance()->SwitchScene(name);
    }

    void Scene::Quit()
    { mSceneName = _end_cc; }
}
