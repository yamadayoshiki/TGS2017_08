#ifndef ENEMYSTATEMOVEBASESTANDARD_H_
#define ENEMYSTATEMOVEBASESTANDARD_H_

#include "../../../Base/EnemyStateBase.h"

// 通常時の移動クラスのベース
class EnemyStateMoveBaseStandard : virtual public EnemyStateBase
{
public:
	// コンストラクタ
	EnemyStateMoveBaseStandard(const EnemyBasePtr& enemy);
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
	virtual void onUniqueInit() {}
	// 更新処理
	virtual void onUpdate(float deltaTime) {}
	// 衝突判定
	virtual void onCollide(const Actor & other, const Body::ContactSet& contactSet) {}
	// 終了時の処理
	virtual void onEnd() {}
	// 入力処理
	virtual void onInput() {}
	// メッセージ処理
	virtual void OnHandleMessage(EventMessage message, void* param) override;
};

#endif