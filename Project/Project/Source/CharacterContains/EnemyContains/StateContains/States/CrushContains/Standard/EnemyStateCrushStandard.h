#ifndef ENEMYSTATECRUSH_H_
#define ENEMYSTATECRUSH_H_

#include "../../Base/EnemyStateBase.h"

class EnemyStateCrushStandard :public EnemyStateBase
{
public:
	//�R���X�g���N�^
	EnemyStateCrushStandard(const EnemyBasePtr& enemy);

protected:
	// �e��ԓƎ��̏�����
	virtual void unique_init() override;
	// �X�V����
	virtual void update(float deltaTime) override;
};

#endif