#ifndef ENEMYSTATERUSHPRELIMINARY_H_
#define ENEMYSTATERUSHPRELIMINARY_H_

#include "../Base/EnemyStateAttackBase.h"

class EnemyStateRushPreliminary :public EnemyStateAttackBase
{
public:
	//コンストラクタ
	EnemyStateRushPreliminary(const EnemyBasePtr& enemy);
protected:
	// 各状態独自の初期化
	virtual void onUniqueInit() override;
	// 更新処理
	virtual void onUpdate(float deltaTime) override;
	// 衝突判定
	virtual void onCollide(const Actor & other, const Body::ContactSet& contactSet) override;
	// 終了時の処理
	virtual void onEnd() override;
	// 入力処理
	virtual void onInput() override;
};
#endif
