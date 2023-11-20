#pragma once

// シーン名を列挙型で定義
enum SCENE { TITLE, STAGE, CLEAR };

class IScene
{
public:
	// 初期化
	virtual void Init() = 0;
	// 更新処理
	virtual void Update() = 0;
	// 描画処理
	virtual void Draw() = 0;

	// 仮想デストラクタ
	virtual ~IScene();

	// シーン番号のゲッター
	int GetSceneNo();
protected:
	// シーン番号を管理する変数
	static int sceneNo;
};