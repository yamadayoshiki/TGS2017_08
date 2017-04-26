#ifndef ENEMY_COMMAND_APPROACH_FIXEDDISTANCE_H_
#define ENEMY_COMMAND_APPROACH_FIXEDDISTANCE_H_

#include "../Base/Enemy_Command_Base.h"

struct GSvector2;

class Enemy_Command_Approach_FixedDistance :public Enemy_Command_Base
{
public:
	//�R���X�g���N�^
	Enemy_Command_Approach_FixedDistance(float fixedDistance);
	//�X�V
	virtual void Update() override;
	//�I��
	virtual void Finalize() override;
	//���߃X�e�[�g
	virtual EnemyStateName GetCurrentStateName() override;

	//�ڕW���W�̎w��
	void SetTargetPos(const GSvector2& targetPos);
protected:
	//�e��ŗL�̏�����
	virtual void OnInitialize() override;

protected:
	GSvector2 m_TargetPos;		//�ڕW
	float  m_FixedDistance;		//�ڕW�܂ł̋���
};

#endif // !ENEMY_COMMAND_APPROACH_FIXEDDISTANCE_H_
