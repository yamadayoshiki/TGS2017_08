#ifndef ENEMY_COMMAND_IDLE_H_
#define ENEMY_COMMAND_IDLE_H_

#include "../Base/Enemy_Command_Base.h"

class Enemy_Command_Idle:public Enemy_Command_Base
{
public:
	//�R���X�g���N�^
	Enemy_Command_Idle();
	//�X�V
	virtual void Update() override;
	//�I��
	virtual void Finalize() override;
	//���߃X�e�[�g
	virtual EnemyStateName GetCurrentStateName() override;

	//
};

#endif // !Enemy_Command_Idle
