#include "ESCaughtCharge.h"
#include "../../../../Entity/Enemys/Base/EnemyBase.h"
#include "../../../../../../WorldContains/IWorld.h"
#include "../../../../../../WorldContains/EventMessage/EventMessage.h"
#include "../../../../../../Base/GameManagerContains/IGameManager.h"
#include "../../../../../PlayerContains/Player/Player_Parameter.h"
ESCaughtCharge::ESCaughtCharge(const EnemyBasePtr & enemy)
	: EnemyStateCaughtStandard(enemy) {
}

void ESCaughtCharge::handleMessage(EventMessage message, void * param) {
	switch (message)
	{
	case EventMessage::PLAYER_CRUSH:
		if (p_Enemy.lock()->GetGameMgr()->GetPlayerParameter().getChargeFlag() == true) {
			change(EnemyStateName::Crush);
			p_Enemy.lock()->GetHitPoint().Decrease(1 + (int)param);
		}
		break;

	case EventMessage::PLAYER_RELEASE:
		change(EnemyStateName::Stop);
		break;
	}
}
