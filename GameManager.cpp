#include "Scene/GameManager.h"
#include "GamePlayerScene.h"
#include "TitleScene.h"
#include "Scene/ClearScene.h"
#include <Novice.h>
#include <Windows.h>

GameManager::GameManager() {
	// 各シーンの配列
	sceneArr_[TITLE] = std::make_unique<TitleScene>();
	sceneArr_[STAGE] = std::make_unique<GamePlayScene>();
	sceneArr_[CLEAR] = std::make_unique<ClearScene>();

	currentSceneNo_ = TITLE;
}

int GameManager::Run() {
	const char kWindowTitle[] = "LE2B_23_PG3_03_01";
	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

    Component_ = Component::GetInstance();

	sceneArr_[currentSceneNo_]->Init();

	while (Novice::ProcessMessage() == 0) {
		Novice::BeginFrame();

		Component_->Update();

		// シーンチェック
		prevSceneNo_ = currentSceneNo_;
		currentSceneNo_ = sceneArr_[currentSceneNo_]->GetSceneNo();

		// シーン変更チェック
		if (prevSceneNo_ != currentSceneNo_) {
			sceneArr_[currentSceneNo_]->Init();
		}

		///
		/// 更新処理
		/// 
		sceneArr_[currentSceneNo_]->Update();

		///
		/// 描画処理
		/// 
		sceneArr_[currentSceneNo_]->Draw();

		Novice::EndFrame();

		if (Component_->ReleaseKey(DIK_ESCAPE)) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}