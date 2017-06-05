#ifndef ENEMYSTATEIDLE_H_
#define ENEMYSTATEIDLE_H_

#include "../Base/EnemyStateMoveBase.h"

//待機状態
class EnemyStateIdle :virtual public EnemyStateMoveBase
{
public:
	//コンストラクタ
	EnemyStateIdle(const EnemyBasePtr& enemy);
	// 各状態独自の初期化
	virtual void onUniqueInit()override;
};

#endif