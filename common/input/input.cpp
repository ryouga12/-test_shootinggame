#include "input.h"

namespace Ginput {

    // --- ここが足りていない「実体」の定義 ---
    char Input::now_keys[256];
    char Input::prev_keys[256];

    //DXライブラリ定数テーブル
    const int Input::dx_key_table[(int)eKeys::KB_MAX] = {
        KEY_INPUT_BACK, KEY_INPUT_TAB, KEY_INPUT_RETURN, KEY_INPUT_LSHIFT, KEY_INPUT_RSHIFT, KEY_INPUT_LCONTROL, KEY_INPUT_RCONTROL, KEY_INPUT_ESCAPE, KEY_INPUT_SPACE,
        KEY_INPUT_PGUP, KEY_INPUT_PGDN, KEY_INPUT_END, KEY_INPUT_HOME, KEY_INPUT_LEFT, KEY_INPUT_UP, KEY_INPUT_RIGHT, KEY_INPUT_DOWN, KEY_INPUT_INSERT, KEY_INPUT_DELETE,
        KEY_INPUT_MINUS, KEY_INPUT_YEN, KEY_INPUT_PREVTRACK, KEY_INPUT_PERIOD, KEY_INPUT_SLASH, KEY_INPUT_LALT, KEY_INPUT_RALT, KEY_INPUT_SCROLL,
        KEY_INPUT_SEMICOLON, KEY_INPUT_COLON, KEY_INPUT_LBRACKET, KEY_INPUT_RBRACKET, KEY_INPUT_AT, KEY_INPUT_BACKSLASH, KEY_INPUT_COMMA, KEY_INPUT_CAPSLOCK, KEY_INPUT_PAUSE,
        KEY_INPUT_NUMPAD0, KEY_INPUT_NUMPAD1, KEY_INPUT_NUMPAD2, KEY_INPUT_NUMPAD3, KEY_INPUT_NUMPAD4, KEY_INPUT_NUMPAD5, KEY_INPUT_NUMPAD6, KEY_INPUT_NUMPAD7, KEY_INPUT_NUMPAD8, KEY_INPUT_NUMPAD9,
        KEY_INPUT_MULTIPLY, KEY_INPUT_ADD, KEY_INPUT_SUBTRACT, KEY_INPUT_DECIMAL, KEY_INPUT_DIVIDE, KEY_INPUT_NUMPADENTER,
        KEY_INPUT_F1, KEY_INPUT_F2, KEY_INPUT_F3, KEY_INPUT_F4, KEY_INPUT_F5, KEY_INPUT_F6, KEY_INPUT_F7, KEY_INPUT_F8, KEY_INPUT_F9, KEY_INPUT_F10, KEY_INPUT_F11, KEY_INPUT_F12,
        KEY_INPUT_A, KEY_INPUT_B, KEY_INPUT_C, KEY_INPUT_D, KEY_INPUT_E, KEY_INPUT_F, KEY_INPUT_G, KEY_INPUT_H, KEY_INPUT_I, KEY_INPUT_J, KEY_INPUT_K, KEY_INPUT_L, KEY_INPUT_M, KEY_INPUT_N, KEY_INPUT_O, KEY_INPUT_P, KEY_INPUT_Q, KEY_INPUT_R, KEY_INPUT_S, KEY_INPUT_T, KEY_INPUT_U, KEY_INPUT_V, KEY_INPUT_W, KEY_INPUT_X, KEY_INPUT_Y, KEY_INPUT_Z,
        KEY_INPUT_0, KEY_INPUT_1, KEY_INPUT_2, KEY_INPUT_3, KEY_INPUT_4, KEY_INPUT_5, KEY_INPUT_6, KEY_INPUT_7, KEY_INPUT_8, KEY_INPUT_9
    };

    void Ginput::Input::Initialize()
    {
        // 配列をゼロクリアして、初期フレームで誤動作しないようにする
        memset(now_keys, 0, sizeof(now_keys));
        memset(prev_keys, 0, sizeof(prev_keys));
    }

    void Ginput::Input::Update()
    {
        // 前フレームの状態を保存
        memcpy(prev_keys, now_keys, sizeof(prev_keys));
        // 全キーの状態を取得
        GetHitKeyStateAll(now_keys);
    }

    bool Ginput::Input::IsKeyDown(eKeys key)
    {
        //現在のキーの取得
        int code = dx_key_table[(int)key];
        //押されたキーをtrueに返す
        return now_keys[code] == 1;
    }

    bool Ginput::Input::IsKeyDownTrigger(eKeys key)
    {
        //現在のキーの取得
        int code = dx_key_table[(int)key];
        //押されたキーを
        return (now_keys[code] == 1 && prev_keys[code] == 0);
    }

    bool Ginput::Input::IsKeyReleaseTrigger(eKeys key)
    {
        int code = dx_key_table[(int)key];
        return (now_keys[code] == 0 && prev_keys[code] == 1);
    }

}