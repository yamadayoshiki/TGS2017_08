#ifndef ENEMYSTATERUSHPRELIMINARY_H_
#define ENEMYSTATERUSHPRELIMINARY_H_

#include "../Base/EnemyStateAttackBase.h"

class EnemyStateRushPreliminary :public EnemyStateAttackBase
{
public:
	//�R���X�g���N�^
	EnemyStateRushPreliminary(const EnemyBasePtr& enemy,const int loop);
protected:
	// �e��ԓƎ��̏�����
	virtual void onUniqueInit() override;
	// �X�V����
	virtual void onUpdate(float deltaTime) override;
	// �Փ˔���
	virtual void onCollide(const Actor & other, const Body::ContactSet& contactSet) override;
	// �I�����̏���
	virtual void onEnd() override;

private:
	int m_Loop;
};
#endif
