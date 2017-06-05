#ifndef ENEMYSTATESTOP_H_
#define ENEMYSTATESTOP_H_

#include "../Base/EnemyStateBase.h"

//�����Ȃ�
class EnemyStateStop : public EnemyStateBase
{
public:
	//�R���X�g���N�^
	EnemyStateStop(const EnemyBasePtr& enemy, float limitTimer);
	//�e��ŗL�̏���������
	virtual void unique_init() override;
	//�X�V����
	virtual void update(float deltaTime) override;
	// �Փ˔���
	virtual void collide(const Actor & other) override {}
	// �I�����̏���
	virtual void end() override {}

protected:
	float m_LimitTimer;	//���t���[���~�܂�̂�
	float m_Timer;		//�^�C�}�[
};

#endif // !ENEMYSTATESTOP_H_