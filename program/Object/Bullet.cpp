#include "Bullet.h"
#include"../../common/common_value.h"
#include"DxLib.h"

using namespace CommonValue;

Bullet::Bullet(const int& new_hp, const int& new_speed, const int& new_height, const int& new_width, const float& new_bullet_pos_x, const float& new_bullet_pos_y):
 Actor(new_hp, new_speed, new_height, new_width, new_bullet_pos_x, new_bullet_pos_y)
{

}

void Bullet::Update(float delta_time)
{
	if (is_arive) {
		//弾の座標を上に移動させる
		actor_pos_y -= speed;
		//画面外に出た際の処理
		ScreenOutObject();
	}
}

void Bullet::Draw()
{
	if (is_arive) {
		DrawCircle(actor_pos_x, actor_pos_y, 5, -1, true);
	}
}

void Bullet::ScreenOutObject()
{
	//画面外に出たらフラグをおろす
	if (actor_pos_y < 0) {
		is_arive = false;
	}
}
