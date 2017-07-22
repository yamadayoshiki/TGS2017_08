#include "EnemyStateMoveRepel.h"

EnemyStateMoveRepel::EnemyStateMoveRepel(const EnemyBasePtr & enemy, const float speed)
	: EnemyStateBase(enemy)
	, EnemyStateMoveBaseStandard(enemy)
	, EnemyStateMoveStandard(enemy, speed)
	, EnemyStateMoveBaseRepel(enemy) {
}

void EnemyStateMoveRepel::onUniqueInit() {
	EnemyStateMoveStandard::onUniqueInit();
}

void EnemyStateMoveRepel::onUpdate(float deltaTime) {
	EnemyStateMoveStandard::onUpdate(deltaTime);
}

void EnemyStateMoveRepel::handleMessage(EventMessage message, void * param) {
	EnemyStateMoveBaseRepel::handleMessage(message, param);
}