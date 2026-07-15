#pragma once
#include"Actor.h"
#include"Bullet.h"
#include <vector>
//------------------------------------------------------------------------------------------------
//
//プレイヤークラス
//
//------------------------------------------------------------------------------------------------

class Enemy;

class Player final : public Actor {
public:

	//デフォルトコンストラクタ
	Player() = default;

	//コンストラクタ
	//arg_1 : 体力
	//arg_2 : 速度
	//arg_3 : チップサイズ高さ
	//arg_4 : チップサイズ幅
	//arg_5 : 座標(X)
	//arg_6 : 座標(X)
	Player(const int& new_hp, const int& new_speed, const int& new_height, const int& new_width, const float& new_player_pos_x, const float& new_player_pos_y);

	~Player();

	//画面外に出そうになった時の処理
	void ScreenOutObject();

	//撃つ
	void Shot();

	//更新処理
	void Update(float delta_time)override;
	//描画処理
	void Draw()override;

	//弾の当たり判定処理
	//arg_1 : 当たり判定フラグ
	//arg_2 : 敵のポインタ
	//arg_3 : 弾のポインタ
	int BulletHitUpdate(bool is_collision , Enemy* enemy , Bullet* bullet);

	//弾の配列を取得する
	const std::vector<Bullet*>& GetBulletArray() {
		return bullet_list;
	}

	//プレイヤーを点滅させる
	void BlinkingPlayer(float delta_time , const bool& collision_flag);

private:

	//弾の配列
	std::vector<Bullet*>bullet_list;
	//画像表示操作フラグ
	bool gh_contorol_flag = true;
	//タイマー
	float timer = 0;
};


