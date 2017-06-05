#ifndef ENEMYSTATEENEMY07IDLE_H_
#define ENEMYSTATEENEMY07IDLE_H_

#include "../Base/EnemyStateEnemy07MoveBase.h"
#include "../../../MoveContains/Idle/EnemyStateIdle.h"

class EnemyStateEnemy07Idle : public EnemyStateEnemy07MoveBase, public EnemyStateIdle
{
public:
	//�R���X�g���N�^
	EnemyStateEnemy07Idle(const EnemyBasePtr& enemy);
	// �e��ԓƎ��̏�����
	virtual void onUniqueInit()override;
	//���b�Z�[�W����
	virtual void handleMessage(EventMessage message, void* param) override;
};

#endif