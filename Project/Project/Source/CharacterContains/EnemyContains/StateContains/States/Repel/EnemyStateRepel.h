#ifndef ENEMYSTATEREPEL_H_
#define ENEMYSTATEREPEL_H_

#include "../Base/EnemyStateBase.h"

// �A�[����e��
class EnemyStateRepel :public EnemyStateBase
{
public:
	//�R���X�g���N�^
	EnemyStateRepel(const EnemyBasePtr& enemy);
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