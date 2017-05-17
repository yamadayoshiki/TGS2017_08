#ifndef ENEMYSTATECRUSH_H_
#define ENEMYSTATECRUSH_H_

#include "../Base/EnemyStateBase.h"

class EnemyStateCrush :public EnemyStateBase
{
public:
	//�R���X�g���N�^
	EnemyStateCrush(const EnemyBasePtr& enemy);
protected:
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
