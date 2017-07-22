#include "EnemyStateMoveOnlyInTheBack.h"

EnemyStateMoveOnlyInTheBack::EnemyStateMoveOnlyInTheBack(const EnemyBasePtr & enemy, const float speed)
	: EnemyStateBase(enemy)
	, EnemyStateMoveBaseStandard(enemy)
	, EnemyStateMoveStandard(enemy, speed)
	, EnemyStateMoveBaseOnlyInTheBack(enemy) {
}

void EnemyStateMoveOnlyInTheBack::onUniqueInit() {
	EnemyStateMoveStandard::onUniqueInit();
}

void EnemyStateMoveOnlyInTheBack::onUpdate(float deltaTime) {
	EnemyStateMoveStandard::onUpdate(deltaTime);
}

void EnemyStateMoveOnlyInTheBack::OnHandleMessage(EventMessage message, void * param) {
	EnemyStateMoveBaseOnlyInTheBack::OnHandleMessage(message, param);
}
