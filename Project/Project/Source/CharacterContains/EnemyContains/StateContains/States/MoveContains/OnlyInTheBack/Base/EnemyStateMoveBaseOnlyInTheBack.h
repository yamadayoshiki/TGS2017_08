#ifndef ENEMYSTATEMOVEBASEONLYINTHEBACK_H_
#define ENEMYSTATEMOVEBASEONLYINTHEBACK_H_

#include "../../Standard/Base/EnemyStateMoveBaseStandard.h"

//Enemy02��p�ړ����N���X
class EnemyStateMoveBaseOnlyInTheBack : virtual public EnemyStateMoveBaseStandard
{
public:
	// �R���X�g���N�^
	EnemyStateMoveBaseOnlyInTheBack(const EnemyBasePtr& enemy);
protected:
	//���b�Z�[�W����
	virtual void OnHandleMessage(EventMessage message, void* param) override;
};

#endif