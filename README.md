# test_shootinggame (C++ゲーム開発勉強会用サンプル)

C++のオブジェクト指向を使ったシンプルな2Dシューティングゲームの勉強会用ソースコードです。
---

## 📂 フォルダ構成 (Directory Structure)

プロジェクトは、役割ごとにきれいにモジュール化されています。

```text
test_shootinggame/
│
├── common/                  # 共通ユーティリティ・基盤処理
│   └── input/               # 入力処理 (キーボードの検知など)
│
├── graphics/                # グラフィックスリソース
│   └── images/              # ゲーム内で使用する画像格納フォルダ (Player, Enemy, Bullet等)
│
├── program/                 # ゲームプログラム本編 (ソースコード)
│   ├── Manager/             # 管理者クラス(今回は使いません)
│   │                        
│   │
│   ├── Object/              # キャラクター・実体クラス
│   │                        # (例: Player, Enemy, Bullet などのオブジェクト)
│   │
│   └── Scene/               # ゲームシーン管理クラス
│                            # (例: PlaySceneなど)
│
├── game_main.cpp            # ゲームの全体ループ (エントリーポイント/初期化・更新・描画・解放)
└── game_main.h              # game_mainのヘッダーファイル
