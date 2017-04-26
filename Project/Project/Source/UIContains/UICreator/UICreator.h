#pragma once

#include "../../ActorContains/ActorPtr.h"
#include "../../SceneContains/SceneName.h"
#include "../../WorldContains/IWorldPtr.h"
#include "../../Base/GameManagerContains/IGameManagerPtr.h"

#include <unordered_map>

// UI生成クラス
class UICreator {
public:
	// コンストラクタ
	UICreator(const IWorldPtr& world, const IGameManagerPtr& gameManager);
	// デストラクタ
	~UICreator();
	// UIの登録
	void regist();
	// シーンに対応したUIの生成
	void create(const SceneName& scene_name);
private:
	// ワールド
	IWorldPtr p_World;
	// ゲームマネージャー
	IGameManagerPtr p_GameManager;
	// UI登録用のmap
	std::unordered_map<SceneName, ActorPtr>m_UIManagers;
};