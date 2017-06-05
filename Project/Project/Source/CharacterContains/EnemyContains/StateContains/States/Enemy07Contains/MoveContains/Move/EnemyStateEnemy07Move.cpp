#include "EnemyStateEnemy07Move.h"

EnemyStateEnemy07Move::EnemyStateEnemy07Move(const EnemyBasePtr & enemy, const float speed)
	: EnemyStateBase(enemy)
	, EnemyStateMoveBase(enemy)
	, EnemyStateEnemy07MoveBase(enemy)
	, EnemyStateMove(enemy, speed) {
}

void EnemyStateEnemy07Move::onUniqueInit(){
	EnemyStateMove::onUniqueInit();
}

void EnemyStateEnemy07Move::onUpdate(float deltaTime){
	EnemyStateMove::onUpdate(deltaTime);
}

void EnemyStateEnemy07Move::handleMessage(EventMessage message, void * param){
	EnemyStateEnemy07MoveBase::handleMessage(message,param);
}
