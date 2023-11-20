#include "Collision.h"

void Collision::Init(Player* player, Enemy* enemy) {
	player_ = player;
	enemy_ = enemy;
}

void Collision::CheckOnCollision() {
	Vector2 e2b = {
		enemy_->GetTranslation().x - player_->bullet_.GetTranslation().x,
		enemy_->GetTranslation().y - player_->bullet_.GetTranslation().y
	};
	float e2bR = enemy_->GetRadius() + player_->bullet_.GetRadius();
	float dist = (e2b.x * e2b.x) + (e2b.y * e2b.y);

	if (dist <= e2bR * e2bR) {
		player_->bullet_.SetIsAlive(false);
		enemy_->SetIsAlive(false);
	}
}