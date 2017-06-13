#ifndef ENEMYCOMMANDRETURNTOTHEREGULARPOSITION_H_
#define ENEMYCOMMANDRETURNTOTHEREGULARPOSITION_H_

#include "../Base/EnemyCommandMoveBase.h"

//�}�X�����̐��K�ʒu�ɖ߂�
class EnemyCommandReturnRegularPos : public EnemyCommandMoveBase
{
public:
	//�R���X�g���N�^
	EnemyCommandReturnRegularPos(
		const EnemyBasePtr& enemy,
		const MapType type);

protected:
	//�e��ŗL�̏�����
	virtual void OnInitialize() override;
protected:
	//�ڕW�n�_�ɓ����������A�N�V����
	virtual void ArriveReaction() override;
	//���̖ڕW�n�_��ݒ肷��
	virtual void SetNextTargetPos() override;
};

#endif