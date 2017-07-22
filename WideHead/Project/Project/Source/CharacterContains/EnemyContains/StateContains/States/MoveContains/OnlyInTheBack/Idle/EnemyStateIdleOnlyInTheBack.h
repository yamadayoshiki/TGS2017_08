#ifndef ENEMYSTATEIDLEONLYINTHEBACK_H_
#define ENEMYSTATEIDLEONLYINTHEBACK_H_

#include "../Base/EnemyStateMoveBaseOnlyInTheBack.h"
#include "../../Standard/Idle/EnemyStateIdleStandard.h"

//Enemy02専用Idle
class EnemyStateIdleOnlyInTheBack : public EnemyStateMoveBaseOnlyInTheBack, public EnemyStateIdleStandard
{
public:
	//コンストラクタ
	EnemyStateIdleOnlyInTheBack(const EnemyBasePtr& enemy);
	// 各状態独自の初期化
	virtual void onUniqueInit()override;
	//メッセージ処理
	virtual void handleMessage(EventMessage message, void* param) override;
};

#endif