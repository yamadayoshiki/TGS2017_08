#include "EnemyStateCaughtReleaseDead.h"
#include "../../../../../../WorldContains/EventMessage/EventMessage.h"

EnemyStateCaughtReleaseDead::EnemyStateCaughtReleaseDead(
	const EnemyBasePtr & enemy)
	:EnemyStateCaughtStandard(enemy) {
}

void EnemyStateCaughtReleaseDead::handleMessage(EventMessage message, void * param) {
	switch (message)
	{
	case EventMessage::PLAYER_CRUSH:
		change(EnemyStateName::Crush);
		break;

	case EventMessage::PLAYER_RELEASE:
		change(EnemyStateName::Dead);
		break;
	}
}
