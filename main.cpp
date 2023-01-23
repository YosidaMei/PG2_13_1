#include <Novice.h>
#include "Bullet.h"
#include "Player.h"
#include "Enemy.h"

const char kWindowTitle[] = "LC1A_28_ヨシダメイ";

int Enemy::isAlive;

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	Player* player = new Player;
	Enemy* enemyA = new Enemy(100,200);
	Enemy* enemyB = new Enemy(400, 300);


	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		player->Update(keys, preKeys);
		enemyA->Update(player->bullet_);
		enemyB->Update(player->bullet_);
		if (keys[DIK_R] && preKeys[DIK_R] == 0) {
			Enemy::isAlive = 1;
		}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		Novice::ScreenPrintf(0, 0, "isAlive:%d", enemyA->isAlive);
		Novice::ScreenPrintf(0, 20, "isAlive:%d", enemyB->isAlive);

		player->Draw();
		enemyA->Draw();
		enemyB->Draw();

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	delete player;
	delete enemyA;
	delete enemyB;

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
