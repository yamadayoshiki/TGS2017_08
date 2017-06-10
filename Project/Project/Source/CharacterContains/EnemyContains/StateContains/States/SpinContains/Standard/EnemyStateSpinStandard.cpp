#include "EnemyStateSpinStandard.h"
#include "../../../../Entity/Enemys/Base/EnemyBase.h"
#include "../../../../CommandContains/CommandManagers/Interface/IEnemyCommandManager.h"
#include "../../../../PlayerWatch/PlayerWatch.h"
#include "../../../../../../WorldContains/EventMessage/EventMessage.h"

//�R���X�g���N�^
EnemyStateSpinStandard::EnemyStateSpinStandard(const EnemyBasePtr & enemy, float speed)
	: EnemyStateBase(enemy)
	, m_Speed(speed) {
}

//�e��ŗL�̏�����
void EnemyStateSpinStandard::unique_init() {
	//�A�j���[�V�����ύX


	//�v���C���[�ɔ�΂��������Ɍ����𒼂�
	p_Enemy.lock()->SetDirection(p_Enemy.lock()->GetPlayerWatch()->GetPlayerFrontDir());

	//�X�s����ԂɑJ�ڂ������Ƃ�m�点��
	p_Enemy.lock()->GetCommandManager()->handleMessage(EventMessage::ENEMY_SPIN, nullptr);
}

//�e��ŗL�̍X�V
void EnemyStateSpinStandard::update(float deltaTime) {
	ForwardMove(deltaTime, m_Speed);
}

//���b�Z�[�W����
void EnemyStateSpinStandard::handleMessage(EventMessage message, void * param){
	switch (message)
	{
	case EventMessage::ENEMY_COMMAND_DEAD:
		change(EnemyStateName::Dead);
	default:
		break;
	}
}

