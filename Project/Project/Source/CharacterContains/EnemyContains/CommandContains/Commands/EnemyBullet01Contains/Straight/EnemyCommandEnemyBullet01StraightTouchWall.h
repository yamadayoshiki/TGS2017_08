#ifndef ENEMYCOMMANDENEMYBULLET01STRAIGHTTOUCHWALL_H_
#define ENEMYCOMMANDENEMYBULLET01STRAIGHTTOUCHWALL_H_

#include "../../Common/MoveContains/StraightTouchWall/EnemyCommandStraightTouchWall.h"

class EnemyCommandEnemyBullet01StraightTouchWall : public EnemyCommandStraightTouchWall
{
public:
	//コンストラクタ
	EnemyCommandEnemyBullet01StraightTouchWall(
		const EnemyBasePtr& enemy,
		const MapType type);

protected:
	//正面に壁があった場合のリアクション
	virtual void HitWallReaction();

};

#endif // !EnemyCommandEnemyBullet01StraightTouchWall_H_
