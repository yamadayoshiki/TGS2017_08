#ifndef ENEMYCOMMANDNULL_H_
#define ENEMYCOMMANDNULL_H_

#include "../Base/EnemyCommandBase.h"

class EnemyCommandNull :public EnemyCommandBase
{
public:
	//�R���X�g���N�^
	EnemyCommandNull(const EnemyBasePtr& enemy)
		:EnemyCommandBase(enemy) {}
	//�X�V
	virtual void Update(float deltaTime) override {};
	//�I���`�F�b�N
	virtual bool IsEnd() override { return true; };
	//���߃X�e�[�g
	virtual EnemyStateName GetCurrentStateName() const override { return EnemyStateName::None; };

};


#endif
