#ifndef ENEMYCOMMANDPATROL_H_
#define ENEMYCOMMANDPATROL_H_

#include "../Base/EnemyCommandMoveBase.h"

//巡回マン
class EnemyCommandPatrol : public EnemyCommandMoveBase
{
public:
	//コンストラクタ
	EnemyCommandPatrol(
		const EnemyBasePtr& enemy,
		const MapType type);

protected:
	//目標地点に到着したリアクション
	virtual void ArriveReaction() override;
	//次の目標地点を設定する
	void SetNextTargetPos() override;
};


#endif // !ENEMYCOMMANDPATROL_H_