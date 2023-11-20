#pragma once
#include "IScene.h"
#include "Player/Player.h"
#include "Enemy/Enemy.h"
#include "Collision/Collision.h"
#include "Component/Component.h"

class GamePlayScene : public IScene
{
public:
	~GamePlayScene();
	void Init() override;
	void Update() override;
	void Draw() override;
private:
	Component* Component_;

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };
	// 宣言
	// 自機
	Player* player_;

	// 敵
	Enemy* enemy_;

	// 当たり判定
	Collision* collision_;
};