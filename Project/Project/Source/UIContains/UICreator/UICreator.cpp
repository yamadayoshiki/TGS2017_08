#include "UICreator.h"

#include "../UIFilePaths.h"
#include "../Button/Button.h"
#include"../Rank/Rank.h"
#include"../Combo/Combo.h"
#include "../Sprite/SpriteCreator.h"
#include "../../ActorContains/Transform/Transform.h"

UICreator::UICreator(IWorld * world, const IGameManagerPtr & gameManager, const UIFilePaths & path) :
	Actor(world, ActorName::UI_Manager, GSvector2({ 0.0f, 0.0f }), gameManager) {
	// ボタンの設定（設計がダメなのでコードを変えたほうがいい）
	addChild(std::make_shared<Button>(world, p_Transform->m_Position, gameManager, "Resource/StreamingAssets/UI/" + path.button));
	// テクスチャの生成
	addChild(std::make_shared<SpriteCreator>(world, p_Transform->m_Position, gameManager, "Resource/StreamingAssets/UI/" + path.sprite));
	//コンボの作成
	addChild(std::make_shared<Combo>(world, p_Transform->m_Position, gameManager, "Resource/StreamingAssets/UI/" + path.combo));
	//Rank UIの設定
	addChild(std::make_shared<Rank>(world, p_Transform->m_Position, gameManager, "Resource/StreamingAssets/UI/" + path.rank));

	// 保留
	//addChild(std::make_shared<Button>(world, ActorName::Player, m_Transform.m_Position, gameManager, "Resource/StreamingAssets/UI/" + path.button));

}

