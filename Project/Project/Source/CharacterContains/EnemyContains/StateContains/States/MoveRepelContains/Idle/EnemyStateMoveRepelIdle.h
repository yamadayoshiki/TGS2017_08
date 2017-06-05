#ifndef ENEMYSTATEMOVEREPELIDLE_H_
#define ENEMYSTATEMOVEREPELIDLE_H_

#include "../Base/EnemyStateMoveRepelBase.h"
#include "../../MoveContains/Idle/EnemyStateIdle.h"

class EnemyStateMoveRepelIdle : public EnemyStateMoveRepelBase,public EnemyStateIdle
{
public:
	//�R���X�g���N�^
	EnemyStateMoveRepelIdle(const EnemyBasePtr& enemy);
	// �e��ԓƎ��̏�����
	virtual void onUniqueInit()override;

	// ���b�Z�[�W����
	virtual void handleMessage(EventMessage message, void* param) override;
};

#endif // !ENEMYSTATEMOVEREPELIDLE_H_