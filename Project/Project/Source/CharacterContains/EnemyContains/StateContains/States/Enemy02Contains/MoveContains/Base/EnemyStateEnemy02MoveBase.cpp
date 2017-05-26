#include "EnemyStateEnemy02MoveBase.h"
#include "../../../../../Enemys/Base/EnemyBase.h"
#include "../../../../../../../WorldContains/EventMessage/EventMessage.h"
#include "../../../../../CommandContains/CommandManagers/Interface/IEnemyCommandManager.h"
#include "../../../../../PlayerWatch/PlayerWatch.h"
#include "../../../EnemyStateName.h"
#include "../../../../../../../Map/MapType.h"

//コンストラクタ
EnemyStateEnemy02MoveBase::EnemyStateEnemy02MoveBase(const EnemyBasePtr & enemy)
	:EnemyStateMoveBase(enemy) {
}

//メッセージ処理
void EnemyStateEnemy02MoveBase::handleMessage(EventMessage message, void * param) {
	switch (message)
	{
		//プレイヤーに挟まれたとき
	case EventMessage::PLAYER_ROUNDS:
		FourDirection toPlayerDir = FourDirection(p_Enemy->GetPlayerWatch()->GetToPlayerChipDis(MapType::Default));
		//背後にプレイヤーがいる
		if (p_Enemy->GetDirection() == toPlayerDir.GetTurnOver())
			change(EnemyStateName::Caught);

		else
			change(EnemyStateName::Repel);
		break;
	}
}
