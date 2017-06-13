#ifndef ENEMYCOMMANDENEMY09RUSH_H_
#define ENEMYCOMMANDENEMY09RUSH_H_

#include "../../Common/AttackContains/Rush/EnemyCommandRush.h"

//突撃
class EnemyCommandEnemy09Rush : public EnemyCommandRush
{
public:
	//コンストラクタ
	EnemyCommandEnemy09Rush(
		const EnemyBasePtr& enemy);
	//デストラクタ
	~EnemyCommandEnemy09Rush();

protected:
	//正面に壁があった場合のリアクション
	virtual void HitWallReaction() override;
};

#endif // !ENEMYCOMMANDENEMY09RUSH_H_
