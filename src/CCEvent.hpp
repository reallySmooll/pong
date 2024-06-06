#ifndef CC_EVENT
#define CC_EVENT

#include <SDL2/SDL_events.h>

namespace cc
{
    namespace Event
    {
        using CCEvent = SDL_Event;

        // Event type structs
        using CCCommonEvent           = SDL_CommonEvent;
        using CCDisplayEvent          = SDL_DisplayEvent;
        using CCWindowEvent           = SDL_WindowEvent;
        using CCKeyboardEvent         = SDL_KeyboardEvent;
        using CCTextEditingEvent      = SDL_TextEditingEvent;
        using CCTextInputEvent        = SDL_TextInputEvent;
        using CCMouseMotionEvent      = SDL_MouseMotionEvent;
        using CCMouseButtonEvent      = SDL_MouseButtonEvent;
        using CCMouseWheelEvent       = SDL_MouseWheelEvent;
        using CCJoyAxisEvent          = SDL_JoyAxisEvent;
        using CCJoyBallEvent          = SDL_JoyBallEvent;
        using CCJoyHatEvent           = SDL_JoyHatEvent;
        using CCJoyButtonEvent        = SDL_JoyButtonEvent;
        using CCJoyDeviceEvent        = SDL_JoyDeviceEvent;
        using CCControllerAxisEvent   = SDL_ControllerAxisEvent;
        using CCControllerButtonEvent = SDL_ControllerButtonEvent;
        using CCControllerDeviceEvent = SDL_ControllerDeviceEvent;
        using CCAudioDeviceEvent      = SDL_AudioDeviceEvent;
        using CCQuitEvent             = SDL_QuitEvent;
        using CCUserEvent             = SDL_UserEvent;
        using CCSysWMEvent            = SDL_SysWMEvent;
        using CCTouchFingerEvent      = SDL_TouchFingerEvent;
        using CCMultiGestureEvent     = SDL_MultiGestureEvent;
        using CCDollarGestureEvent    = SDL_DollarGestureEvent;
        using CCDropEvent             = SDL_DropEvent;

        // Event types
        constexpr int CC_FIRSTEVENT                = SDL_FIRSTEVENT;
        constexpr int CC_QUIT                      = SDL_QUIT;
        constexpr int CC_USEREVENT                 = SDL_USEREVENT;
        constexpr int CC_LASTEVENT                 = SDL_LASTEVENT;
        constexpr int CC_WINDOWEVENT               = SDL_WINDOWEVENT;
        constexpr int CC_WINDOWEVENT_SHOWN         = SDL_WINDOWEVENT_SHOWN;
        constexpr int CC_WINDOWEVENT_HIDDEN        = SDL_WINDOWEVENT_HIDDEN;
        constexpr int CC_WINDOWEVENT_EXPOSED       = SDL_WINDOWEVENT_EXPOSED;
        constexpr int CC_WINDOWEVENT_MOVED         = SDL_WINDOWEVENT_MOVED;
        constexpr int CC_WINDOWEVENT_RESIZED       = SDL_WINDOWEVENT_RESIZED;
        constexpr int CC_WINDOWEVENT_SIZE_CHANGED  = SDL_WINDOWEVENT_SIZE_CHANGED;
        constexpr int CC_WINDOWEVENT_MINIMIZED     = SDL_WINDOWEVENT_MINIMIZED;
        constexpr int CC_WINDOWEVENT_MAXIMIZED     = SDL_WINDOWEVENT_MAXIMIZED;
        constexpr int CC_WINDOWEVENT_RESTORED      = SDL_WINDOWEVENT_RESTORED;
        constexpr int CC_WINDOWEVENT_ENTER         = SDL_WINDOWEVENT_ENTER;
        constexpr int CC_WINDOWEVENT_LEAVE         = SDL_WINDOWEVENT_LEAVE;
        constexpr int CC_WINDOWEVENT_FOCUS_GAINED  = SDL_WINDOWEVENT_FOCUS_GAINED;
        constexpr int CC_WINDOWEVENT_FOCUS_LOST    = SDL_WINDOWEVENT_FOCUS_LOST;
        constexpr int CC_WINDOWEVENT_HIT_TEST      = SDL_WINDOWEVENT_HIT_TEST;
        constexpr int CC_WINDOWEVENT_TAKE_FOCUS    = SDL_WINDOWEVENT_TAKE_FOCUS;
        constexpr int CC_WINDOWEVENT_CLOSE         = SDL_WINDOWEVENT_CLOSE;
        constexpr int CC_DISPLAYEVENT              = SDL_DISPLAYEVENT;
        constexpr int CC_DISPLAYEVENT_CONNECTED    = SDL_DISPLAYEVENT_CONNECTED;
        constexpr int CC_DISPLAYEVENT_DISCONNECTED = SDL_DISPLAYEVENT_DISCONNECTED;
        constexpr int CC_MOUSEMOTION               = SDL_MOUSEMOTION;
        constexpr int CC_MOUSEBUTTONDOWN           = SDL_MOUSEBUTTONDOWN;
        constexpr int CC_MOUSEBUTTONUP             = SDL_MOUSEBUTTONUP;
        constexpr int CC_MOUSEWHEEL                = SDL_MOUSEWHEEL;
        constexpr int CC_MULTIGESTURE              = SDL_MULTIGESTURE;
        constexpr int CC_KEYDOWN                   = SDL_KEYDOWN;
        constexpr int CC_KEYUP                     = SDL_KEYUP;
        constexpr int CC_TEXTEDITING               = SDL_TEXTEDITING;
        constexpr int CC_TEXTINPUT                 = SDL_TEXTINPUT;
        constexpr int CC_JOYAXISMOTION             = SDL_JOYAXISMOTION;
        constexpr int CC_JOYBALLMOTION             = SDL_JOYBALLMOTION;
        constexpr int CC_JOYHATMOTION              = SDL_JOYHATMOTION;
        constexpr int CC_JOYBUTTONDOWN             = SDL_JOYBUTTONDOWN;
        constexpr int CC_JOYBUTTONUP               = SDL_JOYBUTTONUP;
        constexpr int CC_JOYDEVICEADDED            = SDL_JOYDEVICEADDED;
        constexpr int CC_JOYDEVICEREMOVED          = SDL_JOYDEVICEREMOVED;
        constexpr int CC_CONTROLLERAXISMOTION      = SDL_CONTROLLERAXISMOTION;
        constexpr int CC_CONTROLLERBUTTONDOWN      = SDL_CONTROLLERBUTTONDOWN;
        constexpr int CC_CONTROLLERBUTTONUP        = SDL_CONTROLLERBUTTONUP;
        constexpr int CC_CONTROLLERDEVICEADDED     = SDL_CONTROLLERDEVICEADDED;
        constexpr int CC_CONTROLLERDEVICEREMOVED   = SDL_CONTROLLERDEVICEREMOVED;
        constexpr int CC_FINGERMOTION              = SDL_FINGERMOTION;
        constexpr int CC_FINGERDOWN                = SDL_FINGERDOWN;
        constexpr int CC_FINGERUP                  = SDL_FINGERUP;
        constexpr int CC_AUDIODEVICEADDED          = SDL_AUDIODEVICEADDED;
        constexpr int CC_AUDIODEVICEREMOVED        = SDL_AUDIODEVICEREMOVED;
        constexpr int CC_SENSORUPDATE              = SDL_SENSORUPDATE;
        constexpr int CC_SYSWMEVENT                = SDL_SYSWMEVENT;
        constexpr int CC_DROPBEGIN                 = SDL_DROPBEGIN;
        constexpr int CC_DROPCOMPLETE              = SDL_DROPCOMPLETE;

        int PollEvent(CCEvent *event);
    }
}

#endif // CC_EVENT
