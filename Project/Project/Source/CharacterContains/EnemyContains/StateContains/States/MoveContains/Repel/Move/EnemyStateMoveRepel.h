#ifndef ENEMYSTATEMOVEREPEL_H_
#define ENEMYSTATEMOVEREPEL_H_

#include "../Base/EnemyStateMoveBaseRepel.h"
#include "../../Standard/Move/EnemyStateMoveStandard.h"

class EnemyStateMoveRepel : public EnemyStateMoveBaseRepel, public EnemyStateMoveStandard
{
public:
	//�R���X�g���N�^
	EnemyStateMoveRepel(const EnemyBasePtr& enemy,
		const float speed);
	// �e��ԓƎ��̏�����
	virtual void onUniqueInit()override;
	// �X�V����
	virtual void onUpdate(float deltaTime)override;

	// ���b�Z�[�W����
	virtual void handleMessage(EventMessage message, void* param) override;
};

#endif // !ENEMYSTATEMOVEREPELMOVE_H_
