#ifndef ENEMYSTATEMOVEREPELBASE_H_
#define ENEMYSTATEMOVEREPELBASE_H_

#include "../../MoveContains/Base/EnemyStateMoveBase.h"

class EnemyStateMoveRepelBase : public EnemyStateMoveBase
{
public:
	//�R���X�g���N�^
	EnemyStateMoveRepelBase(const EnemyBasePtr& enemy);
	// ���b�Z�[�W����
	virtual void handleMessage(EventMessage message, void* param) override;
};

#endif // !ENEMYSTATEMOVEREPELBASE_H_
