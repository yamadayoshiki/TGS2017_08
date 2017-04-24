#ifndef ENEMY_COMMAND_BASE_H_
#define ENEMY_COMMAND_BASE_H_

#include <gslib.h>
#include "../Enemy_ICommand.h"
#include "../../EnemyStateName.h"

class Enemy_Command_Base :public Enemy_ICommand
{
public:
	//�R���X�g���N�^
	Enemy_Command_Base();
	//���z�f�X�g���N�^
	virtual ~Enemy_Command_Base() { Finalize(); }
	//������
	virtual void Initialize() override;
	//�I�����Ă��邩
	virtual bool IsEnd() override;
	//�ړ��x�N�g���̎擾
	GSvector2& GetVelocity() override;
	//�X�e�[�g�I���t���O�̐ݒ�
	virtual void SetStateEnd(bool stateEnd) override;

public:
	//�X�V
	virtual void Update() override = 0;
	//�I��
	virtual void Finalize()override {};
	//���߃X�e�[�g
	virtual EnemyStateName GetCurrentStateName()override = 0;

protected:
	//�e��ŗL�̏�����
	virtual void OnInitialize() {};

protected:
	bool m_IsEnd;			//�I���t���O
	bool m_StateEnd;		//�X�e�[�g�I���t���O
	GSvector2 m_Velocity;	//�ړ��x�N�g��
};

#endif // !ENEMY_COMMAND_BASE_H_
