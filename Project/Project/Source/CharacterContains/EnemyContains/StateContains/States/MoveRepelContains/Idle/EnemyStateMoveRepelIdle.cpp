#include "EnemyStateMoveRepelIdle.h"

EnemyStateMoveRepelIdle::EnemyStateMoveRepelIdle(const EnemyBasePtr & enemy)
	: EnemyStateBase(enemy)
	, EnemyStateMoveBase(enemy)
	, EnemyStateIdle(enemy)
	, EnemyStateMoveRepelBase(enemy) {
}

void EnemyStateMoveRepelIdle::onUniqueInit(){
	EnemyStateIdle::onUniqueInit();
}

void EnemyStateMoveRepelIdle::handleMessage(EventMessage message, void * param){
	EnemyStateMoveRepelBase::handleMessage(message, param);
}
