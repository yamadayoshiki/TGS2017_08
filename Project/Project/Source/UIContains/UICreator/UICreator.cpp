#include "UICreator.h"

#include "../UIFilePaths.h"

#include "../Button/Button.h"
#include "../Sprite/SpriteCreator.h"

UICreator::UICreator(IWorld * world, const IGameManagerPtr & gameManager, const UIFilePaths & path) :
	Actor(world, ActorName::UI_Manager, GSvector2({ 0.0f, 0.0f }), gameManager) {
	// ボタンの設定（設計がダメなのでコードを変えたほうがいい）
	addChild(std::make_shared<Button>(world, m_Transform.m_Position, gameManager, "Resource/StreamingAssets/UI/" + path.button));
	// テクスチャの生成
	addChild(std::make_shared<SpriteCreator>(world, m_Transform.m_Position, gameManager, "Resource/StreamingAssets/UI/" + path.sprite));
	// 保留
	//addChild(std::make_shared<Button>(world, ActorName::Player, m_Transform.m_Position, gameManager, "Resource/StreamingAssets/UI/" + path.button));

}

