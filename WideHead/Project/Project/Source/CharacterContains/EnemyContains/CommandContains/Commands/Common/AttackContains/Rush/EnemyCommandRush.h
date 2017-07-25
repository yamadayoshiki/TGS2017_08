#ifndef ENEMYCOMMANDRUSH_H_
#define ENEMYCOMMANDRUSH_H_

#include "../../MoveContains/StraightTouchWall/EnemyCommandStraightTW.h"

//�ˌ�
class EnemyCommandRush : public EnemyCommandStraightTW
{
public:
	//�R���X�g���N�^
	EnemyCommandRush(
		const EnemyBasePtr& enemy,
		const MapType type);
	//�f�X�g���N�^
	~EnemyCommandRush();

protected:
	//�e��ŗL�̏�����
	virtual void OnInitialize() override;

protected:
	//���ʂɕǂ��������ꍇ�̃��A�N�V����
	virtual void HitWallReaction() override;
};

#endif