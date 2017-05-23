#ifndef ENEMYCOMMANDAPPROACHFIXEDDISTANCE_H_
#define ENEMYCOMMANDAPPROACHFIXEDDISTANCE_H_

#include "../Base/EnemyCommandBase.h"

struct GSvector2;

//目標に一定距離近づく
class EnemyCommandApproachFixedDistance :public virtual EnemyCommandBase
{
public:
	//コンストラクタ
	EnemyCommandApproachFixedDistance(const EnemyBasePtr& enemy, float fixedDistance);
	//更新
	virtual void Update(float deltaTime) override;
	//終了
	virtual void Finalize() override;
	//命令ステート
	virtual EnemyStateName GetCurrentStateName() const override;
	//目標座標の指定
	void SetTargetPos(const GSvector2& targetPos);
	//近づく距離の設定
	void SetFixedDistance(float fixedDistance);
protected:
	//各種固有の初期化
	virtual void OnInitialize() override;

protected:
	GSvector2 m_NextTargetPos;		//目標座標
	float  m_FixedDistance;		//目標までの距離
};

#endif