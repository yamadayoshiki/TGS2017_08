#ifndef ENEMYSTATESTOP_H_
#define ENEMYSTATESTOP_H_

#include "../Base/EnemyStateBase.h"

//動かない
class EnemyStateStop : public EnemyStateBase
{
public:
	//コンストラクタ
	EnemyStateStop(const EnemyBasePtr& enemy, int limitTimer);
	//各種固有の初期化処理
	virtual void unique_init() override;
	//更新処理
	virtual void update(float deltaTime) override;
	// 衝突判定
	virtual void collide(const Actor & other) override {}
	// 終了時の処理
	virtual void end() override {}

protected:
	int m_LimitTimer;
	int m_Timer;
};

#endif // !ENEMYSTATESTOP_H_