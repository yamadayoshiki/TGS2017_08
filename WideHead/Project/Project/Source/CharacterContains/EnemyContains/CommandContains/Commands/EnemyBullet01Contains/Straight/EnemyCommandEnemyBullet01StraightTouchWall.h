#ifndef ENEMYCOMMANDENEMYBULLET01STRAIGHTTOUCHWALL_H_
#define ENEMYCOMMANDENEMYBULLET01STRAIGHTTOUCHWALL_H_

#include "../../Common/MoveContains/StraightTouchWall/EnemyCommandStraightTouchWall.h"

class EnemyCommandEnemyBullet01StraightTouchWall : public EnemyCommandStraightTouchWall
{
public:
	//�R���X�g���N�^
	EnemyCommandEnemyBullet01StraightTouchWall(
		const EnemyBasePtr& enemy,
		const MapType type);

protected:
	//���ʂɕǂ��������ꍇ�̃��A�N�V����
	virtual void HitWallReaction();

};

#endif // !EnemyCommandEnemyBullet01StraightTouchWall_H_
