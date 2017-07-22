#ifndef ENEMYSTATESTOP_H_
#define ENEMYSTATESTOP_H_

#include "../../MoveContains/Standard/Base/EnemyStateMoveBaseStandard.h"

//�����Ȃ�
class EnemyStateStopStandard : virtual public EnemyStateMoveBaseStandard
{
public:
	//�R���X�g���N�^
	EnemyStateStopStandard(const EnemyBasePtr& enemy, float limitTimer);
	//�e��ŗL�̏���������
	virtual void unique_init() override;
	//�X�V����
	virtual void update(float deltaTime) override;

protected:
	//���b�Z�[�W����
	virtual void OnHandleMessage(EventMessage message, void* param) override;

protected:
	float m_LimitTimer;	//���t���[���~�܂�̂�
	float m_Timer;		//�^�C�}�[
};

#endif // !ENEMYSTATESTOP_H_