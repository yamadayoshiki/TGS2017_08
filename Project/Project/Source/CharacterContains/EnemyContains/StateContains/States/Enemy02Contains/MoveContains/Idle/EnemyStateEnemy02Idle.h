#ifndef ENEMYSTATEENEMY02IDLE_H_
#define ENEMYSTATEENEMY02IDLE_H_

#include "../MoveBase/EnemyStateEnemy02MoveBase.h"

//Enemy02専用Idle
class EnemyStateEnemy02Idle : public EnemyStateEnemy02MoveBase
{
public:
	//コンストラクタ
	EnemyStateEnemy02Idle(const EnemyBasePtr& enemy);
	// 各状態独自の初期化
	virtual void onUniqueInit()override {}
	// 更新処理
	virtual void onUpdate(float deltaTime)override {}
	// 衝突判定
	virtual void onCollide(const Actor & other)override {}
	// 終了時の処理
	virtual void onEnd()override {}
	// 入力処理
	virtual void onInput() override {}
};


#endif // !ENEMYSTATEENEMY02IDLE_H_
