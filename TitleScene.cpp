#include "TitleScene.h"

void TitleScene::Init() {
	Component_ = Component::GetInstance();
}

void TitleScene::Update() {
	if (Component_->ReleaseKey(DIK_SPACE)) {
		sceneNo = STAGE;
	}
}

void TitleScene::Draw() {
	// 文字を表示
	Novice::ScreenPrintf(0, 10, "TitleScene");
	Novice::ScreenPrintf(0, 30, "Press SPACE");
}