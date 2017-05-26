#ifndef ENEMYSTATEMOVEREPELIDLE_H_
#define ENEMYSTATEMOVEREPELIDLE_H_

#include "../Base/EnemyStateMoveRepelBase.h"

class EnemyStateMoveRepelIdle : public EnemyStateMoveRepelBase
{
public:
	//コンストラクタ
	EnemyStateMoveRepelIdle(const EnemyBasePtr& enemy);
	// 各状態独自の初期化
	virtual void onUniqueInit()override;
};

#endif // !ENEMYSTATEMOVEREPELIDLE_H_
