#pragma once
#include "Vector2.h"

class Enemy
{
public:
	///
	/// Default Method
	/// 

	// コンストラクタ
	Enemy() = default;
	// デストラクタ
	~Enemy() = default;

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
	bool GetIsAlive() { return isAlive_; }
	float GetRadius() { return radius_; }

	// Setter
	void SetIsAlive(bool isAlive) { isAlive_ = isAlive; }

private:
	Vector2 pos_;	// 座標
	Vector2 vel_;	// 速度
	float radius_;	// 半径
	bool isAlive_;  // 生存フラグ
};