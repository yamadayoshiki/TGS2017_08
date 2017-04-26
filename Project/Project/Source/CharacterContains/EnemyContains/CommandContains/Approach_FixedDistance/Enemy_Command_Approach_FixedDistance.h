#ifndef ENEMY_COMMAND_APPROACH_FIXEDDISTANCE_H_
#define ENEMY_COMMAND_APPROACH_FIXEDDISTANCE_H_

#include "../Base/Enemy_Command_Base.h"

struct GSvector2;

class Enemy_Command_Approach_FixedDistance :public Enemy_Command_Base
{
public:
	//コンストラクタ
	Enemy_Command_Approach_FixedDistance(float fixedDistance);
	//更新
	virtual void Update() override;
	//終了
	virtual void Finalize() override;
	//命令ステート
	virtual EnemyStateName GetCurrentStateName() override;

	//目標座標の指定
	void SetTargetPos(const GSvector2& targetPos);
protected:
	//各種固有の初期化
	virtual void OnInitialize() override;

protected:
	GSvector2 m_TargetPos;		//目標
	float  m_FixedDistance;		//目標までの距離
};

#endif // !ENEMY_COMMAND_APPROACH_FIXEDDISTANCE_H_
