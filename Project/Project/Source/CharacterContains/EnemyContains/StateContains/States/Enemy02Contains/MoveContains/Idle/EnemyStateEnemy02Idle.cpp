#include "EnemyStateEnemy02Idle.h"

EnemyStateEnemy02Idle::EnemyStateEnemy02Idle(const EnemyBasePtr & enemy)
	: EnemyStateBase(enemy)
	, EnemyStateMoveBase(enemy)
	, EnemyStateIdle(enemy)
	, EnemyStateEnemy02MoveBase(enemy) {
}

void EnemyStateEnemy02Idle::onUniqueInit(){
	EnemyStateIdle::onUniqueInit();
}

void EnemyStateEnemy02Idle::handleMessage(EventMessage message, void * param) {
	EnemyStateEnemy02MoveBase::handleMessage(message, param);
}