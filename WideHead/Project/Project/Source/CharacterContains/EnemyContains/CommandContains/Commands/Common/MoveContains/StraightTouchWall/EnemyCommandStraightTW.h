#ifndef ENEMYCOMMANDSTRAIGHTTOUCHWALL_H_
#define ENEMYCOMMANDSTRAIGHTTOUCHWALL_H_

#include "../Straight/EnemyCommandStraight.h"

//壁に触れるまで直進
class EnemyCommandStraightTW : public EnemyCommandStraight
{
public:
	//コンストラクタ
	EnemyCommandStraightTW(
		const EnemyBasePtr& enemy,
		const MapType type);

protected:
	//次の目標地点を設定する
	virtual void SetNextTargetPos() override;
};



#endif // !ENEMYCOMMANDSTRAIGHTTOUCHWALL_H_
