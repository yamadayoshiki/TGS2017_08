#ifndef ENEMYCOMMANDAPPROACHFIXEDDISTANCE_H_
#define ENEMYCOMMANDAPPROACHFIXEDDISTANCE_H_

#include "../Base/EnemyCommandBase.h"

struct GSvector2;

//�ڕW�Ɉ�苗���߂Â�
class EnemyCommandApproachFixedDistance :public virtual EnemyCommandBase
{
public:
	//�R���X�g���N�^
	EnemyCommandApproachFixedDistance(const EnemyBasePtr& enemy, float fixedDistance);
	//�X�V
	virtual void Update(float deltaTime) override;
	//�I��
	virtual void Finalize() override;
	//���߃X�e�[�g
	virtual EnemyStateName GetCurrentStateName() const override;
	//�ڕW���W�̎w��
	void SetTargetPos(const GSvector2& targetPos);
	//�߂Â������̐ݒ�
	void SetFixedDistance(float fixedDistance);
protected:
	//�e��ŗL�̏�����
	virtual void OnInitialize() override;

protected:
	GSvector2 m_NextTargetPos;		//�ڕW���W
	float  m_FixedDistance;		//�ڕW�܂ł̋���
};

#endif