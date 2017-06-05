#include "EnemyStateMoveRepelMove.h"
#include "../../../../Entity/Enemys/Base/EnemyBase.h"
#include "../../../../CommandContains/CommandManagers/Interface/IEnemyCommandManager.h"

EnemyStateMoveRepelMove::EnemyStateMoveRepelMove(const EnemyBasePtr & enemy, const float speed)
	: EnemyStateBase(enemy)
	, EnemyStateMoveBase(enemy)
	, EnemyStateMove(enemy, speed)
	, EnemyStateMoveRepelBase(enemy) {
}

void EnemyStateMoveRepelMove::onUniqueInit() {
	EnemyStateMove::onUniqueInit();
}

void EnemyStateMoveRepelMove::onUpdate(float deltaTime) {
	EnemyStateMove::onUpdate(deltaTime);
}

void EnemyStateMoveRepelMove::handleMessage(EventMessage message, void * param){
	EnemyStateMoveRepelBase::handleMessage(message, param);
}