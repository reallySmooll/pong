#ifndef CC_SCENE
#define CC_SCENE

#include <cstdint>
#include <string>

namespace cc
{
    class Scene
    {
        public:
            Scene(const std::string &name) : mSceneName(name) { }

            virtual void OnCreate() { }
            virtual void OnDestroy() { }
            virtual void OnStart() { };
            virtual void OnExit() { };
            virtual void OnHandleInput() { };
            virtual void OnHandleKeyStates() { };
            virtual void OnUpdate() { };
            virtual void OnRender() { };

            void SwitchScene(const std::string &name);
            void Quit();

            const uint8_t *keyStates = nullptr;

            bool handleKeyStatesAlone = false;
            bool started = false;
        private:
            friend class SceneManager;

            bool mQuitting = false;
        protected:
            std::string mSceneName = "";
    };
}

#endif // CC_SCENE
