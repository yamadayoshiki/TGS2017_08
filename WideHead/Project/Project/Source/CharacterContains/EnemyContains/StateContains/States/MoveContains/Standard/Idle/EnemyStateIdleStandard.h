#ifndef ENEMYSTATEIDLESTANDARD_H_
#define ENEMYSTATEIDLESTANDARD_H_

#include "../Base/EnemyStateMoveBaseStandard.h"

//待機状態
class EnemyStateIdleStandard :virtual public EnemyStateMoveBaseStandard
{
public:
	//コンストラクタ
	EnemyStateIdleStandard(const EnemyBasePtr& enemy);
	// 各状態独自の初期化
	virtual void onUniqueInit()override;
};

#endif