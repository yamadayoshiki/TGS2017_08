#ifndef ENEMYSTATEIDLE_H_
#define ENEMYSTATEIDLE_H_

#include "../MoveBase/EnemyStateMoveBase.h"

//�ҋ@���
class EnemyStateIdle :public EnemyStateMoveBase
{
public:
	//�R���X�g���N�^
	EnemyStateIdle(const EnemyBasePtr& enemy);
	// �e��ԓƎ��̏�����
	virtual void onUniqueInit()override;
	// �X�V����
	virtual void onUpdate(float deltaTime)override {}
	// �Փ˔���
	virtual void onCollide(const Actor & other)override {}
	// �I�����̏���
	virtual void onEnd()override {}
	// ���͏���
	virtual void onInput() override {}
};

#endif