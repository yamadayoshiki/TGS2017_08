#ifndef ENEMYSTATEDEAD_H_
#define ENEMYSTATEDEAD_H_

#include "../../Base/EnemyStateBase.h"

class EnemyStateDeadStandard :public EnemyStateBase
{
public:
	//�R���X�g���N�^
	EnemyStateDeadStandard(const EnemyBasePtr& enemy);
	// �e��ԓƎ��̏�����
	virtual void unique_init() override;
	// �X�V����
	virtual void update(float deltaTime) override;
	// �Փ˔���
	virtual void collide(const Actor & other) override;
	// �I�����̏���
	virtual void end() override;
};
#endif // !ENEMY_COMMONSTATE_DEAD_H_
