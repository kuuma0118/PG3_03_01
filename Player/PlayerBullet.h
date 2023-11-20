#pragma once
#include "Vector2.h"

class PlayerBullet
{
public:
	///
	/// Default Method
	/// 

	// コンストラクタ
	PlayerBullet() = default;
	// デストラクタ
	~PlayerBullet() = default;

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
	float GetRadius() { return radius_; }
	bool GetIsAlive() { return isAlive_; }

	// Setter
	void SetIsAlive(bool isAlive) { isAlive_ = isAlive; }
	void SetPos(Vector2 pos) { pos_ = pos; }

private:
	Vector2 pos_;
	Vector2 vel_;
	float radius_;
	bool isAlive_;
};