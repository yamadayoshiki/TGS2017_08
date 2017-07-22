#ifndef ENEMYSTATECAUGHTSTANDARD_H_
#define ENEMYSTATECAUGHTSTANDARD_H_

#include "../../Base/EnemyStateBase.h"


class EnemyStateCaughtStandard :public EnemyStateBase
{
public:
	//コンストラクタ
	EnemyStateCaughtStandard(const EnemyBasePtr& enemy);
	// 各状態独自の初期化
	virtual void unique_init() override;
	// 更新処理
	virtual void update(float deltaTime) override;
	// 衝突判定
	virtual void collide(const Actor & other, const Body::ContactSet& contactSet) override {}
	// 終了時の処理
	virtual void end() override;
	// メッセージ処理
	virtual void handleMessage(EventMessage message, void* param) override;
};

#endif