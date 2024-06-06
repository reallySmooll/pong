#include "CCAudio.hpp"
#include "CCLog.hpp"

#include <SDL2/SDL_mixer.h>

namespace cc
{
    namespace Audio
    {
        // Music
        Music::~Music()
        {
            if (mMusic != nullptr)
            { Destroy(); }
            else
            { WARNING("failed to free song! song already freed."); }
        }

        void Music::Load(const char *filepath)
        {
            mFilepath = filepath;

            LOG("loading music file: ", filepath, "...");

            if ((mMusic = Mix_LoadMUS(filepath)) == nullptr)
            { ERROR("failed to load music file: ", filepath, "\n\tsdl_mixer error: ", Mix_GetError()); }
        }

        void Music::Resume()
        { Mix_ResumeMusic(); }

        void Music::Pause()
        { Mix_PauseMusic(); }

        int Music::Stop()
        { return Mix_HaltMusic(); }

        int Music::Play(int loops)
        { return Mix_PlayMusic(mMusic, loops); }

        int Music::Volume(int volume)
        { return Mix_VolumeMusic(volume); }

        void Music::Destroy()
        {
            WARNING("freeing song: ", mFilepath, "...");

            Mix_FreeMusic(mMusic);

            mMusic = nullptr;
            mFilepath = nullptr;
        }

        // SFX
        SFX::~SFX()
        {
            if (mSFX != nullptr)
            { Destroy(); }
        }

        void SFX::Load(const char *filepath, int channel)
        {
            if (channel != -1)
            { mChannel = channel; }

            mFilepath = filepath;

            LOG("loading sfx file: ", filepath, "...");

            if ((mSFX = Mix_LoadWAV(filepath)) == nullptr)
            { ERROR("failed to load sfx file: ", filepath, "\n\tsdl_mixer error: ", Mix_GetError()); }
        }

        void SFX::Resume()
        { Mix_Resume(mChannel); }

        void SFX::Pause()
        { Mix_Pause(mChannel); }

        int SFX::Stop()
        { return Mix_HaltChannel(mChannel); }

        int SFX::Play(int loops)
        {
            if (!Mix_Playing(mChannel))
            { return Mix_PlayChannel(mChannel, mSFX, loops); }
            else
            { return 0; }
        }

        int SFX::Volume(int volume)
        { return Mix_VolumeChunk(mSFX, volume); }

        int SFX::Expire()
        { return Mix_ExpireChannel(mChannel, 0); }

        void SFX::Destroy()
        {
            WARNING("freeing sfx: ", mFilepath, "...");

            Mix_FreeChunk(mSFX);

            mSFX = nullptr;
            mFilepath = nullptr;
            mChannel = -1;
        }
    }
}
