#include "EnemyStateEnemy02Move.h"

EnemyStateEnemy02Move::EnemyStateEnemy02Move(const EnemyBasePtr & enemy, const float speed)
	: EnemyStateEnemy02MoveBase(enemy)
	, m_Speed(speed) {
}

void EnemyStateEnemy02Move::onUniqueInit() {

}

void EnemyStateEnemy02Move::onUpdate(float deltaTime) {
	//ˆÚ“®ˆ—
	Move(deltaTime, m_Speed);
}