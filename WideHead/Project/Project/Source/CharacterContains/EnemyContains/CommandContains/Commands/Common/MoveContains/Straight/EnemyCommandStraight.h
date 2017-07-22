#ifndef ENMYCOMMANDSTRAIGHT_H_
#define ENMYCOMMANDSTRAIGHT_H_

#include "../Base/EnemyCommandMoveBase.h"
#include "../../../../../../../Map/MapType.h"

//���i�N���X
class EnemyCommandStraight :public EnemyCommandMoveBase
{
public:
	//�R���X�g���N�^
	EnemyCommandStraight(
		const EnemyBasePtr& enemy,
		const MapType type);
protected:
	//�ڕW�n�_�ɓ����������A�N�V����
	virtual void ArriveReaction() override;
	//���̖ڕW�n�_��ݒ肷��
	virtual void SetNextTargetPos() override;
protected:
	//���ʂɕǂ��������ꍇ�̃��A�N�V����
	virtual void HitWallReaction();
};

#endif