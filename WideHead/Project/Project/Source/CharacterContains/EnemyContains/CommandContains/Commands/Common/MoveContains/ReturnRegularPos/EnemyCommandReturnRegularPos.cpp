#include "EnemyCommandReturnRegularPos.h"
#include "../../../../../Entity/Enemys/Base/EnemyBase.h"
#include "../../../../../../../Utility/CsvConvertTwoDVector/CsvConvertTwoDVector.h"

EnemyCommandReturnRegularPos::EnemyCommandReturnRegularPos(
	const EnemyBasePtr & enemy,
	const MapType type)
	: EnemyCommandMoveBase(enemy, type) {
}

void EnemyCommandReturnRegularPos::OnInitialize() {
	EnemyCommandMoveBase::OnInitialize();
	m_Regard = true;
}

void EnemyCommandReturnRegularPos::ArriveReaction() {
	Change(EnemyCommandName::Standby);
}

void EnemyCommandReturnRegularPos::SetNextTargetPos() {
	//Ž©•ª‚ª‚¢‚éÀ•W
	m_NextTargetPos = CsvConvertTwoDVector::GetTilePos(p_Enemy.lock()->getPosition(), m_Type);
}
