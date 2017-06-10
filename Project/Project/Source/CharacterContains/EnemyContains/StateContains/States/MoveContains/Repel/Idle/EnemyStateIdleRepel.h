#ifndef ENEMYSTATEIDLEREPEL_H_
#define ENEMYSTATEIDLEREPEL_H_

#include "../Base/EnemyStateMoveBaseRepel.h"
#include "../../Standard/Idle/EnemyStateIdleStandard.h"

class EnemyStateIdleRepel : public EnemyStateMoveBaseRepel,public EnemyStateIdleStandard
{
public:
	//�R���X�g���N�^
	EnemyStateIdleRepel(const EnemyBasePtr& enemy);
	// �e��ԓƎ��̏�����
	virtual void onUniqueInit()override;

	// ���b�Z�[�W����
	virtual void handleMessage(EventMessage message, void* param) override;
};

#endif // !ENEMYSTATEMOVEREPELIDLE_H_