#include "CCTime.hpp"

#include <SDL2/SDL_timer.h>

#include <cstdint>

namespace cc
{
    void Time::UpdateClock()
    {
        mFrames++;

        const uint32_t currentFrameTime = SDL_GetTicks();
        mDeltaTime = (float)(currentFrameTime - mLastFrameTime) / 1000.0f;
        mLastFrameTime = currentFrameTime;

        if ((currentFrameTime - mLastFPSTime) >= 1000)
        {
            mFrameTime = ((float)mFrames / (float)(currentFrameTime - mLastFPSTime));
            mLastFPSTime = currentFrameTime;
            mFrames = 0;
        }
    }
}
