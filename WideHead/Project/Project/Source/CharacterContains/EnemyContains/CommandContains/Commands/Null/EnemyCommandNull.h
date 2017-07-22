#ifndef ENEMYCOMMANDNULL_H_
#define ENEMYCOMMANDNULL_H_

#include "../Base/EnemyCommandBase.h"

class EnemyCommandNull :public EnemyCommandBase
{
public:
	//�R���X�g���N�^
	EnemyCommandNull(const EnemyBasePtr& enemy)
		:EnemyCommandBase(enemy) {}
	//�e��ŗL�̏�����
	void OnInitialize() override { m_IsEnd = true; }
};


#endif
