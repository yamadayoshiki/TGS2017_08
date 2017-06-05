#ifndef ENEMYSTATEMOVEREPELMOVE_H_
#define ENEMYSTATEMOVEREPELMOVE_H_

#include "../Base/EnemyStateMoveRepelBase.h"
#include "../../MoveContains/Move/EnemyStateMove.h"

class EnemyStateMoveRepelMove : public EnemyStateMoveRepelBase, public EnemyStateMove
{
public:
	//�R���X�g���N�^
	EnemyStateMoveRepelMove(const EnemyBasePtr& enemy,
		const float speed);
	// �e��ԓƎ��̏�����
	virtual void onUniqueInit()override;
	// �X�V����
	virtual void onUpdate(float deltaTime)override;

	// ���b�Z�[�W����
	virtual void handleMessage(EventMessage message, void* param) override;
};

#endif // !ENEMYSTATEMOVEREPELMOVE_H_
