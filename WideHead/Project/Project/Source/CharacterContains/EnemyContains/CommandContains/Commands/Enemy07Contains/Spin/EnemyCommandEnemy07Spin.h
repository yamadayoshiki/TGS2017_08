#ifndef ENEMYCOMMANDENEMY07SPIN_H_
#define ENEMYCOMMANDENEMY07SPIN_H_

#include "../../Common/MoveContains/Straight/EnemyCommandStraight.h"

//�m�R�m�R�X�s���R�}���h
//�w��񐔈ȏ�o�E���h����Ǝ���
class EnemyCommandEnemy07Spin : public EnemyCommandStraight
{
public:
	//�R���X�g���N�^
	EnemyCommandEnemy07Spin(
		const EnemyBasePtr& enemy,
		const int limitSpringCounter);

protected:
	//���ʂɕǂ��������ꍇ�̃��A�N�V����
	virtual void HitWallReaction();

protected:
	int m_SpringCounter;		//���˕Ԃ�����
	int m_LimitSpringCounter;	//���˕Ԃ�񐔏��
};


#endif
