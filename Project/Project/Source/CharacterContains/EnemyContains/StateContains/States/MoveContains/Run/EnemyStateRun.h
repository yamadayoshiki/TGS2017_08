#ifndef ENEMYSTATERUN_H_
#define ENEMYSTATERUN_H_

#include "../MoveBase/EnemyStateMoveBase.h"

class EnemyStateRun :public EnemyStateMoveBase
{
public:
	//�R���X�g���N�^
	EnemyStateRun(const EnemyBasePtr& enemy);
protected:
	// �e��ԓƎ��̏�����
	virtual void onUniqueInit()override;
	// �X�V����
	virtual void onUpdate(float deltaTime)override;
	// �Փ˔���
	virtual void onCollide(const Actor & other)override {}
	// �I�����̏���
	virtual void onEnd()override {}
	// ���͏���
	virtual void onInput() override {}
};

#endif
