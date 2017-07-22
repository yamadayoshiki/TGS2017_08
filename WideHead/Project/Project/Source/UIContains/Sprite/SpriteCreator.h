#pragma once

#include "../../WorldContains/IWorld.h"
#include "../../ActorContains/Actor/Actor.h"

// テクスチャ生成クラス
class SpriteCreator : public Actor {
	enum class Element {
		NAME = 0,	// テクスチャの名前
		ANIMATE,	// アニメーションするかしないか
		WIDTH,		// 表示されるテクスチャの横幅
		HEIGHT,		// 表示されるテクスチャの縦幅
		POS_X,		// テクスチャの座標
		POS_Y,		// テクスチャの座標
		TIME,		// １フレームの再生時間
		USAGE,		// 用途
		DRAWORDER,	// 描画順序
	};
public:
	// コンストラクタ
	SpriteCreator(IWorld* world, const GSvector2& position, const IGameManagerPtr& gameManager, const std::string & file_name);
	// 生成
	void create(const std::string & file_name);
};