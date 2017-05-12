#ifndef ENEMYCOMMANDNULL_H_
#define ENEMYCOMMANDNULL_H_

#include "../Base/EnemyCommandBase.h"

class EnemyCommandNull :public EnemyCommandBase
{
public:
	//コンストラクタ
	EnemyCommandNull(const EnemyBasePtr& enemy)
		:EnemyCommandBase(enemy) {}
	//更新
	virtual void Update(float deltaTime) override {};
	//命令ステート
	virtual EnemyStateName GetCurrentStateName() const override { return EnemyStateName::None; };
	//各種固有の初期化
	void OnInitialize() override { m_IsEnd = true; }

};


#endif
