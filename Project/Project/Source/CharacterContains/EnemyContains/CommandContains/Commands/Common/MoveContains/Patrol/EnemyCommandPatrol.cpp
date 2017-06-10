#include "EnemyCommandPatrol.h"
#include "../../../../../../../WorldContains/EventMessage/EventMessage.h"
#include "../../../../../../../WorldContains/IWorld.h"
#include "../../../../../../../Map/Map.h"
#include "../../../../../Entity/Enemys/Base/EnemyBase.h"
#include "../../../../../StateContains/StateManager/EnemyStateManager.h"
#include "../../../../../Entity/Enemys/Base/EnemyBase.h"
#include <iterator>
#include <forward_list>

//コンストラクタ
EnemyCommandPatrol::EnemyCommandPatrol(
	const EnemyBasePtr & enemy,
	const MapType type)
	: EnemyCommandMoveBase(enemy, type)
	, m_CurListNum(0) {
}

//目的地を設定
void EnemyCommandPatrol::SetPatrolPos(const std::vector<GSvector2>& posList) {
	m_TargetPosList = std::vector<GSvector2>(posList);
}

//メッセージ処理
void EnemyCommandPatrol::handleMessage(EventMessage message, void * param){
	switch (message)
	{
	case EventMessage::ENEMY_SPIN:
		Change(EnemyCommandName::SpinMove);
		break;
	default:
		break;
	}
}

//目標地点に到着したリアクション
void EnemyCommandPatrol::ArriveReaction() {
	SetNextTargetPos();
}

//次の目的地を設定する
void EnemyCommandPatrol::SetNextTargetPos() {
	m_CurListNum++;
	if (m_CurListNum >= m_TargetPosList.size())
		m_CurListNum = 0;

	m_NextTargetPos = m_TargetPosList[m_CurListNum];
}