#ifndef ENEMYSTATEENEMY07IDLE_H_
#define ENEMYSTATEENEMY07IDLE_H_

#include "../Base/EnemyStateEnemy07MoveBase.h"
#include "../../../MoveContains/Idle/EnemyStateIdle.h"

class EnemyStateEnemy07Idle : public EnemyStateEnemy07MoveBase, public EnemyStateIdle
{
public:
	//コンストラクタ
	EnemyStateEnemy07Idle(const EnemyBasePtr& enemy);
	// 各状態独自の初期化
	virtual void onUniqueInit()override;
	//メッセージ処理
	virtual void handleMessage(EventMessage message, void* param) override;
};

#endif