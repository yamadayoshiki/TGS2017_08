#ifndef ENEMYSTATEENEMY02MOVE_H_
#define ENEMYSTATEENEMY02MOVE_H_

#include "../Base/EnemyStateMoveBaseOnlyInTheBack.h"
#include "../../Standard/Move/EnemyStateMoveStandard.h"

//Enemy02専用Move
class EnemyStateMoveOnlyInTheBack : public EnemyStateMoveBaseOnlyInTheBack, public EnemyStateMoveStandard
{
public:
	//コンストラクタ
	EnemyStateMoveOnlyInTheBack(
		const EnemyBasePtr& enemy,
		const float speed);
	// 各状態独自の初期化
	virtual void onUniqueInit()override;
	// 更新処理
	virtual void onUpdate(float deltaTime)override;

protected:
	//メッセージ処理
	virtual void OnHandleMessage(EventMessage message, void* param) override;
};

#endif // !ENEMYSTATEENEMY02MOVE_H_