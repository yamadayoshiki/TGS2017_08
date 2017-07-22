#ifndef ENEMYSTATECAUGHTSTANDARD_H_
#define ENEMYSTATECAUGHTSTANDARD_H_

#include "../../Base/EnemyStateBase.h"


class EnemyStateCaughtStandard :public EnemyStateBase
{
public:
	//�R���X�g���N�^
	EnemyStateCaughtStandard(const EnemyBasePtr& enemy);
	// �e��ԓƎ��̏�����
	virtual void unique_init() override;
	// �X�V����
	virtual void update(float deltaTime) override;
	// �Փ˔���
	virtual void collide(const Actor & other, const Body::ContactSet& contactSet) override {}
	// �I�����̏���
	virtual void end() override;
	// ���b�Z�[�W����
	virtual void handleMessage(EventMessage message, void* param) override;
};

#endif