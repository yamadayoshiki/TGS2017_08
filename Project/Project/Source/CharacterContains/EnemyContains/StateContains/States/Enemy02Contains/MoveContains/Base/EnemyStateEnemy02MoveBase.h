#ifndef ENEMYSTATEENEMY02MOVEBASE_H_
#define ENEMYSTATEENEMY02MOVEBASE_H_

#include "../../../MoveContains/Base/EnemyStateMoveBase.h"

//Enemy02専用移動基底クラス
class EnemyStateEnemy02MoveBase : virtual public EnemyStateMoveBase
{
public:
	// コンストラクタ
	EnemyStateEnemy02MoveBase(const EnemyBasePtr& enemy);
	//メッセージ処理
	virtual void handleMessage(EventMessage message, void* param) override;
};

#endif