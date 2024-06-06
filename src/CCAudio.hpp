#ifndef CC_AUDIO
#define CC_AUDIO

#include <SDL2/SDL_mixer.h>

namespace cc
{
    namespace Audio
    {
        class Music
        {
            public:
                ~Music();

                void Load(const char *filepath);

                void Resume();
                void Pause();

                int Stop();
                int Play(int loops = 0);
                int Volume(int volume);

                void Destroy();
            private:
                Mix_Music *mMusic = nullptr;

                const char *mFilepath = nullptr;
        };

        class SFX
        {
            public:
                ~SFX();

                void Load(const char *filepath, int channel = -1);

                void Resume();
                void Pause();

                int Stop();
                int Play(int loops = 0);
                int Volume(int volume);
                int Expire();

                void Destroy();
            private:
                Mix_Chunk *mSFX = nullptr;

                const char *mFilepath = nullptr;

                int mChannel = -1;
        };
    }
}

#endif // CC_AUDIO
