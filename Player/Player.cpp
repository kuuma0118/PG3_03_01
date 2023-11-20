#include "Player.h"
#include <Novice.h>

Player::Player() {

}

void Player::Init() {
	Component_ = Component::GetInstance();

	// 初期値の設定
	// 座標
	pos_ = { 1280 / 2, 720 / 2 };
	// 速度
	const float kSpeed = 4.0f;
	vel_ = { kSpeed, kSpeed };
	// 半径
	radius_ = 16;
	// 発射フラグ
	isShot_ = false;

	// 弾
	// 初期化
	bullet_.Init();
	// 初期位置
	bullet_.SetPos(pos_);
}

void Player::Update() {
#pragma region 入力処理
	// 移動処理
	// Y軸
	if (Component_->PressKey(DIK_W)) {
		pos_.y -= vel_.y;
	}
	if (Component_->PressKey(DIK_S)) {
		pos_.y += vel_.y;
	}
	// X軸
	if (Component_->PressKey(DIK_D)) {
		pos_.x += vel_.x;
	}
	if (Component_->PressKey(DIK_A)) {
		pos_.x -= vel_.x;
	}

	// 発射処理
	if (Component_->ReleaseKey(DIK_SPACE)) {
		isShot_ = true;
	}
#pragma endregion

	if (isShot_) {
		bullet_.SetIsAlive(true);
		isShot_ = false;
	}

	// 発射されたら更新処理を呼ぶ
	if (bullet_.GetIsAlive()) {
		bullet_.Update();
	}
	else {
		// 弾を発射してない間は自機に追従
		bullet_.SetPos(pos_);
	}
}

void Player::Draw() {
	// 自機
	Novice::DrawEllipse(pos_.x, pos_.y, radius_, radius_, 0.0f, BLUE, kFillModeSolid);
	// 弾
	bullet_.Draw();
}