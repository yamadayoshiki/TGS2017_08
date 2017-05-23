#ifndef ENEMYCOMMANDROTATION_H_
#define ENEMYCOMMANDROTATION_H_

#include "../Base/EnemyCommandBase.h"

class EnemyCommandRotation :public virtual EnemyCommandBase
{
public:
	//�R���X�g���N�^
	EnemyCommandRotation(
		const EnemyBasePtr& enemy,	//�G�l�~�[�{��
		const float angle,			//��]�p�x
		const float endTimer		//��]�I���܂ł̎���
		);
	//�X�V
	virtual void Update(float deltaTime) override;
	//�I��
	virtual void Finalize() override;

protected:
	//�e��ŗL�̏�����
	virtual void OnInitialize() override;

protected:
	float m_Angle;			//��]�p�x
	float m_Angle_PerFrame;	//���t���[���̉�]�p�x
	float m_EndTimer;		//��]�I���܂ł̎���
	float m_Timer;			//�^�C�}�[
};

#endif