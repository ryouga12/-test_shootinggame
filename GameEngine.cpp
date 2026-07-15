#include <Windows.h>
#include <chrono>
#include <string>
#include"common/input/input.h"
#include"common/common_value.h"

#include "DxLib.h"
#include "game_main.h"

using namespace CommonValue;

// 時間管理用
static std::chrono::system_clock::time_point clock_start;

// --- エントリポイント ---
int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{

    // ウィンドウモードで起動
    ChangeWindowMode(TRUE);

    // 画面解像度と色深度の設定
    SetGraphMode(WINDOW_WIDTH, WINDOW_HEIGHT, 32);

    // 垂直同期（リフレッシュレートに合わせる設定）を有効化
    SetWaitVSyncFlag(TRUE);

    // DXライブラリ初期化処理
    if (DxLib_Init() == -1) return -1;

    // 描画先を裏画面に設定（ダブルバッファリング）
    // これがないと描画されている軌道が見えて分かりづらくなる
    SetDrawScreen(DX_SCREEN_BACK);

    // ウィンドウが非アクティブでも動作を継続させる設定
    SetAlwaysRunFlag(TRUE);

    //キー情報の初期化
    Ginput::Input::Initialize();

    //ゲーム固有の初期化

    // 最初の時間計測
    clock_start = std::chrono::system_clock::now();

    // game_main.h で定義された初期化関数
    gameStart();

    //メインループ

    // ProcessMessage() は Windows のシステムメッセージを処理し、
    // ウィンドウが閉じられたりエラーが起きると -1 を返す
    while (ProcessMessage() == 0)
    {
        // デルタタイム（経過時間）の計算
        auto clock_now = std::chrono::system_clock::now();
        // 前回から今回までの秒数を float で取得
        float delta_time = std::chrono::duration<float>(clock_now - clock_start).count();
        clock_start = clock_now;

        // --- 描画開始 ---

        // 画面を一度真っ暗にクリア
        ClearDrawScreen();

        //キー情報の更新処理
        Ginput::Input::Update();

        // ゲームロジックの更新と描画
        // game_main.h で定義されたメイン関数を呼び出す
        gameMain(delta_time);

        // 裏画面の内容を表画面（モニター）に反映
        ScreenFlip();

    }

    //終了処理

    // ゲーム側で確保したメモリや画像の解放
    gameEnd();

    // DXライブラリの終了
    DxLib_End();

    return 0;
}