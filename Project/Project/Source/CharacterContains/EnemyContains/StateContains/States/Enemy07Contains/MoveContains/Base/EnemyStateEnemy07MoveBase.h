#ifndef ENEMYSTATEENEMY07MOVEBASE_H_
#define ENEMYSTATEENEMY07MOVEBASE_H_

#include "../../../MoveContains/Base/EnemyStateMoveBase.h"

//Enemy07��p�ړ����N���X
class EnemyStateEnemy07MoveBase : virtual public EnemyStateMoveBase
{
public:
	// �R���X�g���N�^
	EnemyStateEnemy07MoveBase(const EnemyBasePtr& enemy);
	//���b�Z�[�W����
	virtual void handleMessage(EventMessage message, void* param) override;
};

#endif // !ENEMYSTATEENEMY07MOVEBASE_H_
