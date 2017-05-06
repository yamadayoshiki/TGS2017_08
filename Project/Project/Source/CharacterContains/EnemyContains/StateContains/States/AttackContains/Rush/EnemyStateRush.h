#ifndef ENEMYSTATERUSH_H_
#define ENEMYSTATERUSH_H_

#include "../AttackBase/EnemyStateAttackBase.h"

//�ˌ�
class EnemyStateRush :public EnemyStateAttackBase
{
public:
	//�R���X�g���N�^
	EnemyStateRush(const EnemyBasePtr& enemy);
protected:
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
