#ifndef ENEMYCOMMANDPATROL_H_
#define ENEMYCOMMANDPATROL_H_

#include "../Base/EnemyCommandMoveBase.h"
#include <iostream>

//����}��
class EnemyCommandPatrol : public EnemyCommandMoveBase
{
public:
	//�R���X�g���N�^
	EnemyCommandPatrol(
		const EnemyBasePtr& enemy,
		const std::string fileName,
		const MapType type);

	//������W��ݒ�
	void SetPatrolPos(const std::string fileName);

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