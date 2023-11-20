#include "Enemy.h"
#include <Novice.h>

void Enemy::Init() {
	pos_.x = 1280 / 2;
	pos_.y = 100;
	vel_.x = 2;
	vel_.y = 0;
	radius_ = 32;
	isAlive_ = true;
}

void Enemy::Update() {
	// 移動処理
	pos_.x += vel_.x;
	pos_.y += vel_.y;

	// 画面端まで行くと反射
	if (pos_.x - radius_ <= 0 || pos_.x + radius_ >= 1280) {
		vel_.x *= -1;
	}
	if (pos_.y - radius_ <= 0 || pos_.y + radius_ >= 720) {
		vel_.y *= -1;
	}
}

void Enemy::Draw() {
	if (isAlive_) {
		Novice::DrawEllipse(pos_.x, pos_.y, radius_, radius_, 0.0f, RED, kFillModeSolid);
	}
}