#ifndef DEADWALL_H_
#define DEADWALL_H_

#include"../Base/EnemyStateBase.h"

class DeadWall : public EnemyStateBase
{
public:
	//コンストラクタ
	DeadWall(const EnemyBasePtr& enemy);;
	// 各状態独自の初期化
	virtual void unique_init() override;
	// 更新処理
	virtual void update(float deltaTime) override;
	// 衝突判定
	virtual void collide(const Actor & other, const Body::ContactSet& contactSet) override {}
	// 終了時の処理
	virtual void end() override;
};

#endif // !DEADWALL_H_
