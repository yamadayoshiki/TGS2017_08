#ifndef ENEMYCOMMANDENEMY09RUSH_H_
#define ENEMYCOMMANDENEMY09RUSH_H_

#include "../../Common/AttackContains/Rush/EnemyCommandRush.h"

//�ˌ�
class EnemyCommandEnemy09Rush : public EnemyCommandRush
{
public:
	//�R���X�g���N�^
	EnemyCommandEnemy09Rush(
		const EnemyBasePtr& enemy);
	//�f�X�g���N�^
	~EnemyCommandEnemy09Rush();

protected:
	//���ʂɕǂ��������ꍇ�̃��A�N�V����
	virtual void HitWallReaction() override;
};

#endif // !ENEMYCOMMANDENEMY09RUSH_H_
