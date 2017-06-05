#ifndef ENEMYCOMMANDALONGWALLMOVE_H_
#define ENEMYCOMMANDALONGWALLMOVE_H_

#include "../Base/EnemyCommandMoveBase.h"
#include "../../../../../../../Utility/FourDirection/FourDirection.h"

//先行宣言
class TargetPosition;

//壁沿いに進む
class EnemyCommandAlongWallMove :public EnemyCommandMoveBase
{
public:
	//コンストラクタ
	EnemyCommandAlongWallMove(
		const EnemyBasePtr& enemy,
		const MapType type,
		const TurnDirection turnDirection);
	//デストラクタ
	~EnemyCommandAlongWallMove();
	//終了
	virtual void Finalize() override;

protected:
	//各種固有の初期化
	virtual void OnInitialize() override;
	//各種固有の更新
	virtual void OnUpdate(float deltaTime) override;
	//目標地点に到着したリアクション
	virtual void ArriveReaction() override;
	//次の目標地点を設定する
	virtual void SetNextTargetPos()override {}

protected:
	//目標地点の設定
	virtual void SetTargetPos();

protected:
	TurnDirection m_TurnDirection;		//回転方向
	TargetPosition* p_TargetPosition;	//目標地点管理
};

#endif