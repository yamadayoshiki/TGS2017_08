#ifndef ENEMY_COMMAND_APPROACH_FIXEDDISTANCE_H_
#define ENEMY_COMMAND_APPROACH_FIXEDDISTANCE_H_

#include "../Base/Enemy_Command_Base.h"

struct GSvector2;

class Enemy_Command_Approach_FixedDistance:public Enemy_Command_Base
{
public:
	//コンストラクタ
	Enemy_Command_Approach_FixedDistance();
	//更新
	virtual void Update() override;
	//終了
	virtual void Finalize() override;
	//命令ステート
	virtual EnemyStateName GetCurrentStateName() override;

	//目標座標の指定
	void SetTargetPos(GSvector2* targetPos);
protected:
	//各種固有の初期化
	virtual void OnInitialize() override;

protected:
	//目標
	GSvector2* p_TargetPos;
};

#endif // !ENEMY_COMMAND_APPROACH_FIXEDDISTANCE_H_
