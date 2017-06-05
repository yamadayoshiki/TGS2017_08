#ifndef ENEMYSTATEENEMY07MOVE_H_
#define ENEMYSTATEENEMY07MOVE_H_

#include "../Base/EnemyStateEnemy07MoveBase.h"
#include "../../../MoveContains/Move/EnemyStateMove.h"

class EnemyStateEnemy07Move : public EnemyStateEnemy07MoveBase, public EnemyStateMove
{
public:
	//�R���X�g���N�^
	EnemyStateEnemy07Move(
		const EnemyBasePtr& enemy,
		const float speed);
	// �e��ԓƎ��̏�����
	virtual void onUniqueInit()override;
	// �X�V����
	virtual void onUpdate(float deltaTime)override;

	//���b�Z�[�W����
	virtual void handleMessage(EventMessage message, void* param) override;
};
#endif // !ENEMYSTATEENEMY07MOVE_H_
