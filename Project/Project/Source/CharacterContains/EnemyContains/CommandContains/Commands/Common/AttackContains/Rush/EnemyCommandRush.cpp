#include "EnemyCommandRush.h"

EnemyCommandRush::EnemyCommandRush(const EnemyBasePtr & enemy, const MapType type, const TurnDirection turnDirection)
	:EnemyCommandBase(enemy) {
}

EnemyCommandRush::~EnemyCommandRush()
{
}

void EnemyCommandRush::Finalize()
{
}

void EnemyCommandRush::OnInitialize()
{
}

void EnemyCommandRush::OnUpdate(float deltaTime)
{
}