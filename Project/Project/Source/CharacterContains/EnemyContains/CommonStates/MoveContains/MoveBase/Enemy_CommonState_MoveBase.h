#ifndef ENEMY_COMMONSTATE_MOVEBASE_H_
#define ENEMY_COMMONSTATE_MOVEBASE_H_

#include "../../../BaseContains/BaseState/Enemy_BaseState.h"

// 通常時の移動クラスのベース
class Enemy_CommonState_MoveBase : public Enemy_BaseState
{
public:
	// コンストラクタ
	Enemy_CommonState_MoveBase(GSvector2& pos, GSmatrix4& mat);
	// 各状態独自の初期化
	virtual void unique_init(Actor & actor) override;
	// 更新処理
	virtual void update(Actor & actor, float deltaTime) override;
	// 衝突判定
	virtual void collide(const Actor & other) override;
	// 終了時の処理
	virtual void end() override;

protected:
	// 各状態独自の初期化
	virtual void onUniqueInit(Actor & actor) = 0;
	// 更新処理
	virtual void onUpdate(Actor & actor, float deltaTime) = 0;
	// 衝突判定
	virtual void onCollide(const Actor & other) = 0;
	// 終了時の処理
	virtual void onEnd() = 0;
};

#endif // !ENEMY_COMMONSTATE_MOVEBASE_H_
