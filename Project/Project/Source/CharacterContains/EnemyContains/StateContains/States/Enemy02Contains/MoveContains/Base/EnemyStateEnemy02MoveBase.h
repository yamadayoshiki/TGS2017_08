#ifndef ENEMYSTATEENEMY02MOVEBASE_H_
#define ENEMYSTATEENEMY02MOVEBASE_H_

#include "../../../MoveContains/Base/EnemyStateMoveBase.h"

//Enemy02��p�ړ����N���X
class EnemyStateEnemy02MoveBase : virtual public EnemyStateMoveBase
{
public:
	// �R���X�g���N�^
	EnemyStateEnemy02MoveBase(const EnemyBasePtr& enemy);
	//���b�Z�[�W����
	virtual void handleMessage(EventMessage message, void* param) override;
};

#endif