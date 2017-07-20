#ifndef ENEMYSTATEDAMAGE_H_
#define ENEMYSTATEDAMAGE_H_
#include "../Base/EnemyStateBase.h"
#include "../../../../../ActorContains/ActorPtr.h"
class EnemyStateDamage : public EnemyStateBase
{
public:
	EnemyStateDamage(const EnemyBasePtr& enemy,const int damage = 5);
protected:
	// 各種固有の初期化
	virtual void unique_init() override;
	// 各種固有の更新処理
	virtual void update(float deltaTime) override;
	// 各種固有の終了処理
	virtual void end() override;

private:
	ActorPtr p_Explosion;
	int m_Damage;
};

#endif // !1
