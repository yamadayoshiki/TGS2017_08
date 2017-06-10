#ifndef ENEMYSTATECRUSH_H_
#define ENEMYSTATECRUSH_H_

#include "../../Base/EnemyStateBase.h"

class EnemyStateCrushStandard :public EnemyStateBase
{
public:
	//コンストラクタ
	EnemyStateCrushStandard(const EnemyBasePtr& enemy);

protected:
	// 各状態独自の初期化
	virtual void unique_init() override;
	// 更新処理
	virtual void update(float deltaTime) override;
};

#endif