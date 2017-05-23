#ifndef ENEMYCOMMANDSTOP_H_
#define ENEMYCOMMANDSTOP_H_

#include "../Base/EnemyCommandBase.h"

class EnemyCommandStop :public virtual EnemyCommandBase
{
public:
	//コンストラクタ
	EnemyCommandStop(const EnemyBasePtr& enemy, int stopTimer);
	//更新
	virtual void Update(float deltaTime) override;
	//終了
	virtual void Finalize() override;

protected:
	//各種固有の初期化
	virtual void OnInitialize() override;

protected:
	int m_EndTimer;
	int m_StopTimer;
};

#endif // !Enemy_Command_Idle