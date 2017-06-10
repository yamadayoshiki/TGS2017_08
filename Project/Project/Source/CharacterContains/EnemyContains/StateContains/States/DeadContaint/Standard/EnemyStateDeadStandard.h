#ifndef ENEMYSTATEDEAD_H_
#define ENEMYSTATEDEAD_H_

#include "../../Base/EnemyStateBase.h"

class EnemyStateDeadStandard :public EnemyStateBase
{
public:
	//コンストラクタ
	EnemyStateDeadStandard(const EnemyBasePtr& enemy);
	// 各状態独自の初期化
	virtual void unique_init() override;
	// 更新処理
	virtual void update(float deltaTime) override;
	// 衝突判定
	virtual void collide(const Actor & other) override;
	// 終了時の処理
	virtual void end() override;
};
#endif // !ENEMY_COMMONSTATE_DEAD_H_
