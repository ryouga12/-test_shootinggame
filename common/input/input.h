#pragma once
#include <stdint.h>
#include "DxLib.h"

//今の所キーの処理のみ
namespace Ginput {

    class Input {
    public:

        //キーボードキー一覧
        enum class eKeys : uint32_t {
            KB_BACK,        // バックスペース
            KB_TAB,         // タブ
            KB_RETURN,      // エンター
            KB_LSHIFT,      // 左シフト
            KB_RSHIFT,      // 右シフト
            KB_LCONTROL,    // 左コントロール
            KB_RCONTROL,    // 右コントロール
            KB_ESCAPE,      // エスケープ
            KB_SPACE,       // スペース
            KB_PGUP,        // ＰａｇｅＵＰ
            KB_PGDN,        // ＰａｇｅＤｏｗｎ
            KB_END,         // エンド
            KB_HOME,        // ホーム
            KB_LEFT,        // 左
            KB_UP,          // 上
            KB_RIGHT,       // 右
            KB_DOWN,        // 下
            KB_INSERT,      // インサート
            KB_DELETE,      // デリート

            KB_MINUS,       // －
            KB_YEN,         // ￥
            KB_PREVTRACK,   // ＾
            KB_PERIOD,      // ．
            KB_SLASH,       // ／
            KB_LALT,        // 左ＡＬＴ
            KB_RALT,        // 右ＡＬＴ
            KB_SCROLL,      // ScrollLock
            KB_SEMICOLON,   // ；
            KB_COLON,       // ：
            KB_LBRACKET,    // ［
            KB_RBRACKET,    // ］
            KB_AT,          // ＠
            KB_BACKSLASH,   // ＼
            KB_COMMA,       // ，
            KB_CAPSLOCK,    // CaspLock
            KB_PAUSE,       // PauseBreak

            KB_NUMPAD0,     // テンキー０
            KB_NUMPAD1,     // テンキー１
            KB_NUMPAD2,     // テンキー２
            KB_NUMPAD3,     // テンキー３
            KB_NUMPAD4,     // テンキー４
            KB_NUMPAD5,     // テンキー５
            KB_NUMPAD6,     // テンキー６
            KB_NUMPAD7,     // テンキー７
            KB_NUMPAD8,     // テンキー８
            KB_NUMPAD9,     // テンキー９
            KB_MULTIPLY,    // テンキー＊
            KB_ADD,         // テンキー＋
            KB_SUBTRACT,    // テンキー－
            KB_DECIMAL,     // テンキー．
            KB_DIVIDE,      // テンキー／
            KB_NUMPADENTER, // テンキーのエンター

            KB_F1,          // Ｆ１
            KB_F2,          // Ｆ２
            KB_F3,          // Ｆ３
            KB_F4,          // Ｆ４
            KB_F5,          // Ｆ５
            KB_F6,          // Ｆ６
            KB_F7,          // Ｆ７
            KB_F8,          // Ｆ８
            KB_F9,          // Ｆ９
            KB_F10,         // Ｆ１０
            KB_F11,         // Ｆ１１
            KB_F12,         // Ｆ１２

            KB_A,           // Ａ
            KB_B,           // Ｂ
            KB_C,           // Ｃ
            KB_D,           // Ｄ
            KB_E,           // Ｅ
            KB_F,           // Ｆ
            KB_G,           // Ｇ
            KB_H,           // Ｈ
            KB_I,           // Ｉ
            KB_J,           // Ｊ
            KB_K,           // Ｋ
            KB_L,           // Ｌ
            KB_M,           // Ｍ
            KB_N,           // Ｎ
            KB_O,           // Ｏ
            KB_P,           // Ｐ
            KB_Q,           // Ｑ
            KB_R,           // Ｒ
            KB_S,           // Ｓ
            KB_T,           // Ｔ
            KB_U,           // Ｕ
            KB_V,           // Ｖ
            KB_W,           // Ｗ
            KB_X,           // Ｘ
            KB_Y,           // Ｙ
            KB_Z,           // Ｚ
            KB_0,           // ０
            KB_1,           // １
            KB_2,           // ２
            KB_3,           // ３
            KB_4,           // ４
            KB_5,           // ５
            KB_6,           // ６
            KB_7,           // ７
            KB_8,           // ８
            KB_9,           // ９
            KB_MAX          // 最大数確認用
        };

        static void Initialize();

        // 更新
        static void Update();

        // 状態取得
        // 押しっぱなし
        static bool IsKeyDown(eKeys key);

        // 押した瞬間
        static bool IsKeyDownTrigger(eKeys key);

        // 離した瞬間
        static bool IsKeyReleaseTrigger(eKeys key);
     
    private:
        //全てのキーの数
        static const int32_t KEY_MAX_SIZE = 256;
        //現在のキー
        static char now_keys[KEY_MAX_SIZE];
        //一個前のキー
        static char prev_keys[KEY_MAX_SIZE];
        // 変換テーブル
		static const int dx_key_table[(int)eKeys::KB_MAX]; 
    };
}

// 使いやすいようにエイリアスを作成
using eKeys = Ginput::Input::eKeys;