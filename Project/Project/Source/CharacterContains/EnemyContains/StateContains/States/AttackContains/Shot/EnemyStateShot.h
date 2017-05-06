#ifndef ENEMYSTATESHOT_H_
#define ENEMYSTATESHOT_H_

#include "../AttackBase/EnemyStateAttackBase.h"

class EnemyStateShot :public EnemyStateAttackBase
{
public:
	//�R���X�g���N�^
	EnemyStateShot(const EnemyBasePtr& enemy);
public:
	// �e��ԓƎ��̏�����
	virtual void onUniqueInit() override;
	// �X�V����
	virtual void onUpdate(float deltaTime) override;
	// �Փ˔���
	virtual void onCollide(const Actor & other) override;
	// �I�����̏���
	virtual void onEnd() override;
	// ���͏���
	virtual void onInput() override;
};

#endif
