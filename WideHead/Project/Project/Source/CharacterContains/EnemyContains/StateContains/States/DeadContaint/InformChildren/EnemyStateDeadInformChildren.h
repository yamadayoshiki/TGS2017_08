#ifndef ENEMYSTATEDEADINFORMCHILDREN_H_
#define ENEMYSTATEDEADINFORMCHILDREN_H_

#include "../Standard/EnemyStateDeadStandard.h"

//�q�����E��
class EnemyStateDeadInformChildren : public EnemyStateDeadStandard
{
public:
	//�R���X�g���N�^
	EnemyStateDeadInformChildren(
		const EnemyBasePtr& enemy);
protected:
	// �e��ԓƎ��̏�����
	virtual void unique_init() override;
};
#endif // !ENEMYSTATEDEADINFORMCHILDREN_H_
