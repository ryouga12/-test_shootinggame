#pragma once
#include<string>
#include <filesystem>
#include<map>
#include<vector>
#include"memory"

//------------------------------------------------------------------------------------------------
//
//サウンド管理クラス
//
//------------------------------------------------------------------------------------------------

class SoundManager {
public:

	// シングルトン設計
	static std::unique_ptr<SoundManager>& GetSoundManager();

	//コンストラクタ
	SoundManager();
	~SoundManager();

	//サウンドを再生させる
	//arg_1 : 流したいサウンドのKEY(パスの拡張子なし)
	//arg_2 : どのタイプで再生するか
	//arg_3 : 音量(デフォルト30)
	//arg_4 : どこから再生させるか
	void Sound_Play(const std::string& key_path, const int& playType, const float& volume = 30 , const int& top_position_flag = 1);

	//サウンドを止める
	//arg_1 : 止めたいサウンドのKEY
	void StopSound(const std::string& key_path);

private:

	//音楽ファイルパス配列
	std::map <std::string , int>sound_map;

};

