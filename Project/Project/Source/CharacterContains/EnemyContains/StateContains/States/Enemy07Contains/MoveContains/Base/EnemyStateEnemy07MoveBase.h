#ifndef ENEMYSTATEENEMY07MOVEBASE_H_
#define ENEMYSTATEENEMY07MOVEBASE_H_

#include "../../../MoveContains/Base/EnemyStateMoveBase.h"

//Enemy07専用移動基底クラス
class EnemyStateEnemy07MoveBase : virtual public EnemyStateMoveBase
{
public:
	// コンストラクタ
	EnemyStateEnemy07MoveBase(const EnemyBasePtr& enemy);
	//メッセージ処理
	virtual void handleMessage(EventMessage message, void* param) override;
};

#endif // !ENEMYSTATEENEMY07MOVEBASE_H_
