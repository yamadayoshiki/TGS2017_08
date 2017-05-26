#include "EnemyStateMoveRepelBase.h"
#include "../../../../../../WorldContains/EventMessage/EventMessage.h"

//�R���X�g���N�^
EnemyStateMoveRepelBase::EnemyStateMoveRepelBase(const EnemyBasePtr& enemy)
	:EnemyStateMoveBase(enemy) {
}

//���b�Z�[�W����
void EnemyStateMoveRepelBase::handleMessage(EventMessage message, void * param) {
	switch (message)
	{
	case EventMessage::PLAYER_ROUNDS:
		change(EnemyStateName::Repel);
		break;
	}
}