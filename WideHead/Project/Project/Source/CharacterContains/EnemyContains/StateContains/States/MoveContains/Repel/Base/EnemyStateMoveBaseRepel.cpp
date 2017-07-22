#include "EnemyStateMoveBaseRepel.h"
#include "../../../../../../../WorldContains/EventMessage/EventMessage.h"

//コンストラクタ
EnemyStateMoveBaseRepel::EnemyStateMoveBaseRepel(const EnemyBasePtr& enemy)
	: EnemyStateBase(enemy)
	, EnemyStateMoveBaseStandard(enemy) {
}

//メッセージ処理
void EnemyStateMoveBaseRepel::OnHandleMessage(EventMessage message, void * param) {
	switch (message)
	{
	case EventMessage::PLAYER_ROUNDS:
		change(EnemyStateName::Repel);
		break;
	}
}