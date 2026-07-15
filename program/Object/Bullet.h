#pragma once
#include"Actor.h"
//------------------------------------------------------------------------------------------------
//
//弾クラス
//
//------------------------------------------------------------------------------------------------

class Bullet final : public Actor {
public :


	Bullet(const int& new_hp, const int& new_speed, const int& new_height, const int& new_width, const float& new_bullet_pos_x, const float& new_bullet_pos_y);
	~Bullet() {};

	//更新処理
	void Update(float delta_time)override;
	//描画処理
	void Draw()override;

	//画面外にでた時の処理
	void ScreenOutObject();

private:

};


