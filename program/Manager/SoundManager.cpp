#include "SoundManager.h"
#include"DxLib.h"

std::unique_ptr<SoundManager>& SoundManager::GetSoundManager()
{
	static std::unique_ptr<SoundManager> p_instance = nullptr;

	if (!p_instance)p_instance = std::make_unique<SoundManager>();
	return p_instance;
}

void SoundManager::Sound_Play(const std::string& key_path, const int& playType, const float& volume , const int& top_position_flag)
{
	//流したいサウンド
	int sound;

	auto it = sound_map.find(key_path);
	//キーが見つかったら
	if (it != sound_map.end()) {
		sound = sound_map[key_path];
	}
	else {
		return;
	}
	//見つかったらまず30%に音を調整する
	ChangeVolumeSoundMem(255 * volume / 100, sound);
	//音を流す
	PlaySoundMem(sound, playType, top_position_flag);
}

void SoundManager::StopSound(const std::string& key_path)
{
	//止めたいサウンド
	int sound;

	auto it = sound_map.find(key_path);
	//キーが見つかったら
	if (it != sound_map.end()) {
		sound = sound_map[key_path];
	}
	else {
		return;
	}

	//サウンドを止める
	StopSoundMem(sound);
}

SoundManager::SoundManager()
{
	//ディレクトリ配下のパスを格納する
	std::vector<std::filesystem::path> directory_sound_path;

	//指定したディレクトリのパスをすべて取得する
	if (std::filesystem::is_directory("sound/")) {
		for (auto& directory_path : std::filesystem::directory_iterator("sound/")) {
			directory_sound_path.emplace_back(directory_path.path());
		}
	}

	//サウンドリストが空じゃなかったら
	if (!directory_sound_path.empty()) {
		//キーにする名前
		std::string key_name;

		for (auto& sound_path : directory_sound_path) {
			//パスからキーを生成する
			key_name = sound_path.stem().string();
			//連想配列に格納する
			sound_map.insert(std::make_pair(key_name,LoadSoundMem(sound_path.string().c_str())));
		}
	}
}

SoundManager::~SoundManager()
{
	//サウンドを削除する
	sound_map.clear();
}
