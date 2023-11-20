#pragma once
#include "Vector2.h"
#include "PlayerBullet.h"
#include "Enemy/Enemy.h"
#include "Component/Component.h"
#include <memory>

class Player
{
public:
	///
	/// Default Method
	/// 

	// コンストラクタ
	Player();
	// デストラクタ
	~Player() = default;

	// 初期化
	void Init();
	// 更新処理
	void Update();
	// 描画
	void Draw();

	/// 
	/// User Method
	/// 
	// Getter
	Vector2 GetTranslation() { return pos_; }
	bool GetIsShot() { return isShot_; }
	float GetRadius() { return radius_; }

	// 包含して弾を作る
	PlayerBullet bullet_;
private:
	Component* Component_;
	Vector2 pos_;	// 座標
	Vector2 vel_;	// 速度
	float radius_;	// 半径
	bool isShot_;   // 発射フラグ
};