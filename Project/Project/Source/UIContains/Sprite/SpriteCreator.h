#pragma once

#include "../../WorldContains/IWorld.h"
#include "../../ActorContains/Actor/Actor.h"

// テクスチャ生成クラス
class SpriteCreator : public Actor {
	enum class Element {
		NAME = 0,		// テクスチャの名前
		ANIMATE = 1,	// アニメーションするかしないか
		WIDTH = 2,		// 表示されるテクスチャの横幅
		HEIGHT = 3,		// 表示されるテクスチャの縦幅
		POS_X = 4,		// テクスチャの座標
		POS_Y = 5,		// テクスチャの座標
		TIME = 6,		// １フレームの再生時間
		ANGLE = 7,		// 角度
		ALPHA = 8,		// 透明度
	};
public:
	// コンストラクタ
	SpriteCreator(IWorld* world, const GSvector2& position, const IGameManagerPtr& gameManager, const std::string & file_name);
	// 生成
	void create(const std::string & file_name);
};