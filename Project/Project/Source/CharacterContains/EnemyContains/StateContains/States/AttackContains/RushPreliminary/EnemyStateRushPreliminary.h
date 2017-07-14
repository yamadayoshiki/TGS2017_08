#ifndef ENEMYSTATERUSHPRELIMINARY_H_
#define ENEMYSTATERUSHPRELIMINARY_H_

#include "../Base/EnemyStateAttackBase.h"

class EnemyStateRushPreliminary :public EnemyStateAttackBase
{
public:
	//�R���X�g���N�^
	EnemyStateRushPreliminary(const EnemyBasePtr& enemy);
protected:
	// �e��ԓƎ��̏�����
	virtual void onUniqueInit() override;
	// �X�V����
	virtual void onUpdate(float deltaTime) override;
	// �Փ˔���
	virtual void onCollide(const Actor & other, const Body::ContactSet& contactSet) override;
	// �I�����̏���
	virtual void onEnd() override;
	// ���͏���
	virtual void onInput() override;
};
#endif
