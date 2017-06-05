#ifndef ENEMYCOMMANDENEMY01STRAIGHT_H_
#define ENEMYCOMMANDENEMY01STRAIGHT_H_

#include "../../Common/MoveContains/Straight/EnemyCommandStraight.h"

class EnemyCommandEnemy01Straight : public EnemyCommandStraight
{
public:
	//�R���X�g���N�^
	EnemyCommandEnemy01Straight(
		const EnemyBasePtr& enemy);

protected:
	//�e��ŗL�̏�����
	virtual void OnInitialize() override;
	//�e��ŗL�̍X�V
	virtual void OnUpdate(float deltaTime) override;
	//�ڕW�n�_�ɓ����������A�N�V����
	virtual void ArriveReaction() override;
	//���ʂɕǂ��������ꍇ�̃��A�N�V����
	virtual void HitWallReaction();

	//�v���C���[�ƍ��W������v���Ă��邩
	void CheckAxisEnemyToPlayer();

protected:
	bool m_AxisChangeFlag;
};

#endif // !ENEMYCOMMANDENEMY01STRAIGHT_H_
