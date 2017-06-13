#include "EnemyCommandEnemy07Patrol.h"
#include "../../../../../../WorldContains/EventMessage/EventMessage.h"

EnemyCommandEnemy07Patrol::EnemyCommandEnemy07Patrol(
	const EnemyBasePtr & enemy,
	const std::string fileName)
	:EnemyCommandPatrol(enemy, fileName, MapType::Double) {
}

void EnemyCommandEnemy07Patrol::handleMessage(EventMessage message, void * param) {
	switch (message)
	{
	case EventMessage::ENEMY_SPIN:
		Change(EnemyCommandName::SpinMove);
		break;
	default:
		break;
	}
}