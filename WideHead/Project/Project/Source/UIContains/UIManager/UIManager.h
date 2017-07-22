#pragma once

#include "../../WorldContains/IWorld.h"
#include "../../ActorContains/Actor/Actor.h"

#include "../UIType.h"
#include "../UIFilePaths.h"

#include <unordered_map>

enum class SceneName;

// UIマネージャー
class UIManager : public Actor {
public:
	// コンストラクタ
	UIManager(IWorld* world, const IGameManagerPtr& gameManakkoger, const SceneName& scene);

private:
	// 各シーンのパスの登録
	void regist();
	// シーンに対応したUIの生成
	void create(const SceneName& scene_name);

private:
	// UI登録用のmap
	std::unordered_map<SceneName, UIFilePaths>m_FilePaths;
};