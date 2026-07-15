#include "Enemy.h"
#include"DxLib.h"
#include"../../common/common_value.h"
#include<random>

using namespace CommonValue;

Enemy::Enemy(const int& new_hp, const int& new_speed, const int& new_height, const int& new_width, const float& new_enemy_pos_x, const float& new_enemy_pos_y ):
Actor(new_hp, new_speed, new_height, new_width, new_enemy_pos_x, new_enemy_pos_y)
{

	//上書き用のため、前座標を保存する(リスポーン値)
	prev_pos_x = new_enemy_pos_x;
	prev_pos_y = new_enemy_pos_y;
}

Enemy::~Enemy()
{

}

void Enemy::Update(float delta_time)
{
	if (is_arive) {
		//敵の座標を下に移動させる
		actor_pos_y += speed;
		//hpが0になったらis_ariveをfalseにする
		if (hp <= 0) {
			is_arive = false;
			//座標をリスポーン値に戻す
			actor_pos_x = prev_pos_x;
			actor_pos_y = prev_pos_y;
			//hpを戻す
			hp = max_hp;
		}
		//画面外にでたら生存フラグをfalseにする
		ScreenOutObject();
	}
	//敵が消えた後、3秒後に再度リスポーンさせる
	else if(!is_arive){
		//時間をプラスする
		timer += delta_time;
		//タイマーが3秒を超えたらリスポーンさせる
		if (timer >= 3) {
			is_arive = true;
			//座標をリスポーン値に戻す
			actor_pos_x = prev_pos_x;
			actor_pos_y = prev_pos_y;
			//タイマーをリセットする
			timer = 0;
		}
	}
}

void Enemy::Draw()
{
	//ラジアンに変換用(180度)
	const float PI = 3.14159265f;
	if (is_arive) {
		//敵画像の描画
		DrawCircle(actor_pos_x, actor_pos_y, 10, GetColor(255, 0, 0), true);
	}
}

void Enemy::ScreenOutObject()
{
	//画面外に出たら
	//今回は下に行く処理しかないため、下の画面外に出たら生存フラグをOFFにする
	if (actor_pos_y > WINDOW_HEIGHT) {
		is_arive = false;
	}
}
