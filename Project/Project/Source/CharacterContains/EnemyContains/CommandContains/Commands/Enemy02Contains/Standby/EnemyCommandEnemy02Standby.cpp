#include "EnemyCommandEnemy02Standby.h"
#include "../../../../../../WorldContains/EventMessage/EventMessage.h"
#include "../../../../../../WorldContains/IWorld.h"
#include "../../../../Enemys/Base/EnemyBase.h"
#include "../../../../../../Utility/TurnDirection/TurnDirection.h"

//コンストラクタ
EnemyCommandEnemy02Standby::EnemyCommandEnemy02Standby(const EnemyBasePtr & enemy, const FourDirection turnDirection)
	:EnemyCommandBase(enemy)
	, m_TurnDiretion(turnDirection) {
}

//メッセージ処理
void EnemyCommandEnemy02Standby::handleMessage(EventMessage message, void * param) {
	switch (message)
	{
	case EventMessage::ENEMY02_DEAD:
		switch (m_TurnDiretion.name)
		{
			//右に90度回転
		case FourDirectionName::Right:
			p_Enemy->SetDirection(p_Enemy->GetDirection().GetTurn(TurnDirectionName::Clockwise));
			break;
			//左に90度回転
		case FourDirectionName::Left:
			p_Enemy->SetDirection(p_Enemy->GetDirection().GetTurn(TurnDirectionName::AntiClockwise));
			break;
			//180度回転
		case FourDirectionName::Down:
			p_Enemy->SetDirection(p_Enemy->GetDirection().GetTurnOver());
			break;
		}
	}
}
