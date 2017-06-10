#include "EnemyStateIdleRepel.h"

EnemyStateIdleRepel::EnemyStateIdleRepel(const EnemyBasePtr & enemy)
	: EnemyStateBase(enemy)
	, EnemyStateMoveBaseStandard(enemy)
	, EnemyStateIdleStandard(enemy)
	, EnemyStateMoveBaseRepel(enemy) {
}

void EnemyStateIdleRepel::onUniqueInit(){
	EnemyStateIdleStandard::onUniqueInit();
}

void EnemyStateIdleRepel::handleMessage(EventMessage message, void * param){
	EnemyStateMoveBaseStandard::handleMessage(message, param);
}
