#ifndef ENEMYCOMMANDSTOP_H_
#define ENEMYCOMMANDSTOP_H_

#include "../Base/EnemyCommandBase.h"

class EnemyCommandStop :public virtual EnemyCommandBase
{
public:
	//�R���X�g���N�^
	EnemyCommandStop(const EnemyBasePtr& enemy, int stopTimer);
	//�X�V
	virtual void Update(float deltaTime) override;
	//�I��
	virtual void Finalize() override;

protected:
	//�e��ŗL�̏�����
	virtual void OnInitialize() override;

protected:
	int m_EndTimer;
	int m_StopTimer;
};

#endif // !Enemy_Command_Idle