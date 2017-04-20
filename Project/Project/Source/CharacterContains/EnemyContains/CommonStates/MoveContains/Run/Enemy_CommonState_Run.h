#ifndef ENEMY_COMMONSTATE_RUN_H_
#define ENEMY_COMMONSTATE_RUN_H_

#include "../MoveBase/Enemy_CommonState_MoveBase.h"

class Enemy_CommonState_Run :public Enemy_CommonState_MoveBase
{
public:
	//コンストラクタ
	Enemy_CommonState_Run(GSvector2& pos, GSmatrix4& mat);
protected:
	// 各状態独自の初期化
	virtual void onUniqueInit(Actor & actor)override;
	// 更新処理
	virtual void onUpdate(Actor & actor, float deltaTime)override;
	// 衝突判定
	virtual void onCollide(const Actor & other)override {}
	// 終了時の処理
	virtual void onEnd()override {}
	// 入力処理
	virtual void onInput() override {}
};

#endif // !ENEMY_COMMONSTATE_RUN_H_
