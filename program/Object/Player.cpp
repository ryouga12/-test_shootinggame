#include "Player.h"
#include"../../common/common_value.h"
#include"DxLib.h"
#include"../../common/input/input.h"
#include"Enemy.h"

using namespace CommonValue;
using namespace Ginput;

Player::Player(const int& new_hp, const int& new_speed, const int& new_height, const int& new_width, const float& new_player_pos_x, const float& new_player_pos_y) :
	Actor(new_hp, new_speed, new_height, new_width, new_player_pos_x, new_player_pos_y)
{
	//配列を回して10個文を生成する
	for (int i = 0; i < 10; i++) {
		bullet_list.emplace_back(new Bullet(0, 5, 20, 20, 0, 0));
	}
}

Player::~Player()
{
	//弾の解放
	for (auto& bullet : bullet_list) {
		delete bullet;
		bullet = nullptr;
	}

}

void Player::ScreenOutObject()
{
	//画面外に出そうになったら押し返す
	
	// --- 左端 ---
	if (actor_pos_x < 0 + width / 2) {
		actor_pos_x = 0 + width / 2;
	}
	// --- 右端 ---
	if (actor_pos_x > WINDOW_WIDTH - width / 2) {
		actor_pos_x = WINDOW_WIDTH - width / 2;
	}
	// --- 上端 ---
	if (actor_pos_y < 0 + height / 2) {
		actor_pos_y = 0 + height / 2;
	}

	// --- 下端 ---
	if (actor_pos_y > WINDOW_HEIGHT - height / 2) {
		actor_pos_y = WINDOW_HEIGHT - height / 2;
	}
}

void Player::Shot()
{
	//弾を生成する
	for(auto bullet : bullet_list){
		if (bullet != nullptr && !bullet->GetIsArive()) {
			//最初の一個だけフラグを切り替える
			bullet->SetisArive(true);
			//座標をPlayerにSETする
			bullet->SetPosX(actor_pos_x);
			bullet->SetPosY(actor_pos_y);
			break;
		}
	}
}

void Player::Update(float delta_time)
{
	//プレイヤーのHPが0になったらis_ariveをfalseにする
	if (hp <= 0) {
		is_arive = false;
	}

	//弾の処理
	for (auto bullet : bullet_list) {
		if (bullet != nullptr) {
			bullet->Update(delta_time);
		}
	}

	//移動処理
	if (Input::IsKeyDown(eKeys::KB_W)) {
		actor_pos_y -= speed;
	}
	else if (Input::IsKeyDown(eKeys::KB_S)) {
		actor_pos_y += speed;
	}
	else if (Input::IsKeyDown(eKeys::KB_A)) {
		actor_pos_x -= speed;
	}
	else if (Input::IsKeyDown(eKeys::KB_D)) {
		actor_pos_x += speed;
	}

	//Enterボタンを押したときに弾を生成する
	if (Input::IsKeyDownTrigger(eKeys::KB_RETURN)) {
		//弾を撃つ
		Shot();
	}

	//画面外に出そうになった際の処理
	ScreenOutObject();
}

void Player::Draw()
{
	//HP表示
	DrawFormatString(100, 100, -1, "プレイヤーHP : %d", hp);

	//弾の描画処理
	for (auto bullet : bullet_list) {
		if (bullet != nullptr) {
			bullet->Draw();
		}
	}

	//プレイヤーの描画制御フラグ
	if(gh_contorol_flag){
	 //プレイヤーの描画
	  DrawCircle(actor_pos_x, actor_pos_y, 10, -1, true);
	}
}

int Player::BulletHitUpdate(bool is_collision, Enemy* enemy , Bullet* bullet)
{
	//当たり判定が発生したら
	if (is_collision) {
		//敵の体力を0にする
		enemy->SetHp(0);
		//敵の生存フラグをfalseにして消す
		bullet->SetisArive(false);
		//敵の座標を0に固定する
		bullet->SetPosY(0);
		return true;
	}
	return false;
}

void Player::BlinkingPlayer(float delta_time , const bool& collision_flag)
{
	// 無敵状態のとき
	if (!collision_flag) {
		//タイマーを更新する
		timer += delta_time;
		// 0.1秒ごとに点滅させる
		if (timer >= 0.1f) {
			//フラグを反転させて点滅してるように見せる
			gh_contorol_flag = !gh_contorol_flag; 
			// タイマーリセット
			timer = 0;       
		}
	}
	else {
		// 通常時は必ず表示
		gh_contorol_flag = true;
	}
}
