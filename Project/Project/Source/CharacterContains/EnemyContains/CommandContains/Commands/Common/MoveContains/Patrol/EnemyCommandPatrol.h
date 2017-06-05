#ifndef ENEMYCOMMANDPATROL_H_
#define ENEMYCOMMANDPATROL_H_

#include "../Base/EnemyCommandMoveBase.h"

//����}��
class EnemyCommandPatrol : public EnemyCommandMoveBase
{
public:
	//�R���X�g���N�^
	EnemyCommandPatrol(
		const EnemyBasePtr& enemy,
		const MapType type);

protected:
	//�ڕW�n�_�ɓ����������A�N�V����
	virtual void ArriveReaction() override;
	//���̖ڕW�n�_��ݒ肷��
	void SetNextTargetPos() override;
};


#endif // !ENEMYCOMMANDPATROL_H_