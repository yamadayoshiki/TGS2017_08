#ifndef ENEMYCOMMANDENEMYBULLET01STRAIGHTTOUCHWALL_H_
#define ENEMYCOMMANDENEMYBULLET01STRAIGHTTOUCHWALL_H_

#include "../../Common/MoveContains/StraightTouchWall/EnemyCommandStraightTW.h"

class EnemyCommandEB01Straight : public EnemyCommandStraightTW
{
public:
	//�R���X�g���N�^
	EnemyCommandEB01Straight(
		const EnemyBasePtr& enemy,
		const MapType type);

protected:
	//���ʂɕǂ��������ꍇ�̃��A�N�V����
	virtual void HitWallReaction();

};

#endif // !EnemyCommandEnemyBullet01StraightTouchWall_H_
