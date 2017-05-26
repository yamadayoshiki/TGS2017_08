#include "EnemyCommandEnemy02Standby.h"
#include "../../../../../../WorldContains/EventMessage/EventMessage.h"
#include "../../../../../../WorldContains/IWorld.h"
#include "../../../../Enemys/Base/EnemyBase.h"
#include "../../../../../../Utility/TurnDirection/TurnDirection.h"

//�R���X�g���N�^
EnemyCommandEnemy02Standby::EnemyCommandEnemy02Standby(const EnemyBasePtr & enemy, const FourDirection turnDirection)
	:EnemyCommandBase(enemy)
	, m_TurnDiretion(turnDirection) {
}

//���b�Z�[�W����
void EnemyCommandEnemy02Standby::handleMessage(EventMessage message, void * param) {
	switch (message)
	{
	case EventMessage::ENEMY02_DEAD:
		switch (m_TurnDiretion.name)
		{
			//�E��90�x��]
		case FourDirectionName::Right:
			p_Enemy->SetDirection(p_Enemy->GetDirection().GetTurn(TurnDirectionName::Clockwise));
			break;
			//����90�x��]
		case FourDirectionName::Left:
			p_Enemy->SetDirection(p_Enemy->GetDirection().GetTurn(TurnDirectionName::AntiClockwise));
			break;
			//180�x��]
		case FourDirectionName::Down:
			p_Enemy->SetDirection(p_Enemy->GetDirection().GetTurnOver());
			break;
		}
	}
}
