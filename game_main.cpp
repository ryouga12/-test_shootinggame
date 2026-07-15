#include "game_main.h"
#include"common/input/input.h"
#include "DxLib.h"
#include <time.h>
#include <string>
#include"program/Scene/PlayScene.h"

//プレイシーンの処理
PlayScene* play_scene = nullptr;

//---------------------------------------------------
//
// ゲームの初期化処理(ここに最初に初期化させたい処理を書いてください)
// 
//----------------------------------------------------

void gameStart()
{
	//毎回バラバラな乱数を取得したい為、ここで初期化(rand()関数などの使用時の為に)
	srand(time(0));

	//シーンの初期化
	play_scene = new PlayScene();
}

//---------------------------------------------------
//
// ゲームのメイン処理(ここに処理を書いてください)
// 
//----------------------------------------------------

void gameMain(float delta_time)
{
	//シーンの更新処理
	play_scene->Update(delta_time);
	//シーンの描画処理
	play_scene->Draw();
}

//---------------------------------------------------
//
// ゲームの解放処理(ここに解放処理を書いてください)
// 
//----------------------------------------------------

void gameEnd()
{
	delete play_scene;
	play_scene = nullptr;
}
