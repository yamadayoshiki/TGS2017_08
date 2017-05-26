#include "EnemyStateMoveRepelBase.h"
#include "../../../../../../WorldContains/EventMessage/EventMessage.h"

//コンストラクタ
EnemyStateMoveRepelBase::EnemyStateMoveRepelBase(const EnemyBasePtr& enemy)
	:EnemyStateMoveBase(enemy) {
}

//メッセージ処理
void EnemyStateMoveRepelBase::handleMessage(EventMessage message, void * param) {
	switch (message)
	{
	case EventMessage::PLAYER_ROUNDS:
		change(EnemyStateName::Repel);
		break;
	}
}