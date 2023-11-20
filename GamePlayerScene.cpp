#include "GamePlayerScene.h"
#include <Novice.h>

GamePlayScene::~GamePlayScene() {
	delete collision_;
	delete enemy_;
	delete player_;
}

void GamePlayScene::Init() {
	Component_->GetInstance();

	// 自機
	player_ = new Player();
	player_->Init();

	// 敵
	enemy_ = new Enemy();
	enemy_->Init();

	// 当たり判定
	collision_ = new Collision();
	collision_->Init(player_, enemy_);
}

void GamePlayScene::Update() {
	// 自機
	player_->Update();

	// 敵
	enemy_->Update();

	// 当たり判定
	collision_->CheckOnCollision();

	// 敵が死んだらシーン切り替え
	if (!enemy_->GetIsAlive()) {
		sceneNo = CLEAR;
	}
}

void GamePlayScene::Draw() {
	// 自機
	player_->Draw();

	// 敵
	enemy_->Draw();

	// 文字を表示
	Novice::ScreenPrintf(0, 10, "GameScene");
	Novice::ScreenPrintf(0, 30, "SPACE:Shot  WASD:Move");
}