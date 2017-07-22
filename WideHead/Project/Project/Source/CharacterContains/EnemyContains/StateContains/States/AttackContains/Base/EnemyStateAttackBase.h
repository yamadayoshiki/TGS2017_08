#ifndef ENEMYSTATEATTACKBASE_H_
#define ENEMYSTATEATTACKBASE_H_

#include "../../Base/EnemyStateBase.h"

//�U����Ԃ̊��N���X
class EnemyStateAttackBase :public EnemyStateBase
{
public:
	// �R���X�g���N�^
	EnemyStateAttackBase(const EnemyBasePtr& enemy);
	// �e��ԓƎ��̏�����
	virtual void unique_init() override;
	// �X�V����
	virtual void update(float deltaTime) override;
	// �Փ˔���
	virtual void collide(const Actor & other, const Body::ContactSet& contactSet) override;
	// �I�����̏���
	virtual void end() override;
	// ���͏���
	virtual void input() override;
protected:
	// �e��ԓƎ��̏�����
	virtual void onUniqueInit() = 0;
	// �X�V����
	virtual void onUpdate(float deltaTime) = 0;
	// �Փ˔���
	virtual void onCollide(const Actor & other, const Body::ContactSet& contactSet) = 0;
	// �I�����̏���
	virtual void onEnd() = 0;
	// ���͏���
	virtual void onInput() {}
};

#endif
