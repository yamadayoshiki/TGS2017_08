#ifndef ENEMYSTATEMOVEREPELIDLE_H_
#define ENEMYSTATEMOVEREPELIDLE_H_

#include "../Base/EnemyStateMoveRepelBase.h"

class EnemyStateMoveRepelIdle : public EnemyStateMoveRepelBase
{
public:
	//�R���X�g���N�^
	EnemyStateMoveRepelIdle(const EnemyBasePtr& enemy);
	// �e��ԓƎ��̏�����
	virtual void onUniqueInit()override;
};

#endif // !ENEMYSTATEMOVEREPELIDLE_H_
