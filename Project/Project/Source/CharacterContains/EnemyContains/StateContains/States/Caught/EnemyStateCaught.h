#ifndef ENEMYSTATECAUGHT_H_
#define ENEMYSTATECAUGHT_H_

#include "../Base/EnemyStateBase.h"
#include "../../../../CharacterManagerContains/CharacterManager/CharacterManager.h"


class EnemyStateCaught :public EnemyStateBase
{
public:
	//�R���X�g���N�^
	EnemyStateCaught(const EnemyBasePtr& enemy);
	// �e��ԓƎ��̏�����
	virtual void unique_init() override;
	// �X�V����
	virtual void update(float deltaTime) override;
	// �Փ˔���
	virtual void collide(const Actor & other) override;
	// �I�����̏���
	virtual void end() override;
	// ���b�Z�[�W����
	virtual void handleMessage(EventMessage message, void* param) override;
};

#endif