#include "EnemyCommandRush.h"
#include "../../../../../StateContains/States/EnemyStateName.h"
#include "../../../../../Entity/Enemys/Base/EnemyBase.h"
#include "../../../../../StateContains/StateManager/EnemyStateManager.h"
#include "../../../../../../../WorldContains/EventMessage/EventMessage.h"

EnemyCommandRush::EnemyCommandRush(
	const EnemyBasePtr & enemy,
	const MapType type)
	:EnemyCommandStraightTouchWall(enemy,type) {
}

EnemyCommandRush::~EnemyCommandRush(){
}

void EnemyCommandRush::OnInitialize(){
	EnemyCommandStraight::OnInitialize();
	m_CurStateName = EnemyStateName::Rush;
}

void EnemyCommandRush::HitWallReaction(){
	p_Enemy.lock()->GetStateManager()->handleMessage(EventMessage::ENEMY_STATEEND, nullptr);
	Change(EnemyCommandName::ReturnToTheRegularPosition);
}