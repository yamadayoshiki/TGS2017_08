#ifndef ENEMYCOMMANDALONGWALLMOVE_H_
#define ENEMYCOMMANDALONGWALLMOVE_H_

#include "../Base/EnemyCommandBase.h"
#include "../../../../../Utility/FourDirection/FourDirection.h"

//壁沿いに進む
class EnemyCommandAlongWallMove :public EnemyCommandBase
{
public:
	//コンストラクタ
	EnemyCommandAlongWallMove(const EnemyBasePtr& enemy, const TurnDirection turnDirection);
	//更新
	virtual void Update(float deltaTime) override;
	//終了
	virtual void Finalize() override;
	//回転方向の設定
	void SetTurnDirection(TurnDirection turnDirection);

protected:
	//各種固有の初期化
	virtual void OnInitialize() override;
	//目標地点の設定
	void SetTargetPos();


protected:
	TurnDirection m_TurnDirection;		//回転方向
	FourDirection m_CurDirection;		//現在の進行方向
	GSvector2 m_NextTargetPos;			//次の目標地点
};

#endif