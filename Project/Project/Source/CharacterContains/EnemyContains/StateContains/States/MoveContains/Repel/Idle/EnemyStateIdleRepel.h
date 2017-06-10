#ifndef ENEMYSTATEIDLEREPEL_H_
#define ENEMYSTATEIDLEREPEL_H_

#include "../Base/EnemyStateMoveBaseRepel.h"
#include "../../Standard/Idle/EnemyStateIdleStandard.h"

class EnemyStateIdleRepel : public EnemyStateMoveBaseRepel,public EnemyStateIdleStandard
{
public:
	//コンストラクタ
	EnemyStateIdleRepel(const EnemyBasePtr& enemy);
	// 各状態独自の初期化
	virtual void onUniqueInit()override;

	// メッセージ処理
	virtual void handleMessage(EventMessage message, void* param) override;
};

#endif // !ENEMYSTATEMOVEREPELIDLE_H_