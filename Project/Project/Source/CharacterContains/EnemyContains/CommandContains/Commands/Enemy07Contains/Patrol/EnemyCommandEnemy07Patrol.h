#ifndef ENEMYCOMMANDENEMY07PATROL_H_
#define ENEMYCOMMANDENEMY07PATROL_H_

#include "../../Common/MoveContains/Patrol/EnemyCommandPatrol.h"

//ノコノコ専用巡回
class EnemyCommandEnemy07Patrol : public EnemyCommandPatrol
{
public:
	//コンストラクタ
	EnemyCommandEnemy07Patrol(
		const EnemyBasePtr& enemy,
		const std::string fileName);

	//メッセージ処理
	virtual void handleMessage(EventMessage message, void* param) override;

};

#endif // !ENEMYCOMMANDENEMY07PATROL_H_