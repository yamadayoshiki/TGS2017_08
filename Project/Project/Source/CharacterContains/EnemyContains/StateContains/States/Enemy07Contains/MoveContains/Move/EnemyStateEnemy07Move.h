#ifndef ENEMYSTATEENEMY07MOVE_H_
#define ENEMYSTATEENEMY07MOVE_H_

#include "../Base/EnemyStateEnemy07MoveBase.h"
#include "../../../MoveContains/Move/EnemyStateMove.h"

class EnemyStateEnemy07Move : public EnemyStateEnemy07MoveBase, public EnemyStateMove
{
public:
	//コンストラクタ
	EnemyStateEnemy07Move(
		const EnemyBasePtr& enemy,
		const float speed);
	// 各状態独自の初期化
	virtual void onUniqueInit()override;
	// 更新処理
	virtual void onUpdate(float deltaTime)override;

	//メッセージ処理
	virtual void handleMessage(EventMessage message, void* param) override;
};
#endif // !ENEMYSTATEENEMY07MOVE_H_
