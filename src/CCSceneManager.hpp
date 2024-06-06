#ifndef CC_SCENEMANAGER
#define CC_SCENEMANAGER

#include "CCScene.hpp"
#include "CCLog.hpp"
#include "CCWindow.hpp"

#include <cstring>
#include <functional>
#include <string>
#include <unordered_map>
#include <cstring>

namespace cc
{
    extern const std::string &_end_cc;

    class SceneManager
    {
        public:
            ~SceneManager();

            template <typename TScene>
            void Add(const std::string &name)
            {
                if (name == _end_cc)
                {
                    ERROR("Scene cannot have this name. It has been reserved internally for exiting the game. Please choose another name.");
                    cc::Window::GetInstance()->Destroy();
                }
                else
                {
                    if (mScenes.find(name) != mScenes.end())
                    { WARNING("Scene with name: ", name, " already exists. Overwriting..."); }
                    mScenes[name] = [name]() { return new TScene(name); };
                    LOG("Scene: \"", name, "\" added!");
                }
            }

            void SwitchScene(const std::string &name);
            void Run();

            static SceneManager *GetInstance()
            {
                static SceneManager instance;
                return &instance;
            }
        private:
            friend class Scene;

            std::unordered_map<std::string, std::function<Scene *(void)>> mScenes;

            Scene *mCurrentScene = nullptr;
    };
}

#endif // CC_SCENEMANAGER
