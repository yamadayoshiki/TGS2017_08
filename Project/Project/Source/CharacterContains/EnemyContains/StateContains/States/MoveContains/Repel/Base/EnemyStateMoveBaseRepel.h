#ifndef ENEMYSTATEMOVEBASEREPEL_H_
#define ENEMYSTATEMOVEBASEREPEL_H_

#include "../../Standard/Base/EnemyStateMoveBaseStandard.h"

class EnemyStateMoveBaseRepel : virtual public EnemyStateMoveBaseStandard
{
public:
	//�R���X�g���N�^
	EnemyStateMoveBaseRepel(const EnemyBasePtr& enemy);
protected:
	// ���b�Z�[�W����
	virtual void OnHandleMessage(EventMessage message, void* param) override;
};

#endif