#include "EnemyStateStopOnlyInTheBack.h"

EnemyStateStopOnlyInTheBack::EnemyStateStopOnlyInTheBack(const EnemyBasePtr & enemy, float limitTimer)
	: EnemyStateBase(enemy)
	, EnemyStateMoveBaseOnlyInTheBack(enemy)
	, EnemyStateMoveBaseStandard(enemy)
	, EnemyStateStopStandard(enemy,limitTimer) {
}

void EnemyStateStopOnlyInTheBack::unique_init(){
	EnemyStateStopStandard::unique_init();
}

void EnemyStateStopOnlyInTheBack::update(float deltaTime){
	EnemyStateStopStandard::update(deltaTime);
}

void EnemyStateStopOnlyInTheBack::OnHandleMessage(EventMessage message, void * param){
	EnemyStateMoveBaseOnlyInTheBack::OnHandleMessage(message, param);
}
