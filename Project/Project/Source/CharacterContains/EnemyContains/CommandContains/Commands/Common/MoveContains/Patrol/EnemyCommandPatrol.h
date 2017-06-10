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

	//�ړI�n��ݒ�
	void SetPatrolPos(const std::vector<GSvector2>& posList);
	//���b�Z�[�W����
	virtual void handleMessage(EventMessage message,void* param) override;

protected:
	//�ڕW�n�_�ɓ����������A�N�V����
	virtual void ArriveReaction() override;
	//���̖ڕW�n�_��ݒ肷��
	void SetNextTargetPos() override;

protected:
	std::vector<GSvector2> m_TargetPosList;			//����n�_�z��
	int m_CurListNum;								//���݂̖ڕW�n�_�̏��񃊃X�g��ԍ�
};


#endif