#include "EnemyStateMoveBaseOnlyInTheBack.h"
#include "../../../../../../../Utility/FourDirection/FourDirection.h"
#include "../../../../../Entity/Enemys/Base/EnemyBase.h"
#include "../../../../../../../WorldContains/EventMessage/EventMessage.h"
#include "../../../../../CommandContains/CommandManagers/Interface/IEnemyCommandManager.h"
#include "../../../../../PlayerWatch/PlayerWatch.h"
#include "../../../EnemyStateName.h"
#include "../../../../../../../Map/MapType.h"
#include "../../../../../../../ActorContains/Transform/Transform.h"

//�R���X�g���N�^
EnemyStateMoveBaseOnlyInTheBack::EnemyStateMoveBaseOnlyInTheBack(const EnemyBasePtr & enemy)
	: EnemyStateBase(enemy)
	, EnemyStateMoveBaseStandard(enemy) {
}

//���b�Z�[�W����
void EnemyStateMoveBaseOnlyInTheBack::OnHandleMessage(EventMessage message, void * param) {
	switch (message)
	{
		//�v���C���[�ɋ��܂ꂽ�Ƃ�
	case EventMessage::PLAYER_ROUNDS:
		FourDirection toPlayerDir 
			= FourDirection(p_Enemy.lock()->GetPlayerWatch()->GetToPlayerDis());
		//�w��Ƀv���C���[������
		if (FourDirection(p_Enemy.lock()->getTransform()->m_Angle) == toPlayerDir.GetTurnOver())
			change(EnemyStateName::Caught);

		else
			change(EnemyStateName::Repel);
		break;
	}
}