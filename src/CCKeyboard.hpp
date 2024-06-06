#ifndef CC_KEYBOARD
#define CC_KEYBOARD

#include <cstdint>

#include <SDL2/SDL_keycode.h>
#include <SDL2/SDL_scancode.h>

namespace cc
{
    using CCScancode = SDL_Scancode;

    namespace Keyboard
    {
        constexpr int CCK_BACKSPACE    = SDLK_BACKSPACE;
        constexpr int CCK_TAB          = SDLK_TAB;
        constexpr int CCK_CLEAR        = SDLK_CLEAR;
        constexpr int CCK_RETURN       = SDLK_RETURN;
        constexpr int CCK_PAUSE        = SDLK_PAUSE;
        constexpr int CCK_ESCAPE       = SDLK_ESCAPE;
        constexpr int CCK_SPACE        = SDLK_SPACE;
        constexpr int CCK_EXCLAIM      = SDLK_EXCLAIM;
        constexpr int CCK_QUOTEDBL     = SDLK_QUOTEDBL;
        constexpr int CCK_HASH         = SDLK_HASH;
        constexpr int CCK_DOLLAR       = SDLK_DOLLAR;
        constexpr int CCK_AMPERSAND    = SDLK_AMPERSAND;
        constexpr int CCK_QUOTE        = SDLK_QUOTE;
        constexpr int CCK_LEFTPAREN    = SDLK_LEFTPAREN;
        constexpr int CCK_RIGHTPAREN   = SDLK_RIGHTPAREN;
        constexpr int CCK_ASTERISK     = SDLK_ASTERISK;
        constexpr int CCK_PLUS         = SDLK_PLUS;
        constexpr int CCK_COMMA        = SDLK_COMMA;
        constexpr int CCK_MINUS        = SDLK_MINUS;
        constexpr int CCK_PERIOD       = SDLK_PERIOD;
        constexpr int CCK_SLASH        = SDLK_SLASH;
        constexpr int CCK_0            = SDLK_0;
        constexpr int CCK_1            = SDLK_1;
        constexpr int CCK_2            = SDLK_2;
        constexpr int CCK_3            = SDLK_3;
        constexpr int CCK_4            = SDLK_4;
        constexpr int CCK_5            = SDLK_5;
        constexpr int CCK_6            = SDLK_6;
        constexpr int CCK_7            = SDLK_7;
        constexpr int CCK_8            = SDLK_8;
        constexpr int CCK_9            = SDLK_9;
        constexpr int CCK_COLON        = SDLK_COLON;
        constexpr int CCK_SEMICOLON    = SDLK_SEMICOLON;
        constexpr int CCK_LESS         = SDLK_LESS;
        constexpr int CCK_EQUALS       = SDLK_EQUALS;
        constexpr int CCK_GREATER      = SDLK_GREATER;
        constexpr int CCK_QUESTION     = SDLK_QUESTION;
        constexpr int CCK_AT           = SDLK_AT;
        constexpr int CCK_LEFTBRACKET  = SDLK_LEFTBRACKET;
        constexpr int CCK_BACKSLASH    = SDLK_BACKSLASH;
        constexpr int CCK_RIGHTBRACKET = SDLK_RIGHTBRACKET;
        constexpr int CCK_CARET        = SDLK_CARET;
        constexpr int CCK_UNDERSCORE   = SDLK_UNDERSCORE;
        constexpr int CCK_BACKQUOTE    = SDLK_BACKQUOTE;
        constexpr int CCK_A            = SDLK_a;
        constexpr int CCK_B            = SDLK_b;
        constexpr int CCK_C            = SDLK_c;
        constexpr int CCK_D            = SDLK_d;
        constexpr int CCK_E            = SDLK_e;
        constexpr int CCK_F            = SDLK_f;
        constexpr int CCK_G            = SDLK_g;
        constexpr int CCK_H            = SDLK_h;
        constexpr int CCK_I            = SDLK_i;
        constexpr int CCK_J            = SDLK_j;
        constexpr int CCK_K            = SDLK_k;
        constexpr int CCK_L            = SDLK_l;
        constexpr int CCK_M            = SDLK_m;
        constexpr int CCK_N            = SDLK_n;
        constexpr int CCK_O            = SDLK_o;
        constexpr int CCK_P            = SDLK_p;
        constexpr int CCK_Q            = SDLK_q;
        constexpr int CCK_R            = SDLK_r;
        constexpr int CCK_S            = SDLK_s;
        constexpr int CCK_T            = SDLK_t;
        constexpr int CCK_U            = SDLK_u;
        constexpr int CCK_V            = SDLK_v;
        constexpr int CCK_W            = SDLK_w;
        constexpr int CCK_X            = SDLK_x;
        constexpr int CCK_Y            = SDLK_y;
        constexpr int CCK_Z            = SDLK_z;
        constexpr int CCK_DELETE       = SDLK_DELETE;
        constexpr int CCK_KP0          = SDLK_KP_0;
        constexpr int CCK_KP1          = SDLK_KP_1;
        constexpr int CCK_KP2          = SDLK_KP_2;
        constexpr int CCK_KP3          = SDLK_KP_3;
        constexpr int CCK_KP4          = SDLK_KP_4;
        constexpr int CCK_KP5          = SDLK_KP_5;
        constexpr int CCK_KP6          = SDLK_KP_6;
        constexpr int CCK_KP7          = SDLK_KP_7;
        constexpr int CCK_KP8          = SDLK_KP_8;
        constexpr int CCK_KP9          = SDLK_KP_9;
        constexpr int CCK_KP_PERIOD    = SDLK_KP_PERIOD;
        constexpr int CCK_KP_DIVIDE    = SDLK_KP_DIVIDE;
        constexpr int CCK_KP_MULTIPLY  = SDLK_KP_MULTIPLY;
        constexpr int CCK_KP_MINUS     = SDLK_KP_MINUS;
        constexpr int CCK_KP_PLUS      = SDLK_KP_PLUS;
        constexpr int CCK_KP_ENTER     = SDLK_KP_ENTER;
        constexpr int CCK_KP_EQUALS    = SDLK_KP_EQUALS;
        constexpr int CCK_UP           = SDLK_UP;
        constexpr int CCK_DOWN         = SDLK_DOWN;
        constexpr int CCK_RIGHT        = SDLK_RIGHT;
        constexpr int CCK_LEFT         = SDLK_LEFT;
        constexpr int CCK_INSERT       = SDLK_INSERT;
        constexpr int CCK_HOME         = SDLK_HOME;
        constexpr int CCK_END          = SDLK_END;
        constexpr int CCK_PAGEUP       = SDLK_PAGEUP;
        constexpr int CCK_PAGEDOWN     = SDLK_PAGEDOWN;
        constexpr int CCK_F1           = SDLK_F1;
        constexpr int CCK_F2           = SDLK_F2;
        constexpr int CCK_F3           = SDLK_F3;
        constexpr int CCK_F4           = SDLK_F4;
        constexpr int CCK_F5           = SDLK_F5;
        constexpr int CCK_F6           = SDLK_F6;
        constexpr int CCK_F7           = SDLK_F7;
        constexpr int CCK_F8           = SDLK_F8;
        constexpr int CCK_F9           = SDLK_F9;
        constexpr int CCK_F10          = SDLK_F10;
        constexpr int CCK_F11          = SDLK_F11;
        constexpr int CCK_F12          = SDLK_F12;
        constexpr int CCK_F13          = SDLK_F13;
        constexpr int CCK_F14          = SDLK_F14;
        constexpr int CCK_F15          = SDLK_F15;
        constexpr int CCK_NUMLOCK      = SDLK_NUMLOCKCLEAR;
        constexpr int CCK_CAPSLOCK     = SDLK_CAPSLOCK;
        constexpr int CCK_SCROLLOCK    = SDLK_SCROLLLOCK;
        constexpr int CCK_RSHIFT       = SDLK_RSHIFT;
        constexpr int CCK_LSHIFT       = SDLK_LSHIFT;
        constexpr int CCK_RCTRL        = SDLK_RCTRL;
        constexpr int CCK_LCTRL        = SDLK_LCTRL;
        constexpr int CCK_RALT         = SDLK_RALT;
        constexpr int CCK_LALT         = SDLK_LALT;
        constexpr int CCK_MODE         = SDLK_MODE;
        constexpr int CCK_HELP         = SDLK_HELP;
        constexpr int CCK_PRINTSCREEN  = SDLK_PRINTSCREEN;
        constexpr int CCK_SYSREQ       = SDLK_SYSREQ;
        constexpr int CCK_MENU         = SDLK_MENU;
        constexpr int CCK_POWER        = SDLK_POWER;

        const uint8_t *GetKeyboardState(int *numkeys = nullptr);
    }

    namespace Scancode
    {
        constexpr CCScancode CCS_UNKNOWN            = SDL_SCANCODE_UNKNOWN;
        constexpr CCScancode CCS_A                  = SDL_SCANCODE_A;
        constexpr CCScancode CCS_B                  = SDL_SCANCODE_B;
        constexpr CCScancode CCS_C                  = SDL_SCANCODE_C;
        constexpr CCScancode CCS_D                  = SDL_SCANCODE_D;
        constexpr CCScancode CCS_E                  = SDL_SCANCODE_E;
        constexpr CCScancode CCS_F                  = SDL_SCANCODE_F;
        constexpr CCScancode CCS_G                  = SDL_SCANCODE_G;
        constexpr CCScancode CCS_H                  = SDL_SCANCODE_H;
        constexpr CCScancode CCS_I                  = SDL_SCANCODE_I;
        constexpr CCScancode CCS_J                  = SDL_SCANCODE_J;
        constexpr CCScancode CCS_K                  = SDL_SCANCODE_K;
        constexpr CCScancode CCS_L                  = SDL_SCANCODE_L;
        constexpr CCScancode CCS_M                  = SDL_SCANCODE_M;
        constexpr CCScancode CCS_N                  = SDL_SCANCODE_N;
        constexpr CCScancode CCS_O                  = SDL_SCANCODE_O;
        constexpr CCScancode CCS_P                  = SDL_SCANCODE_P;
        constexpr CCScancode CCS_Q                  = SDL_SCANCODE_Q;
        constexpr CCScancode CCS_R                  = SDL_SCANCODE_R;
        constexpr CCScancode CCS_S                  = SDL_SCANCODE_S;
        constexpr CCScancode CCS_T                  = SDL_SCANCODE_T;
        constexpr CCScancode CCS_U                  = SDL_SCANCODE_U;
        constexpr CCScancode CCS_V                  = SDL_SCANCODE_V;
        constexpr CCScancode CCS_W                  = SDL_SCANCODE_W;
        constexpr CCScancode CCS_X                  = SDL_SCANCODE_X;
        constexpr CCScancode CCS_Y                  = SDL_SCANCODE_Y;
        constexpr CCScancode CCS_Z                  = SDL_SCANCODE_Z;
        constexpr CCScancode CCS_1                  = SDL_SCANCODE_1;
        constexpr CCScancode CCS_2                  = SDL_SCANCODE_2;
        constexpr CCScancode CCS_3                  = SDL_SCANCODE_3;
        constexpr CCScancode CCS_4                  = SDL_SCANCODE_4;
        constexpr CCScancode CCS_5                  = SDL_SCANCODE_5;
        constexpr CCScancode CCS_6                  = SDL_SCANCODE_6;
        constexpr CCScancode CCS_7                  = SDL_SCANCODE_7;
        constexpr CCScancode CCS_8                  = SDL_SCANCODE_8;
        constexpr CCScancode CCS_9                  = SDL_SCANCODE_9;
        constexpr CCScancode CCS_0                  = SDL_SCANCODE_0;
        constexpr CCScancode CCS_RETURN             = SDL_SCANCODE_RETURN;
        constexpr CCScancode CCS_ESCAPE             = SDL_SCANCODE_ESCAPE;
        constexpr CCScancode CCS_BACKSPACE          = SDL_SCANCODE_BACKSPACE;
        constexpr CCScancode CCS_TAB                = SDL_SCANCODE_TAB;
        constexpr CCScancode CCS_SPACE              = SDL_SCANCODE_SPACE;
        constexpr CCScancode CCS_MINUS              = SDL_SCANCODE_MINUS;
        constexpr CCScancode CCS_EQUALS             = SDL_SCANCODE_EQUALS;
        constexpr CCScancode CCS_LEFTBRACKET        = SDL_SCANCODE_LEFTBRACKET;
        constexpr CCScancode CCS_RIGHTBRACKET       = SDL_SCANCODE_RIGHTBRACKET;
        constexpr CCScancode CCS_BACKSLASH          = SDL_SCANCODE_BACKSLASH;
        constexpr CCScancode CCS_NONUSHASH          = SDL_SCANCODE_NONUSHASH;
        constexpr CCScancode CCS_SEMICOLON          = SDL_SCANCODE_SEMICOLON;
        constexpr CCScancode CCS_APOSTROPHE         = SDL_SCANCODE_APOSTROPHE;
        constexpr CCScancode CCS_GRAVE              = SDL_SCANCODE_GRAVE;
        constexpr CCScancode CCS_COMMA              = SDL_SCANCODE_COMMA;
        constexpr CCScancode CCS_PERIOD             = SDL_SCANCODE_PERIOD;
        constexpr CCScancode CCS_SLASH              = SDL_SCANCODE_SLASH;
        constexpr CCScancode CCS_CAPSLOCK           = SDL_SCANCODE_CAPSLOCK;
        constexpr CCScancode CCS_F1                 = SDL_SCANCODE_F1;
        constexpr CCScancode CCS_F2                 = SDL_SCANCODE_F2;
        constexpr CCScancode CCS_F3                 = SDL_SCANCODE_F3;
        constexpr CCScancode CCS_F4                 = SDL_SCANCODE_F4;
        constexpr CCScancode CCS_F5                 = SDL_SCANCODE_F5;
        constexpr CCScancode CCS_F6                 = SDL_SCANCODE_F6;
        constexpr CCScancode CCS_F7                 = SDL_SCANCODE_F7;
        constexpr CCScancode CCS_F8                 = SDL_SCANCODE_F8;
        constexpr CCScancode CCS_F9                 = SDL_SCANCODE_F9;
        constexpr CCScancode CCS_F10                = SDL_SCANCODE_F10;
        constexpr CCScancode CCS_F11                = SDL_SCANCODE_F11;
        constexpr CCScancode CCS_F12                = SDL_SCANCODE_F12;
        constexpr CCScancode CCS_PRINTSCREEN        = SDL_SCANCODE_PRINTSCREEN;
        constexpr CCScancode CCS_SCROLLLOCK         = SDL_SCANCODE_SCROLLLOCK;
        constexpr CCScancode CCS_PAUSE              = SDL_SCANCODE_PAUSE;
        constexpr CCScancode CCS_INSERT             = SDL_SCANCODE_INSERT;
        constexpr CCScancode CCS_HOME               = SDL_SCANCODE_HOME;
        constexpr CCScancode CCS_PAGEUP             = SDL_SCANCODE_PAGEUP;
        constexpr CCScancode CCS_DELETE             = SDL_SCANCODE_DELETE;
        constexpr CCScancode CCS_END                = SDL_SCANCODE_END;
        constexpr CCScancode CCS_PAGEDOWN           = SDL_SCANCODE_PAGEDOWN;
        constexpr CCScancode CCS_RIGHT              = SDL_SCANCODE_RIGHT;
        constexpr CCScancode CCS_LEFT               = SDL_SCANCODE_LEFT;
        constexpr CCScancode CCS_DOWN               = SDL_SCANCODE_DOWN;
        constexpr CCScancode CCS_UP                 = SDL_SCANCODE_UP;
        constexpr CCScancode CCS_NUMLOCKCLEAR       = SDL_SCANCODE_NUMLOCKCLEAR;
        constexpr CCScancode CCS_KP_DIVIDE          = SDL_SCANCODE_KP_DIVIDE;
        constexpr CCScancode CCS_KP_MULTIPLY        = SDL_SCANCODE_KP_MULTIPLY;
        constexpr CCScancode CCS_KP_MINUS           = SDL_SCANCODE_KP_MINUS;
        constexpr CCScancode CCS_KP_PLUS            = SDL_SCANCODE_KP_PLUS;
        constexpr CCScancode CCS_KP_ENTER           = SDL_SCANCODE_KP_ENTER;
        constexpr CCScancode CCS_KP_1               = SDL_SCANCODE_KP_1;
        constexpr CCScancode CCS_KP_2               = SDL_SCANCODE_KP_2;
        constexpr CCScancode CCS_KP_3               = SDL_SCANCODE_KP_3;
        constexpr CCScancode CCS_KP_4               = SDL_SCANCODE_KP_4;
        constexpr CCScancode CCS_KP_5               = SDL_SCANCODE_KP_5;
        constexpr CCScancode CCS_KP_6               = SDL_SCANCODE_KP_6;
        constexpr CCScancode CCS_KP_7               = SDL_SCANCODE_KP_7;
        constexpr CCScancode CCS_KP_8               = SDL_SCANCODE_KP_8;
        constexpr CCScancode CCS_KP_9               = SDL_SCANCODE_KP_9;
        constexpr CCScancode CCS_KP_0               = SDL_SCANCODE_KP_0;
        constexpr CCScancode CCS_KP_PERIOD          = SDL_SCANCODE_KP_PERIOD;
        constexpr CCScancode CCS_NONUSBACKSLASH     = SDL_SCANCODE_NONUSBACKSLASH;
        constexpr CCScancode CCS_APPLICATION        = SDL_SCANCODE_APPLICATION;
        constexpr CCScancode CCS_POWER              = SDL_SCANCODE_POWER;
        constexpr CCScancode CCS_KP_EQUALS          = SDL_SCANCODE_KP_EQUALS;
        constexpr CCScancode CCS_F13                = SDL_SCANCODE_F13;
        constexpr CCScancode CCS_F14                = SDL_SCANCODE_F14;
        constexpr CCScancode CCS_F15                = SDL_SCANCODE_F15;
        constexpr CCScancode CCS_F16                = SDL_SCANCODE_F16;
        constexpr CCScancode CCS_F17                = SDL_SCANCODE_F17;
        constexpr CCScancode CCS_F18                = SDL_SCANCODE_F18;
        constexpr CCScancode CCS_F19                = SDL_SCANCODE_F19;
        constexpr CCScancode CCS_F20                = SDL_SCANCODE_F20;
        constexpr CCScancode CCS_F21                = SDL_SCANCODE_F21;
        constexpr CCScancode CCS_F22                = SDL_SCANCODE_F22;
        constexpr CCScancode CCS_F23                = SDL_SCANCODE_F23;
        constexpr CCScancode CCS_F24                = SDL_SCANCODE_F24;
        constexpr CCScancode CCS_EXECUTE            = SDL_SCANCODE_EXECUTE;
        constexpr CCScancode CCS_HELP               = SDL_SCANCODE_HELP;
        constexpr CCScancode CCS_MENU               = SDL_SCANCODE_MENU;
        constexpr CCScancode CCS_SELECT             = SDL_SCANCODE_SELECT;
        constexpr CCScancode CCS_STOP               = SDL_SCANCODE_STOP;
        constexpr CCScancode CCS_AGAIN              = SDL_SCANCODE_AGAIN;
        constexpr CCScancode CCS_UNDO               = SDL_SCANCODE_UNDO;
        constexpr CCScancode CCS_CUT                = SDL_SCANCODE_CUT;
        constexpr CCScancode CCS_COPY               = SDL_SCANCODE_COPY;
        constexpr CCScancode CCS_PASTE              = SDL_SCANCODE_PASTE;
        constexpr CCScancode CCS_FIND               = SDL_SCANCODE_FIND;
        constexpr CCScancode CCS_MUTE               = SDL_SCANCODE_MUTE;
        constexpr CCScancode CCS_VOLUMEUP           = SDL_SCANCODE_VOLUMEUP;
        constexpr CCScancode CCS_VOLUMEDOWN         = SDL_SCANCODE_VOLUMEDOWN;
        constexpr CCScancode CCS_KP_COMMA           = SDL_SCANCODE_KP_COMMA;
        constexpr CCScancode CCS_KP_EQUALSAS400     = SDL_SCANCODE_KP_EQUALSAS400;
        constexpr CCScancode CCS_INTERNATIONAL1     = SDL_SCANCODE_INTERNATIONAL1;
        constexpr CCScancode CCS_INTERNATIONAL2     = SDL_SCANCODE_INTERNATIONAL2;
        constexpr CCScancode CCS_INTERNATIONAL3     = SDL_SCANCODE_INTERNATIONAL3;
        constexpr CCScancode CCS_INTERNATIONAL4     = SDL_SCANCODE_INTERNATIONAL4;
        constexpr CCScancode CCS_INTERNATIONAL5     = SDL_SCANCODE_INTERNATIONAL5;
        constexpr CCScancode CCS_INTERNATIONAL6     = SDL_SCANCODE_INTERNATIONAL6;
        constexpr CCScancode CCS_INTERNATIONAL7     = SDL_SCANCODE_INTERNATIONAL7;
        constexpr CCScancode CCS_INTERNATIONAL8     = SDL_SCANCODE_INTERNATIONAL8;
        constexpr CCScancode CCS_INTERNATIONAL9     = SDL_SCANCODE_INTERNATIONAL9;
        constexpr CCScancode CCS_LANG1              = SDL_SCANCODE_LANG1;
        constexpr CCScancode CCS_LANG2              = SDL_SCANCODE_LANG2;
        constexpr CCScancode CCS_LANG3              = SDL_SCANCODE_LANG3;
        constexpr CCScancode CCS_LANG4              = SDL_SCANCODE_LANG4;
        constexpr CCScancode CCS_LANG5              = SDL_SCANCODE_LANG5;
        constexpr CCScancode CCS_LANG6              = SDL_SCANCODE_LANG6;
        constexpr CCScancode CCS_LANG7              = SDL_SCANCODE_LANG7;
        constexpr CCScancode CCS_LANG8              = SDL_SCANCODE_LANG8;
        constexpr CCScancode CCS_LANG9              = SDL_SCANCODE_LANG9;
        constexpr CCScancode CCS_ALTERASE           = SDL_SCANCODE_ALTERASE;
        constexpr CCScancode CCS_SYSREQ             = SDL_SCANCODE_SYSREQ;
        constexpr CCScancode CCS_CANCEL             = SDL_SCANCODE_CANCEL;
        constexpr CCScancode CCS_CLEAR              = SDL_SCANCODE_CLEAR;
        constexpr CCScancode CCS_PRIOR              = SDL_SCANCODE_PRIOR;
        constexpr CCScancode CCS_RETURN2            = SDL_SCANCODE_RETURN2;
        constexpr CCScancode CCS_SEPARATOR          = SDL_SCANCODE_SEPARATOR;
        constexpr CCScancode CCS_OUT                = SDL_SCANCODE_OUT;
        constexpr CCScancode CCS_OPER               = SDL_SCANCODE_OPER;
        constexpr CCScancode CCS_CLEARAGAIN         = SDL_SCANCODE_CLEARAGAIN;
        constexpr CCScancode CCS_CRSEL              = SDL_SCANCODE_CRSEL;
        constexpr CCScancode CCS_EXSEL              = SDL_SCANCODE_EXSEL;
        constexpr CCScancode CCS_KP_00              = SDL_SCANCODE_KP_00;
        constexpr CCScancode CCS_KP_000             = SDL_SCANCODE_KP_000;
        constexpr CCScancode CCS_THOUSANDSSEPARATOR = SDL_SCANCODE_THOUSANDSSEPARATOR;
        constexpr CCScancode CCS_DECIMALSEPARATOR   = SDL_SCANCODE_DECIMALSEPARATOR;
        constexpr CCScancode CCS_CURRENCYUNIT       = SDL_SCANCODE_CURRENCYUNIT;
        constexpr CCScancode CCS_CURRENCYSUBUNIT    = SDL_SCANCODE_CURRENCYSUBUNIT;
        constexpr CCScancode CCS_KP_LEFTPAREN       = SDL_SCANCODE_KP_LEFTPAREN;
        constexpr CCScancode CCS_KP_RIGHTPAREN      = SDL_SCANCODE_KP_RIGHTPAREN;
        constexpr CCScancode CCS_KP_LEFTBRACE       = SDL_SCANCODE_KP_LEFTBRACE;
        constexpr CCScancode CCS_KP_RIGHTBRACE      = SDL_SCANCODE_KP_RIGHTBRACE;
        constexpr CCScancode CCS_KP_TAB             = SDL_SCANCODE_KP_TAB;
        constexpr CCScancode CCS_KP_BACKSPACE       = SDL_SCANCODE_KP_BACKSPACE;
        constexpr CCScancode CCS_KP_A               = SDL_SCANCODE_KP_A;
        constexpr CCScancode CCS_KP_B               = SDL_SCANCODE_KP_B;
        constexpr CCScancode CCS_KP_C               = SDL_SCANCODE_KP_C;
        constexpr CCScancode CCS_KP_D               = SDL_SCANCODE_KP_D;
        constexpr CCScancode CCS_KP_E               = SDL_SCANCODE_KP_E;
        constexpr CCScancode CCS_KP_F               = SDL_SCANCODE_KP_F;
        constexpr CCScancode CCS_KP_XOR             = SDL_SCANCODE_KP_XOR;
        constexpr CCScancode CCS_KP_POWER           = SDL_SCANCODE_KP_POWER;
        constexpr CCScancode CCS_KP_PERCENT         = SDL_SCANCODE_KP_PERCENT;
        constexpr CCScancode CCS_KP_LESS            = SDL_SCANCODE_KP_LESS;
        constexpr CCScancode CCS_KP_GREATER         = SDL_SCANCODE_KP_GREATER;
        constexpr CCScancode CCS_KP_AMPERSAND       = SDL_SCANCODE_KP_AMPERSAND;
        constexpr CCScancode CCS_KP_DBLAMPERSAND    = SDL_SCANCODE_KP_DBLAMPERSAND;
        constexpr CCScancode CCS_KP_VERTICALBAR     = SDL_SCANCODE_KP_VERTICALBAR;
        constexpr CCScancode CCS_KP_DBLVERTICALBAR  = SDL_SCANCODE_KP_DBLVERTICALBAR;
        constexpr CCScancode CCS_KP_COLON           = SDL_SCANCODE_KP_COLON;
        constexpr CCScancode CCS_KP_HASH            = SDL_SCANCODE_KP_HASH;
        constexpr CCScancode CCS_KP_SPACE           = SDL_SCANCODE_KP_SPACE;
        constexpr CCScancode CCS_KP_AT              = SDL_SCANCODE_KP_AT;
        constexpr CCScancode CCS_KP_EXCLAM          = SDL_SCANCODE_KP_EXCLAM;
        constexpr CCScancode CCS_KP_MEMSTORE        = SDL_SCANCODE_KP_MEMSTORE;
        constexpr CCScancode CCS_KP_MEMRECALL       = SDL_SCANCODE_KP_MEMRECALL;
        constexpr CCScancode CCS_KP_MEMCLEAR        = SDL_SCANCODE_KP_MEMCLEAR;
        constexpr CCScancode CCS_KP_MEMADD          = SDL_SCANCODE_KP_MEMADD;
        constexpr CCScancode CCS_KP_MEMSUBTRACT     = SDL_SCANCODE_KP_MEMSUBTRACT;
        constexpr CCScancode CCS_KP_MEMMULTIPLY     = SDL_SCANCODE_KP_MEMMULTIPLY;
        constexpr CCScancode CCS_KP_MEMDIVIDE       = SDL_SCANCODE_KP_MEMDIVIDE;
        constexpr CCScancode CCS_KP_PLUSMINUS       = SDL_SCANCODE_KP_PLUSMINUS;
        constexpr CCScancode CCS_KP_CLEAR           = SDL_SCANCODE_KP_CLEAR;
        constexpr CCScancode CCS_KP_CLEARENTRY      = SDL_SCANCODE_KP_CLEARENTRY;
        constexpr CCScancode CCS_KP_BINARY          = SDL_SCANCODE_KP_BINARY;
        constexpr CCScancode CCS_KP_OCTAL           = SDL_SCANCODE_KP_OCTAL;
        constexpr CCScancode CCS_KP_DECIMAL         = SDL_SCANCODE_KP_DECIMAL;
        constexpr CCScancode CCS_KP_HEXADECIMAL     = SDL_SCANCODE_KP_HEXADECIMAL;
        constexpr CCScancode CCS_LCTRL              = SDL_SCANCODE_LCTRL;
        constexpr CCScancode CCS_LSHIFT             = SDL_SCANCODE_LSHIFT;
        constexpr CCScancode CCS_LALT               = SDL_SCANCODE_LALT;
        constexpr CCScancode CCS_LGUI               = SDL_SCANCODE_LGUI;
        constexpr CCScancode CCS_RCTRL              = SDL_SCANCODE_RCTRL;
        constexpr CCScancode CCS_RSHIFT             = SDL_SCANCODE_RSHIFT;
        constexpr CCScancode CCS_RALT               = SDL_SCANCODE_RALT;
        constexpr CCScancode CCS_RGUI               = SDL_SCANCODE_RGUI;
        constexpr CCScancode CCS_MODE               = SDL_SCANCODE_MODE;
        constexpr CCScancode CCS_AUDIONEXT          = SDL_SCANCODE_AUDIONEXT;
        constexpr CCScancode CCS_AUDIOPREV          = SDL_SCANCODE_AUDIOPREV;
        constexpr CCScancode CCS_AUDIOSTOP          = SDL_SCANCODE_AUDIOSTOP;
        constexpr CCScancode CCS_AUDIOPLAY          = SDL_SCANCODE_AUDIOPLAY;
        constexpr CCScancode CCS_AUDIOMUTE          = SDL_SCANCODE_AUDIOMUTE;
        constexpr CCScancode CCS_MEDIASELECT        = SDL_SCANCODE_MEDIASELECT;
        constexpr CCScancode CCS_WWW                = SDL_SCANCODE_WWW;
        constexpr CCScancode CCS_MAIL               = SDL_SCANCODE_MAIL;
        constexpr CCScancode CCS_CALCULATOR         = SDL_SCANCODE_CALCULATOR;
        constexpr CCScancode CCS_COMPUTER           = SDL_SCANCODE_COMPUTER;
        constexpr CCScancode CCS_AC_SEARCH          = SDL_SCANCODE_AC_SEARCH;
        constexpr CCScancode CCS_AC_HOME            = SDL_SCANCODE_AC_HOME;
        constexpr CCScancode CCS_AC_BACK            = SDL_SCANCODE_AC_BACK;
        constexpr CCScancode CCS_AC_FORWARD         = SDL_SCANCODE_AC_FORWARD;
        constexpr CCScancode CCS_AC_STOP            = SDL_SCANCODE_AC_STOP;
        constexpr CCScancode CCS_AC_REFRESH         = SDL_SCANCODE_AC_REFRESH;
        constexpr CCScancode CCS_AC_BOOKMARKS       = SDL_SCANCODE_AC_BOOKMARKS;
        constexpr CCScancode CCS_BRIGHTNESSDOWN     = SDL_SCANCODE_BRIGHTNESSDOWN;
        constexpr CCScancode CCS_BRIGHTNESSUP       = SDL_SCANCODE_BRIGHTNESSUP;
        constexpr CCScancode CCS_DISPLAYSWITCH      = SDL_SCANCODE_DISPLAYSWITCH;
        constexpr CCScancode CCS_KBDILLUMTOGGLE     = SDL_SCANCODE_KBDILLUMTOGGLE;
        constexpr CCScancode CCS_KBDILLUMDOWN       = SDL_SCANCODE_KBDILLUMDOWN;
        constexpr CCScancode CCS_KBDILLUMUP         = SDL_SCANCODE_KBDILLUMUP;
        constexpr CCScancode CCS_EJECT              = SDL_SCANCODE_EJECT;
        constexpr CCScancode CCS_SLEEP              = SDL_SCANCODE_SLEEP;
        constexpr CCScancode CCS_APP1               = SDL_SCANCODE_APP1;
        constexpr CCScancode CCS_APP2               = SDL_SCANCODE_APP2;
    }
}

#endif // CC_KEYBOARD
