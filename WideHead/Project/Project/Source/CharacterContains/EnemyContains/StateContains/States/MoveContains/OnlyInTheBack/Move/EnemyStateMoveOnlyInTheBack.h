#ifndef ENEMYSTATEENEMY02MOVE_H_
#define ENEMYSTATEENEMY02MOVE_H_

#include "../Base/EnemyStateMoveBaseOnlyInTheBack.h"
#include "../../Standard/Move/EnemyStateMoveStandard.h"

//Enemy02��pMove
class EnemyStateMoveOnlyInTheBack : public EnemyStateMoveBaseOnlyInTheBack, public EnemyStateMoveStandard
{
public:
	//�R���X�g���N�^
	EnemyStateMoveOnlyInTheBack(
		const EnemyBasePtr& enemy,
		const float speed);
	// �e��ԓƎ��̏�����
	virtual void onUniqueInit()override;
	// �X�V����
	virtual void onUpdate(float deltaTime)override;

protected:
	//���b�Z�[�W����
	virtual void OnHandleMessage(EventMessage message, void* param) override;
};

#endif // !ENEMYSTATEENEMY02MOVE_H_