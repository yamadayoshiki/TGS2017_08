#ifndef ENEMYSTATEMOVEBASE_H_
#define ENEMYSTATEMOVEBASE_H_

#include "../../Base/EnemyStateBase.h"

// 通常時の移動クラスのベース
class EnemyStateMoveBase : public EnemyStateBase
{
public:
	// コンストラクタ
	EnemyStateMoveBase(const EnemyBasePtr& enemy);
	// 各状態独自の初期化
	virtual void unique_init() override;
	// 更新処理
	virtual void update(float deltaTime) override;
	// 衝突判定
	virtual void collide(const Actor & other) override;
	// 終了時の処理
	virtual void end() override;
	// 入力処理
	virtual void input() override;
	// メッセージ処理
	virtual void handleMessage(EventMessage message, void* param) override;

protected:
	// 各状態独自の初期化
	virtual void onUniqueInit() = 0;
	// 更新処理
	virtual void onUpdate(float deltaTime) = 0;
	// 衝突判定
	virtual void onCollide(const Actor & other) = 0;
	// 終了時の処理
	virtual void onEnd() = 0;
	// 入力処理
	virtual void onInput() = 0;
};

#endif