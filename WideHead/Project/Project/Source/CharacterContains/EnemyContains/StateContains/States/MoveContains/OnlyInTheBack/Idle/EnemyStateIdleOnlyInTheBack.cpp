#include "EnemyStateIdleOnlyInTheBack.h"

EnemyStateIdleOnlyInTheBack::EnemyStateIdleOnlyInTheBack(const EnemyBasePtr & enemy)
	: EnemyStateBase(enemy)
	, EnemyStateMoveBaseStandard(enemy)
	, EnemyStateIdleStandard(enemy)
	, EnemyStateMoveBaseOnlyInTheBack(enemy) {
}

void EnemyStateIdleOnlyInTheBack::onUniqueInit() {
	EnemyStateIdleStandard::onUniqueInit();
}

void EnemyStateIdleOnlyInTheBack::handleMessage(EventMessage message, void * param) {
	EnemyStateMoveBaseOnlyInTheBack::handleMessage(message, param);
}