#ifndef ENEMYSTATEMOVEREPELMOVE_H_
#define ENEMYSTATEMOVEREPELMOVE_H_

#include "../Base/EnemyStateMoveRepelBase.h"
#include "../../MoveContains/Move/EnemyStateMove.h"

class EnemyStateMoveRepelMove : public EnemyStateMoveRepelBase, public EnemyStateMove
{
public:
	//コンストラクタ
	EnemyStateMoveRepelMove(const EnemyBasePtr& enemy,
		const float speed);
	// 各状態独自の初期化
	virtual void onUniqueInit()override;
	// 更新処理
	virtual void onUpdate(float deltaTime)override;

	// メッセージ処理
	virtual void handleMessage(EventMessage message, void* param) override;
};

#endif // !ENEMYSTATEMOVEREPELMOVE_H_
