#ifndef ENEMYSTATEREPEL_H_
#define ENEMYSTATEREPEL_H_

#include "../Base/EnemyStateBase.h"

// アームを弾く
class EnemyStateRepel :public EnemyStateBase
{
public:
	//コンストラクタ
	EnemyStateRepel(const EnemyBasePtr& enemy);
	// 各状態独自の初期化
	virtual void unique_init() override;
	// 更新処理
	virtual void update(float deltaTime) override;
	// 衝突判定
	virtual void collide(const Actor & other) override;
	// 終了時の処理
	virtual void end() override;
};

#endif