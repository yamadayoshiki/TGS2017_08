#pragma once

#include "../../WorldContains/IWorld.h"
#include "../../ActorContains/Actor/Actor.h"

// テキスト生成クラス
class TextCreator : public Actor {
	enum class Element {
		NAME = 0,		// 画像の名前
		ANIMATE = 1,	// アニメーションするかしないか
		WIDTH = 2,		// 表示される画像の横幅
		HEIGHT = 3,		// 表示される画像の縦幅
		POS_X = 4,		// 画像の座標
		POS_Y = 5,		// 画像の座標
		TIME = 6,		// １フレームの再生時間
		ANGLE = 7,		// 角度
		ALPHA = 8,		// 透明度
	};
public:
	// コンストラクタ
	TextCreator(IWorld* world, const GSvector2& position, const IGameManagerPtr& gameManager, const std::string & file_name);
	// 生成
	void create(const std::string & file_name);
};