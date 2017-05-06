#ifndef ENEMYSTATEWALK_H_
#define ENEMYSTATEWALK_H_

#include "../MoveBase/EnemyStateMoveBase.h"

class EnemyStateWalk :public EnemyStateMoveBase
{
public:
	//�R���X�g���N�^
	EnemyStateWalk(const EnemyBasePtr& enemy);
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

#endif // !ENEMY_COMMONSTATE_WALK
