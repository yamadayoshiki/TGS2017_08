#include "EnemyCommandEnemy09Rush.h"
#include "../../../../StateContains/States/EnemyStateName.h"

EnemyCommandEnemy09Rush::EnemyCommandEnemy09Rush(
	const EnemyBasePtr & enemy)
	: EnemyCommandRush(enemy, MapType::Double) {
}

EnemyCommandEnemy09Rush::~EnemyCommandEnemy09Rush()
{
}

void EnemyCommandEnemy09Rush::HitWallReaction() {
	EnemyCommandRush::HitWallReaction();
	Change(EnemyCommandName::ReturnToTheRegularPosition);
}