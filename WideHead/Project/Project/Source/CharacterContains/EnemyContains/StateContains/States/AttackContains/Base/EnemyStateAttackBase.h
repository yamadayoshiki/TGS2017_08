#ifndef ENEMYSTATEATTACKBASE_H_
#define ENEMYSTATEATTACKBASE_H_

#include "../../Base/EnemyStateBase.h"

//攻撃状態の基底クラス
class EnemyStateAttackBase :public EnemyStateBase
{
public:
	// コンストラクタ
	EnemyStateAttackBase(const EnemyBasePtr& enemy);
	// 各状態独自の初期化
	virtual void unique_init() override;
	// 更新処理
	virtual void update(float deltaTime) override;
	// 衝突判定
	virtual void collide(const Actor & other, const Body::ContactSet& contactSet) override;
	// 終了時の処理
	virtual void end() override;
	// 入力処理
	virtual void input() override;
protected:
	// 各状態独自の初期化
	virtual void onUniqueInit() = 0;
	// 更新処理
	virtual void onUpdate(float deltaTime) = 0;
	// 衝突判定
	virtual void onCollide(const Actor & other, const Body::ContactSet& contactSet) = 0;
	// 終了時の処理
	virtual void onEnd() = 0;
	// 入力処理
	virtual void onInput() {}
};

#endif
