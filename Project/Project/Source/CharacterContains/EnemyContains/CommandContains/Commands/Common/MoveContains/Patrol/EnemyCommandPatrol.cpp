#include "EnemyCommandPatrol.h"
#include "../../../../../../../WorldContains/EventMessage/EventMessage.h"
#include "../../../../../Entity/Enemys/Base/EnemyBase.h"
#include "../../../../../StateContains/StateManager/EnemyStateManager.h"

//コンストラクタ
EnemyCommandPatrol::EnemyCommandPatrol(
	const EnemyBasePtr & enemy,
	const MapType type)
	:EnemyCommandMoveBase(enemy, type) {
}

//目標地点に到着したリアクション
void EnemyCommandPatrol::ArriveReaction()
{
}

//次の目的地を設定する
void EnemyCommandPatrol::SetNextTargetPos()
{
}