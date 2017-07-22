#ifndef ENEMYSTATEIDLEONLYINTHEBACK_H_
#define ENEMYSTATEIDLEONLYINTHEBACK_H_

#include "../Base/EnemyStateMoveBaseOnlyInTheBack.h"
#include "../../Standard/Idle/EnemyStateIdleStandard.h"

//Enemy02��pIdle
class EnemyStateIdleOnlyInTheBack : public EnemyStateMoveBaseOnlyInTheBack, public EnemyStateIdleStandard
{
public:
	//�R���X�g���N�^
	EnemyStateIdleOnlyInTheBack(const EnemyBasePtr& enemy);
	// �e��ԓƎ��̏�����
	virtual void onUniqueInit()override;
	//���b�Z�[�W����
	virtual void handleMessage(EventMessage message, void* param) override;
};

#endif