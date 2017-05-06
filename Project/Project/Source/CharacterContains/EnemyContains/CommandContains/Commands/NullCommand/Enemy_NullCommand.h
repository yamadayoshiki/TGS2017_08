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
	//終了チェック
	virtual bool IsEnd() override { return true; };
	//命令ステート
	virtual EnemyStateName GetCurrentStateName() const override { return EnemyStateName::None; };

};


#endif
