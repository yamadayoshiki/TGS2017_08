#ifndef ENEMYSTATEDEADINFORM_H_
#define ENEMYSTATEDEADINFORM_H_

#include "../Standard/EnemyStateDeadStandard.h"

//�G�l�~�[02��p���S�N���X

class EnemyStateDeadInform : public EnemyStateDeadStandard
{
public:
	//�R���X�g���N�^
	EnemyStateDeadInform(const EnemyBasePtr& enemy, const ActorName name);
	// �e��ԓƎ��̏�����
	virtual void unique_init() override;

protected:
	ActorName m_Name;
};

#endif