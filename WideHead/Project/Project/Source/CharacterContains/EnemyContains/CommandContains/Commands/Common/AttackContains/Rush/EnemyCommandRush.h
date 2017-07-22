#ifndef ENEMYCOMMANDRUSH_H_
#define ENEMYCOMMANDRUSH_H_

#include "../../MoveContains/StraightTouchWall/EnemyCommandStraightTouchWall.h"

//突撃
class EnemyCommandRush : public EnemyCommandStraightTouchWall
{
public:
	//コンストラクタ
	EnemyCommandRush(
		const EnemyBasePtr& enemy,
		const MapType type);
	//デストラクタ
	~EnemyCommandRush();

protected:
	//各種固有の初期化
	virtual void OnInitialize() override;

protected:
	//正面に壁があった場合のリアクション
	virtual void HitWallReaction() override;

protected:

};

#endif