#ifndef ENEMY_COMMAND_IDLE_H_
#define ENEMY_COMMAND_IDLE_H_

#include "../Base/Enemy_Command_Base.h"

class Enemy_Command_Idle:public Enemy_Command_Base
{
public:
	//コンストラクタ
	Enemy_Command_Idle();
	//更新
	virtual void Update() override;
	//終了
	virtual void Finalize() override;
	//命令ステート
	virtual EnemyStateName GetCurrentStateName() override;

	//
};

#endif // !Enemy_Command_Idle
