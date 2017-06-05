#ifndef ENEMYSTATEENEMY02IDLE_H_
#define ENEMYSTATEENEMY02IDLE_H_

#include "../Base/EnemyStateEnemy02MoveBase.h"
#include "../../../MoveContains/Idle/EnemyStateIdle.h"

//Enemy02専用Idle
class EnemyStateEnemy02Idle : public EnemyStateEnemy02MoveBase,public EnemyStateIdle
{
public:
	//コンストラクタ
	EnemyStateEnemy02Idle(const EnemyBasePtr& enemy);
	// 各状態独自の初期化
	virtual void onUniqueInit()override;
	//メッセージ処理
	virtual void handleMessage(EventMessage message, void* param) override;
};

#endif