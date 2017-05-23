#ifndef ENEMYCOMMANDENEMY01DETOUR_H_
#define ENEMYCOMMANDENEMY01DETOUR_H_

#include "../../AlongWallMove/EnemyCommandAlongWallMove.h"

//壁を挟んで空いてるマスに、壁沿いに最短の回転方向で移動
class EnemyCommandEnemy01Detour : public EnemyCommandAlongWallMove
{
public:
	//コンストラクタ
	EnemyCommandEnemy01Detour(
		const EnemyBasePtr& enemy);
	//デストラクタ
	~EnemyCommandEnemy01Detour();

protected:
	//各種固有の初期化
	virtual void OnInitialize() override;
	//各種固有の更新
	virtual void OnUpdate(float deltaTime) override;
	//目標地点に到着したリアクション
	virtual void ArriveReaction() override;
	//目標地点の設定
	virtual void SetTargetPos() override;
	//目標地点管理の取得
	TargetPosition GetTargetPositionManager();

	//プレイヤーと座標軸が一致しているか
	void CheckAxisEnemyToPlayer();

protected:
	bool m_AxisChangeFlag;
};

#endif // !ENEMYCOMMANDENEMY01DETOUR_H_