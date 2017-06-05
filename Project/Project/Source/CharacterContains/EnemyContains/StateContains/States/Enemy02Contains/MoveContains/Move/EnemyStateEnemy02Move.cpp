#include "EnemyStateEnemy02Move.h"

EnemyStateEnemy02Move::EnemyStateEnemy02Move(const EnemyBasePtr & enemy, const float speed)
	: EnemyStateBase(enemy)
	, EnemyStateMoveBase(enemy)
	, EnemyStateMove(enemy,speed)
	, EnemyStateEnemy02MoveBase(enemy) {
}

void EnemyStateEnemy02Move::onUniqueInit() {
	EnemyStateMove::onUniqueInit();
}

void EnemyStateEnemy02Move::onUpdate(float deltaTime) {
	EnemyStateMove::onUpdate(deltaTime);
}

void EnemyStateEnemy02Move::handleMessage(EventMessage message, void * param){
	EnemyStateEnemy02MoveBase::handleMessage(message, param);
}
