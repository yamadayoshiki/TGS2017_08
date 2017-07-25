#ifndef ENEMYCOMMANDENEMYBULLET01STRAIGHTTOUCHWALL_H_
#define ENEMYCOMMANDENEMYBULLET01STRAIGHTTOUCHWALL_H_

#include "../../Common/MoveContains/StraightTouchWall/EnemyCommandStraightTW.h"

class EnemyCommandEB01Straight : public EnemyCommandStraightTW
{
public:
	//コンストラクタ
	EnemyCommandEB01Straight(
		const EnemyBasePtr& enemy,
		const MapType type);

protected:
	//正面に壁があった場合のリアクション
	virtual void HitWallReaction();

};

#endif // !EnemyCommandEnemyBullet01StraightTouchWall_H_
