#ifndef ENEMYSTATEMOVEREPELIDLE_H_
#define ENEMYSTATEMOVEREPELIDLE_H_

#include "../Base/EnemyStateMoveRepelBase.h"
#include "../../MoveContains/Idle/EnemyStateIdle.h"

class EnemyStateMoveRepelIdle : public EnemyStateMoveRepelBase,public EnemyStateIdle
{
public:
	//コンストラクタ
	EnemyStateMoveRepelIdle(const EnemyBasePtr& enemy);
	// 各状態独自の初期化
	virtual void onUniqueInit()override;

	// メッセージ処理
	virtual void handleMessage(EventMessage message, void* param) override;
};

#endif // !ENEMYSTATEMOVEREPELIDLE_H_