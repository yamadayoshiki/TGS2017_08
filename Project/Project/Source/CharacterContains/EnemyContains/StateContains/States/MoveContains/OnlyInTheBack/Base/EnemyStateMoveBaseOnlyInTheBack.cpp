#include "EnemyStateMoveBaseOnlyInTheBack.h"
#include "../../../../../../../Utility/FourDirection/FourDirection.h"
#include "../../../../../Entity/Enemys/Base/EnemyBase.h"
#include "../../../../../../../WorldContains/EventMessage/EventMessage.h"
#include "../../../../../CommandContains/CommandManagers/Interface/IEnemyCommandManager.h"
#include "../../../../../PlayerWatch/PlayerWatch.h"
#include "../../../EnemyStateName.h"
#include "../../../../../../../Map/MapType.h"
#include "../../../../../../../ActorContains/Transform/Transform.h"

//コンストラクタ
EnemyStateMoveBaseOnlyInTheBack::EnemyStateMoveBaseOnlyInTheBack(const EnemyBasePtr & enemy)
	: EnemyStateBase(enemy)
	, EnemyStateMoveBaseStandard(enemy) {
}

//メッセージ処理
void EnemyStateMoveBaseOnlyInTheBack::OnHandleMessage(EventMessage message, void * param) {
	switch (message)
	{
		//プレイヤーに挟まれたとき
	case EventMessage::PLAYER_ROUNDS:
		FourDirection toPlayerDir 
			= FourDirection(p_Enemy.lock()->GetPlayerWatch()->GetToPlayerDis());
		//背後にプレイヤーがいる
		if (FourDirection(p_Enemy.lock()->getTransform()->m_Angle) == toPlayerDir.GetTurnOver())
			change(EnemyStateName::Caught);

		else
			change(EnemyStateName::Repel);
		break;
	}
}