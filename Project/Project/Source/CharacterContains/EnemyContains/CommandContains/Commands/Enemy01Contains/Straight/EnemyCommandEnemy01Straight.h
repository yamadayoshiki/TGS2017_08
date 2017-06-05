#ifndef ENEMYCOMMANDENEMY01STRAIGHT_H_
#define ENEMYCOMMANDENEMY01STRAIGHT_H_

#include "../../Common/MoveContains/Straight/EnemyCommandStraight.h"

class EnemyCommandEnemy01Straight : public EnemyCommandStraight
{
public:
	//コンストラクタ
	EnemyCommandEnemy01Straight(
		const EnemyBasePtr& enemy);

protected:
	//各種固有の初期化
	virtual void OnInitialize() override;
	//各種固有の更新
	virtual void OnUpdate(float deltaTime) override;
	//目標地点に到着したリアクション
	virtual void ArriveReaction() override;
	//正面に壁があった場合のリアクション
	virtual void HitWallReaction();

	//プレイヤーと座標軸が一致しているか
	void CheckAxisEnemyToPlayer();

protected:
	bool m_AxisChangeFlag;
};

#endif // !ENEMYCOMMANDENEMY01STRAIGHT_H_
