#include "EnemyStateRush.h"
#include "../../../../Entity/Enemys/Base/EnemyBase.h"
#include "../../../../../../WorldContains/EventMessage/EventMessage.h"
#include "../../../../Entity/Enemys/Base/EnemyBase.h"

EnemyStateRush::EnemyStateRush(const EnemyBasePtr & enemy, const float speed)
	: EnemyStateBase(enemy)
	, m_Speed(speed) {
}

void EnemyStateRush::unique_init() {
	//�e�N�X�`���ؑ�
	p_Enemy.lock()->Settexture("Rush");
}

void EnemyStateRush::update(float deltaTime) {
	//��������ړ�
	RegardMove(p_Enemy.lock()->GetDirection(), deltaTime, m_Speed);
}

void EnemyStateRush::end() {
	//�e�N�X�`���ؑ�
	p_Enemy.lock()->Settexture("Normal");
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