#include "EnemyStateDeadInformChildren.h"
#include "../../../../Entity/Enemys/Base/EnemyBase.h"
#include "../../../../../../WorldContains/EventMessage/EventMessage.h"

EnemyStateDeadInformChildren::EnemyStateDeadInformChildren(
	const EnemyBasePtr & enemy)
	: EnemyStateDeadStandard(enemy) {
}

void EnemyStateDeadInformChildren::unique_init(){
	p_Enemy.lock()->eachChildren([](Actor& child) {child.handleMessage(EventMessage::ENEMY_COMMAND_DEAD, nullptr); });
}