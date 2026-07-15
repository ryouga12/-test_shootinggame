#include "PlayScene.h"
#include"../../program/Object/Player.h"
#include"../../program/Object/Enemy.h"
#include"DxLib.h"
#include"../../common/common_value.h"

using namespace CommonValue;

PlayScene::PlayScene()
{	
	//プレイヤーのポインタ初期化
	player = new Player(5, 5, 56, 126, WINDOW_WIDTH / 2, 635);

	//敵の生成
	for (int i = 0; i < 10; i++) {
		enemy_list.emplace_back(new Enemy(10, 1, 45, 45, (i + 1) * 100, 50));
	}
}

PlayScene::~PlayScene()
{
	//オブジェクト解放
	if (player != nullptr) {
		delete player;
		player = nullptr;
	}
	for (auto& enemy : enemy_list) {
		if (enemy != nullptr) {
			delete enemy;
			enemy = nullptr;
		}
	}
}

bool PlayScene::IsCollisionCenter(const Actor* a, const Actor* b, float scale)
{
    //中心同士の距離（絶対値）を計算
    float diffX = std::abs(a->GetPosX() - b->GetPosX());
    float diffY = std::abs(a->GetPosY() - b->GetPosY());

    //当たり判定のしきい値を計算
    float thresholdX = (a->GetWidth() + b->GetWidth()) * 0.5f * scale;
    float thresholdY = (a->GetHeight() + b->GetHeight()) * 0.5f * scale;

    //XとYの両方がしきい値より小さければ「当たり」
    return (diffX < thresholdX && diffY < thresholdY);
}

void PlayScene::Update(float delta_time)
{
	//当たり判定がoFFになった場合、1秒後再度当たり判定を有効にする
	if (!collision_flag) {
		timer += delta_time;
		if (timer >= 1.5f) {
			collision_flag = true;
		}
	}

	//プレイヤーの更新処理
	if (player != nullptr && player->GetIsArive()) {
		//プレイヤーの更新処理
		player->Update(delta_time);
		//プレイヤーの点滅処理
		player->BlinkingPlayer(delta_time, collision_flag);
	}

	//敵の更新処理
	for (auto enemy : enemy_list) {
		enemy->Update(delta_time);
	}

	//当たり判定
	for (auto& enemy : enemy_list) {
		if (enemy != nullptr && !enemy->GetIsArive()) {
			continue;
		}
		if (IsCollisionCenter(player, enemy, 1) && collision_flag) {
			player->SetHp(player->GetHp() - 1);
			collision_flag = false;
			timer = 0;
		}
		//弾の当たり判定
		for (auto bullet : player->GetBulletArray()) {
			//弾と敵が当たったら敵を消す
			if (player->BulletHitUpdate(IsCollisionCenter(bullet, enemy, 1), enemy, bullet)) {
				//敵を倒したらスコア加算
				score += 100;
			}
		}
	}
}

void PlayScene::Draw()
{

	if (player != nullptr && player->GetIsArive()){
	//プレイヤーの描画処理
    player->Draw();
	}
	//敵の描画処理
	for (auto enemy : enemy_list) {
		enemy->Draw();
	}
	//スコア表示
	DrawFormatString(WINDOW_WIDTH - 250, 100, -1, "スコア : %d", score);

	if (player != nullptr && !player->GetIsArive()) {
		//重い処理
		SetFontSize(50);
		//プレイヤーのHPが0になったら終了という文字を大きく出す
		DrawString(400, 150, "ゲーム終了", -1);
		//重い処理
		SetFontSize(16);
	}
}

