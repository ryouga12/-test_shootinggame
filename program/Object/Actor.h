#pragma once
#include <iostream>
//------------------------------------------------------------------------------------------------
//
//オブジェクトの基底クラス
//
//------------------------------------------------------------------------------------------------

class Actor {
public:

	Actor(const int& new_hp , const int& new_speed ,const int& new_height , const int& new_width , const float& new_actor_pos_x , const float& new_actor_pos_y);
	~Actor();

	// --- ゲッター (Getter) ---
	int   GetHp()       const { return hp; }
	int	  GetMaxHp()	const { return max_hp; }
	int   GetSpeed()    const { return speed; }
	int   GetWidth()    const { return width; }
	int   GetHeight()   const { return height; }
	float GetPosX()     const { return actor_pos_x; }
	float GetPosY()     const { return actor_pos_y; }

	// --- セッター (Setter) ---
	void SetHp(const int& val) { hp = val; }
	void SetMaxHp(const int& val) { max_hp = val; }
	void SetSpeed(const int& val) { speed = val; }
	void SetWidth(const int& val) { width = val; }
	void SetHeight(const int& val) { height = val; }
	void SetPosX(const float& val) { actor_pos_x = val; }
	void SetPosY(const float& val) { actor_pos_y = val; }

	//更新処理
	virtual void Update(float delta_time) = 0;
	//描画
	virtual void Draw() {};

	//生存フラグをセットする
	void SetisArive(bool new_flag) {
		is_arive = new_flag;
	}
	//生存フラグを取得する
	bool GetIsArive()const {
		return is_arive;
	}

protected:

	//最大hp
	int max_hp = 0;
	//Hp
	int hp = 0;
	//速度
	int speed = 0;
	//自身のサイズ(幅)
	int width = 0;
	//自身のサイズ(縦)
	int height = 0;
	//x座標
	float actor_pos_x = 0;
	//y座標
	float actor_pos_y = 0;
	//生存フラグ
	bool is_arive = true;
};