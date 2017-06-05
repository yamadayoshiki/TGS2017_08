#include "EnemyStateEnemy07Idle.h"

EnemyStateEnemy07Idle::EnemyStateEnemy07Idle(const EnemyBasePtr & enemy)
	: EnemyStateBase(enemy)
	, EnemyStateMoveBase(enemy)
	, EnemyStateEnemy07MoveBase(enemy)
	, EnemyStateIdle(enemy) {
}

void EnemyStateEnemy07Idle::onUniqueInit(){
	EnemyStateIdle::onUniqueInit();
}

void EnemyStateEnemy07Idle::handleMessage(EventMessage message, void * param){
	EnemyStateEnemy07MoveBase::handleMessage(message, param);
}
