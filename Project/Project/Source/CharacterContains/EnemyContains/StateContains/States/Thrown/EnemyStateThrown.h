#ifndef ENEMYSTATETHROWN_H_
#define ENEMYSTATETHROWN_H_

#include "../Base/EnemyStateBase.h"

class EnemyStateThrown:public EnemyStateBase
{
public:
	//�R���X�g���N�^
	EnemyStateThrown(const EnemyBasePtr& enemy);
	// �e��ԓƎ��̏�����
	virtual void unique_init() override;
	// �X�V����
	virtual void update(float deltaTime) override;
	// �Փ˔���
	virtual void collide(const Actor & other) override;
	// �I�����̏���
	virtual void end() override;
};

#endif
