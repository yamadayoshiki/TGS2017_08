#ifndef ENEMYSTATEENEMY02DEAD_H_
#define ENEMYSTATEENEMY02DEAD_H_

#include "../../Dead/EnemyStateDead.h"

class EnemyStateEnemy02Dead : public EnemyStateDead
{
public:
	//�R���X�g���N�^
	EnemyStateEnemy02Dead(const EnemyBasePtr& enemy);
	// �e��ԓƎ��̏�����
	virtual void unique_init() override;
};


//�G�l�~�[02��p���S�N���X


#endif // !ENEMYSTATEENEMY02DEAD_H_
