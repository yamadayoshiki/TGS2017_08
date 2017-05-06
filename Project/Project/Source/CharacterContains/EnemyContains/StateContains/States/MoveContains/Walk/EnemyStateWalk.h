#ifndef ENEMYSTATEWALK_H_
#define ENEMYSTATEWALK_H_

#include "../MoveBase/EnemyStateMoveBase.h"

class EnemyStateWalk :public EnemyStateMoveBase
{
public:
	//コンストラクタ
	EnemyStateWalk(const EnemyBasePtr& enemy);
protected:
	// 各状態独自の初期化
	virtual void onUniqueInit()override;
	// 更新処理
	virtual void onUpdate(float deltaTime)override;
	// 衝突判定
	virtual void onCollide(const Actor & other)override {}
	// 終了時の処理
	virtual void onEnd()override {}
	// 入力処理
	virtual void onInput() override {}
};

#endif // !ENEMY_COMMONSTATE_WALK
