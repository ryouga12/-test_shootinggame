#pragma once
#include<vector>
#include"../../program/Object/Actor.h"
//------------------------------------------------------------------------------------------------
//
//PlaySceneクラス
//
//------------------------------------------------------------------------------------------------

class Player;
class Enemy;

class PlayScene {
public: 

	PlayScene();
	~PlayScene();

	//当たり判定
	//arg_1 : 当たり判定を取りたいオブジェクト1
	//arg_2 : 当たり判定を取りたいオブジェクト2
	//arg_3 : 当たり判定大きさ(デフォルト0.5)
	bool IsCollisionCenter(const Actor* a, const Actor* b, float scale = 0.5f);

	//更新処理
	void Update(float delta_time);
	//描画
	void Draw();
	
private:

	//プレイヤー
	Player* player = nullptr;
	//敵の配列
	std::vector<Enemy*>enemy_list;
	//当たり判定フラグ(何回も当たらないようにするため)
	bool collision_flag = true;
	//タイマー
	float timer = 0;
	//スコア
	int score = 0;

};