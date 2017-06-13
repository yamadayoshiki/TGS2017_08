#include "EnemyStateRush.h"
#include "../../../../Entity/Enemys/Base/EnemyBase.h"
#include "../../../../../../WorldContains/EventMessage/EventMessage.h"

EnemyStateRush::EnemyStateRush(const EnemyBasePtr & enemy, const float speed)
	: EnemyStateBase(enemy)
	, m_Speed(speed) {
}

void EnemyStateRush::update(float deltaTime) {
	//��������ړ�
	RegardMove(p_Enemy.lock()->GetDirection(), deltaTime, m_Speed);
}

void EnemyStateRush::OnHandleMessage(EventMessage message, void * param) {
	switch (message)
	{
		//�v���C���[�ɋ��܂ꂽ�Ƃ�
	case EventMessage::PLAYER_ROUNDS:
		change(EnemyStateName::Repel);
		break;

		//�ǂɎh�����ďI��
	case EventMessage::ENEMY_STATEEND:
		change(EnemyStateName::StickWall);
		break;
	}
}