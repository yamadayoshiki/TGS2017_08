#include "EnemyStateMoveBaseRepel.h"
#include "../../../../../../../WorldContains/EventMessage/EventMessage.h"

//�R���X�g���N�^
EnemyStateMoveBaseRepel::EnemyStateMoveBaseRepel(const EnemyBasePtr& enemy)
	: EnemyStateBase(enemy)
	, EnemyStateMoveBaseStandard(enemy) {
}

//���b�Z�[�W����
void EnemyStateMoveBaseRepel::OnHandleMessage(EventMessage message, void * param) {
	switch (message)
	{
	case EventMessage::PLAYER_ROUNDS:
		change(EnemyStateName::Repel);
		break;
	}
}