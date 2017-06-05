#ifndef ENEMYSTATEENEMY02MOVE_H_
#define ENEMYSTATEENEMY02MOVE_H_

#include "../Base/EnemyStateEnemy02MoveBase.h"
#include "../../../MoveContains/Move/EnemyStateMove.h"

//Enemy02専用Move
class EnemyStateEnemy02Move : public EnemyStateEnemy02MoveBase , public EnemyStateMove
{
public:
	//コンストラクタ
	EnemyStateEnemy02Move(
		const EnemyBasePtr& enemy,
		const float speed);
	// 各状態独自の初期化
	virtual void onUniqueInit()override;
	// 更新処理
	virtual void onUpdate(float deltaTime)override;

	//メッセージ処理
	virtual void handleMessage(EventMessage message, void* param) override;
};

#endif // !ENEMYSTATEENEMY02MOVE_H_