#include "EnemyStateEnemy02MoveBase.h"
#include "../../../../../Enemys/Base/EnemyBase.h"
#include "../../../../../../../WorldContains/EventMessage/EventMessage.h"
#include "../../../../../CommandContains/CommandManagers/Interface/IEnemyCommandManager.h"
#include "../../../../../PlayerWatch/PlayerWatch.h"
#include "../../../EnemyStateName.h"
#include "../../../../../../../Map/MapType.h"

//�R���X�g���N�^
EnemyStateEnemy02MoveBase::EnemyStateEnemy02MoveBase(const EnemyBasePtr & enemy)
	:EnemyStateMoveBase(enemy) {
}

//���b�Z�[�W����
void EnemyStateEnemy02MoveBase::handleMessage(EventMessage message, void * param) {
	switch (message)
	{
		//�v���C���[�ɋ��܂ꂽ�Ƃ�
	case EventMessage::PLAYER_ROUNDS:
		FourDirection toPlayerDir = FourDirection(p_Enemy->GetPlayerWatch()->GetToPlayerChipDis(MapType::Default));
		//�w��Ƀv���C���[������
		if (p_Enemy->GetDirection() == toPlayerDir.GetTurnOver())
			change(EnemyStateName::Caught);

		else
			change(EnemyStateName::Repel);
		break;
	}
}
