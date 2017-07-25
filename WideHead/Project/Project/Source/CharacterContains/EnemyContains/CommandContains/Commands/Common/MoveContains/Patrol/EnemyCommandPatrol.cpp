#include "EnemyCommandPatrol.h"
#include "../../../../../../../WorldContains/EventMessage/EventMessage.h"
#include "../../../../../../../WorldContains/IWorld.h"
#include "../../../../../../../Map/Map.h"
#include "../../../../../Entity/Enemys/Base/EnemyBase.h"
#include "../../../../../StateContains/StateManager/EnemyStateManager.h"
#include "../../../../../Entity/Enemys/Base/EnemyBase.h"
#include "../../../../../../../CsvConvertTDV/CsvConvertTDV.h"
#include "../../../../../../../CsvConvertTDV/CsvCellData.h"
#include <iterator>
#include <forward_list>

//コンストラクタ
EnemyCommandPatrol::EnemyCommandPatrol(
	const EnemyBasePtr & enemy,
	const std::string fileName,
	const MapType type)
	: EnemyCommandMoveBase(enemy, type)
	, m_CurListNum(0) {
	SetPatrolPos(fileName);
}

//巡回座標を設定
void EnemyCommandPatrol::SetPatrolPos(const std::string fileName) {
	std::vector<CsvCellData> csvCellDatavector = std::vector<CsvCellData>(CsvConvertTDV::GetPatrolPos(fileName));
	m_TargetPosList = std::vector<GSvector2>(CsvConvertTDV::GetPatrolPosList(csvCellDatavector, m_Type));
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