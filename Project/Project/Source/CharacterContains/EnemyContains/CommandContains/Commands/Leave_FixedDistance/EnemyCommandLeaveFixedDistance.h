#ifndef ENEMYCOMMANDLEAVEFIXEDDISTANCE_H_
#define ENEMYCOMMANDLEAVEFIXEDDISTANCE_H_

#include "../Base/EnemyCommandBase.h"

struct GSvector2;

//目標から一定距離離れる
class EnemyCommandLeaveFixedDistance :public EnemyCommandBase
{
public:
	//コンストラクタ
	EnemyCommandLeaveFixedDistance(const EnemyBasePtr& enemy, float fixedDistance);
	//更新
	virtual void Update(float deltaTime) override;
	//終了
	virtual void Finalize() override;
	//終了チェック
	virtual bool IsEnd() override;
	//命令ステート
	virtual EnemyStateName GetCurrentStateName() const override;
	//目標座標の設定
	void SetTargetPos(const GSvector2& targetPos);
	//離れる距離の設定
	void SetFixedDistance(const float fixedDistance);
protected:
	//各種固有の初期化
	virtual void OnInitialize() override;

protected:
	GSvector2 m_TargetPos;		//目標座標
	float  m_FixedDistance;		//目標までの距離
};

#endif
