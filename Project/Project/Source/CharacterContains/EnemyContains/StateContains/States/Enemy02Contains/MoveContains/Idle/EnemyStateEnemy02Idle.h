#ifndef ENEMYSTATEENEMY02IDLE_H_
#define ENEMYSTATEENEMY02IDLE_H_

#include "../Base/EnemyStateEnemy02MoveBase.h"
#include "../../../MoveContains/Idle/EnemyStateIdle.h"

//Enemy02��pIdle
class EnemyStateEnemy02Idle : public EnemyStateEnemy02MoveBase,public EnemyStateIdle
{
public:
	//�R���X�g���N�^
	EnemyStateEnemy02Idle(const EnemyBasePtr& enemy);
	// �e��ԓƎ��̏�����
	virtual void onUniqueInit()override;
	//���b�Z�[�W����
	virtual void handleMessage(EventMessage message, void* param) override;
};

#endif