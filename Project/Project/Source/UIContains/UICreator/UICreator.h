#pragma once

#include "../../WorldContains/IWorld.h"
#include "../../ActorContains/Actor/Actor.h"

#include "../UIType.h"
#include "../../FileReader/CsvReaderPtr.h"

#include <unordered_map>
#include <string>

// UI生成クラス
template<typename T>
class UICreator : public Actor {
public:
	// コンストラクタ
	UICreator(IWorld* world, const IGameManagerPtr& gameManager, const std::string& path);
	// 生成
	void create(const std::string& path);
};

// コンストラクタ
template<typename T>
inline UICreator<T>::UICreator(IWorld * world, const IGameManagerPtr & gameManager, const std::string & path) :
	Actor(world, ActorName::UI_Manager, GSvector2({ 0.0f, 0.0f }), gameManager) {
	create(path);
}

// 生成
template<typename T>
inline void UICreator<T>::create(const std::string & path) {
	addChild(std::make_shared<T>(p_World, p_GameManager, path));
}
