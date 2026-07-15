#pragma once
#include"Actor.h"
//------------------------------------------------------------------------------------------------
//
//敵クラス
//
//------------------------------------------------------------------------------------------------

class Enemy final :public Actor {
public:

	//コンストラクタ
	//arg_1 : 体力
	//arg_2 : 速度
	//arg_3 : チップサイズ高さ
	//arg_4 : チップサイズ幅
	//arg_5 : 座標(X)
	//arg_6 : 座標(X)
	Enemy(const int& new_hp, const int& new_speed, const int& new_height, const int& new_width, const float& new_enemy_pos_x, const float& new_enemy_pos_y);
	~Enemy();

	//更新処理
	void Update(float delta_time)override;
	//描画処理
	void Draw()override;
	//画面外に出た際の処理
	void ScreenOutObject();

	//前座標を取得する(X座標)
	float GetPrevPosX()const {
		return prev_pos_x;
	}
	//前座標を取得する(Y座標)
	float GetPrevPosY()const {
		return prev_pos_y;
	}
	//座標をリセットする
	void EnemyPosReset() {
		actor_pos_x = prev_pos_x;
		actor_pos_y = prev_pos_y;
	}

private:



	//タイマー
	float timer = 0;
	//前座標(x)
	float prev_pos_x = 0;
	//前座標(y)
	float prev_pos_y = 0;

};

