#ifndef NUMBERCREATOR_H_
#define NUMBERCREATOR_H_
#include "../../ActorContains/Actor/Actor.h"
//数字テクスチャ生成クラス
class NumberCreator : public Actor {
	enum class Element {
		NAME = 0,	// テクスチャの名前
		POS_X,		// 右上座標.x
		POS_Y,		// 右上座標.y
		LENGTH,		// 表示桁数
		USAGE,		// 用途
		DRAWORDER,	// 描画順序
	};
public:
	//コンストラクタ
	NumberCreator(
		IWorld* world,
		const GSvector2& position,
		const IGameManagerPtr& gameManager,
		const std::string & file_name);
	// 生成
	void Create(const std::string & file_name);
};

#endif // !NUMBERCREATOR_H_
