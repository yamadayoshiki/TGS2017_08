#ifndef ENEMYCOMMANDENEMY07PATROL_H_
#define ENEMYCOMMANDENEMY07PATROL_H_

#include "../../Common/MoveContains/Patrol/EnemyCommandPatrol.h"

//�m�R�m�R��p����
class EnemyCommandEnemy07Patrol : public EnemyCommandPatrol
{
public:
	//�R���X�g���N�^
	EnemyCommandEnemy07Patrol(
		const EnemyBasePtr& enemy,
		const std::string fileName);

	//���b�Z�[�W����
	virtual void handleMessage(EventMessage message, void* param) override;

};

#endif // !ENEMYCOMMANDENEMY07PATROL_H_