#ifndef ENEMYCOMMANDSTNDBY_H_
#define ENEMYCOMMANDSTNDBY_H_

#include "../../Base/EnemyCommandBase.h"

//3回挟まれたら指定方向に動く
class EnemyCommandStandby : public EnemyCommandBase
{
public:
	//コンストラクタ
	EnemyCommandStandby(const EnemyBasePtr& enemy, const FourDirection front, const MapType type);
	//更新
	virtual void Update(float deltaTime) override;
	//終了
	virtual void Finalize() override;
};

#endif // !ENEMYCOMMANDSTNDBY_H_

