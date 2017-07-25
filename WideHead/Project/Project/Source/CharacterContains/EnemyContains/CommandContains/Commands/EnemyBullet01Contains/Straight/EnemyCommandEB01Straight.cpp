#include "EnemyCommandEB01Straight.h"
#include "../../../../Entity/Enemys/Base/EnemyBase.h"
#include "../../../../StateContains/StateManager/EnemyStateManager.h"
#include "../../../../../../WorldContains/EventMessage/EventMessage.h"

EnemyCommandEB01Straight::EnemyCommandEB01Straight(
	const EnemyBasePtr & enemy,
	const MapType type)
	: EnemyCommandStraightTW(enemy, type) {
}

void EnemyCommandEB01Straight::HitWallReaction() {
	//Ž€‚Ê
	p_Enemy.lock()->GetStateManager()->handleMessage(EventMessage::ENEMY_COMMAND_DEAD, nullptr);
}
