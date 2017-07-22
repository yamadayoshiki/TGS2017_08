#include "EnemyCommandEnemyBullet01StraightTouchWall.h"
#include "../../../../Entity/Enemys/Base/EnemyBase.h"
#include "../../../../StateContains/StateManager/EnemyStateManager.h"
#include "../../../../../../WorldContains/EventMessage/EventMessage.h"

EnemyCommandEnemyBullet01StraightTouchWall::EnemyCommandEnemyBullet01StraightTouchWall(
	const EnemyBasePtr & enemy,
	const MapType type)
	: EnemyCommandStraightTouchWall(enemy, type) {
}

void EnemyCommandEnemyBullet01StraightTouchWall::HitWallReaction() {
	//Ž€‚Ê
	p_Enemy.lock()->GetStateManager()->handleMessage(EventMessage::ENEMY_COMMAND_DEAD, nullptr);
}
