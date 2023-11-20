#include "PlayerBullet.h"
#include "Novice.h"

void PlayerBullet::Init() {
	// 初期値の設定
	// 座標
	pos_ = { 1280 / 2, 720 / 2 };
	// 速度
	const float kSpeed = 6.0f;
	vel_ = { 0, kSpeed };
	// 半径
	radius_ = 32;
	// 弾が存在しているか
	isAlive_ = false;
}

void PlayerBullet::Update() {
	// 上に進む
	pos_.y -= vel_.y;
	// 画面上まで行ったら消す
	if (0 >= pos_.y - radius_) {
		isAlive_ = false;
	}
}

void PlayerBullet::Draw() {
	if (isAlive_) {
		Novice::DrawEllipse(pos_.x, pos_.y, radius_, radius_, 0.0f, WHITE, kFillModeSolid);
	}
}