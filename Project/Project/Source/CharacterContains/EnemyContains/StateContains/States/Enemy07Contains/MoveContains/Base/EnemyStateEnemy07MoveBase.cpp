#include "EnemyStateEnemy07MoveBase.h"
#include "../../../../../../../WorldContains/EventMessage/EventMessage.h"

//コンストラクタ
EnemyStateEnemy07MoveBase::EnemyStateEnemy07MoveBase(const EnemyBasePtr & enemy)
	: EnemyStateBase(enemy)
	, EnemyStateMoveBase(enemy) {
}

void EnemyStateEnemy07MoveBase::handleMessage(EventMessage message, void * param){
	switch (message)
	{
	case EventMessage::PLAYER_ROUNDS:
		change(EnemyStateName::Spin);
		break;
	default:
		break;
	}
}