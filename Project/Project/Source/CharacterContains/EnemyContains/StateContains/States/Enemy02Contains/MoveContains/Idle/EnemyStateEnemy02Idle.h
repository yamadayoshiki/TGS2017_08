#ifndef ENEMYSTATEENEMY02IDLE_H_
#define ENEMYSTATEENEMY02IDLE_H_

#include "../MoveBase/EnemyStateEnemy02MoveBase.h"

//Enemy02��pIdle
class EnemyStateEnemy02Idle : public EnemyStateEnemy02MoveBase
{
public:
	//�R���X�g���N�^
	EnemyStateEnemy02Idle(const EnemyBasePtr& enemy);
	// �e��ԓƎ��̏�����
	virtual void onUniqueInit()override {}
	// �X�V����
	virtual void onUpdate(float deltaTime)override {}
	// �Փ˔���
	virtual void onCollide(const Actor & other)override {}
	// �I�����̏���
	virtual void onEnd()override {}
	// ���͏���
	virtual void onInput() override {}
};


#endif // !ENEMYSTATEENEMY02IDLE_H_
