#ifndef ENEMYSTATEIDLESTANDARD_H_
#define ENEMYSTATEIDLESTANDARD_H_

#include "../Base/EnemyStateMoveBaseStandard.h"

//�ҋ@���
class EnemyStateIdleStandard :virtual public EnemyStateMoveBaseStandard
{
public:
	//�R���X�g���N�^
	EnemyStateIdleStandard(const EnemyBasePtr& enemy);
	// �e��ԓƎ��̏�����
	virtual void onUniqueInit()override;
};

#endif