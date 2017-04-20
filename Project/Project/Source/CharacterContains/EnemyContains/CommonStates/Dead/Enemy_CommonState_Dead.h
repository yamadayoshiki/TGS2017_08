#ifndef ENEMY_COMMONSTATE_DEAD_H_
#define ENEMY_COMMONSTATE_DEAD_H_

#include "../../BaseContains/BaseState/Enemy_BaseState.h"

class Enemy_CommonState_Dead:public Enemy_BaseState
{
public:
	//コンストラクタ
	Enemy_CommonState_Dead(GSvector2& pos, GSmatrix4& mat);
	// 各状態独自の初期化
	virtual void unique_init(Actor & actor) override;
	// 更新処理
	virtual void update(Actor & actor, float deltaTime) override;
	// 衝突判定
	virtual void collide(const Actor & other) override;
	// 終了時の処理
	virtual void end() override;
};
#endif // !ENEMY_COMMONSTATE_DEAD_H_
