#ifndef ENEMYSTATEIDLE_H_
#define ENEMYSTATEIDLE_H_

#include "../Base/EnemyStateMoveBase.h"

//�ҋ@���
class EnemyStateIdle :virtual public EnemyStateMoveBase
{
public:
	//�R���X�g���N�^
	EnemyStateIdle(const EnemyBasePtr& enemy);
	// �e��ԓƎ��̏�����
	virtual void onUniqueInit()override;
};

#endif