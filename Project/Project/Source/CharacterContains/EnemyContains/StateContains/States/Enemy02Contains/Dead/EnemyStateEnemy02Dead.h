#ifndef ENEMYSTATEENEMY02DEAD_H_
#define ENEMYSTATEENEMY02DEAD_H_

#include "../../Dead/EnemyStateDead.h"

class EnemyStateEnemy02Dead : public EnemyStateDead
{
public:
	//コンストラクタ
	EnemyStateEnemy02Dead(const EnemyBasePtr& enemy);
	// 各状態独自の初期化
	virtual void unique_init() override;
};


//エネミー02専用死亡クラス


#endif // !ENEMYSTATEENEMY02DEAD_H_
