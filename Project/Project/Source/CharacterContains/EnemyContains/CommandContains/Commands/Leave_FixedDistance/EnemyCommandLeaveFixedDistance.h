#ifndef ENEMYCOMMANDLEAVEFIXEDDISTANCE_H_
#define ENEMYCOMMANDLEAVEFIXEDDISTANCE_H_

#include "../Base/EnemyCommandBase.h"

struct GSvector2;

//�ڕW�����苗�������
class EnemyCommandLeaveFixedDistance :public EnemyCommandBase
{
public:
	//�R���X�g���N�^
	EnemyCommandLeaveFixedDistance(const EnemyBasePtr& enemy, float fixedDistance);
	//�X�V
	virtual void Update(float deltaTime) override;
	//�I��
	virtual void Finalize() override;
	//�I���`�F�b�N
	virtual bool IsEnd() override;
	//���߃X�e�[�g
	virtual EnemyStateName GetCurrentStateName() const override;
	//�ڕW���W�̐ݒ�
	void SetTargetPos(const GSvector2& targetPos);
	//����鋗���̐ݒ�
	void SetFixedDistance(const float fixedDistance);
protected:
	//�e��ŗL�̏�����
	virtual void OnInitialize() override;

protected:
	GSvector2 m_TargetPos;		//�ڕW���W
	float  m_FixedDistance;		//�ڕW�܂ł̋���
};

#endif
