#pragma once
#include <memory>
#include "IScene.h"
#include "GamePlayerScene.h"
#include "TitleScene.h"
#include "ClearScene.h"
#include "Component/Component.h"

class GameManager
{
public:
	GameManager();
	~GameManager() = default;

	int Run();

private:
	// シーンを保持するメンバ変数
	std::unique_ptr<IScene> sceneArr_[3];
	int currentSceneNo_;
	int prevSceneNo_;

	Component* Component_;
};