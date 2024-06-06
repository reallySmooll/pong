#ifndef CC_TIME
#define CC_TIME

#include <cstdint>

namespace cc
{
    class Time
    {
        public:
            void UpdateClock();

            float GetDeltaTime() { return mDeltaTime; }
            float GetFrameTime() { return mFrameTime * 1000.0f; }
        private:
            uint32_t mLastFrameTime = 0;
            uint32_t mLastFPSTime = 0;

            int mFrames = 0;

            float mDeltaTime = 0.0f;
            float mFrameTime = 0.0f;
    };
}

#endif // CC_TIME
