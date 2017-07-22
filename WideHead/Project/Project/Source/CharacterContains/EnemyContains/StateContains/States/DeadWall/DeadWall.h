#ifndef DEADWALL_H_
#define DEADWALL_H_

#include"../Base/EnemyStateBase.h"

class DeadWall : public EnemyStateBase
{
public:
	//�R���X�g���N�^
	DeadWall(const EnemyBasePtr& enemy);;
	// �e��ԓƎ��̏�����
	virtual void unique_init() override;
	// �X�V����
	virtual void update(float deltaTime) override;
	// �Փ˔���
	virtual void collide(const Actor & other, const Body::ContactSet& contactSet) override {}
	// �I�����̏���
	virtual void end() override;
};

#endif // !DEADWALL_H_
