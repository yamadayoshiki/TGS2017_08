#include "EnemyStateCaughtStandard.h"
#include "../../../../Entity/Enemys/Base/EnemyBase.h"
#include "../../../../../../WorldContains/IWorld.h"
#include "../../../../../PlayerContains/PlayerState/PlayerStateName.h"
#include "../../../../../../WorldContains/EventMessage/EventMessage.h"
#include "../../../../../../ActorContains/Transform/Transform.h"

//�R���X�g���N�^
EnemyStateCaughtStandard::EnemyStateCaughtStandard(
	const EnemyBasePtr& enemy)
	:EnemyStateBase(enemy) {
}

// �e��ԓƎ��̏�����
void EnemyStateCaughtStandard::unique_init() {
	// �v���C���[�̎擾
	ActorPtr player = p_Enemy.lock()->getWorld()->findActor(ActorName::Player);
	// �v���C���[�̍��W+�O��
	p_Enemy.lock()->setPosition(player->getPosition() + player->getTransform()->GetForward()*20.0f);
}

// �X�V����
void EnemyStateCaughtStandard::update(float deltaTime) {
}

// �I�����̏���
void EnemyStateCaughtStandard::end() {
}

// ���b�Z�[�W����
void EnemyStateCaughtStandard::handleMessage(EventMessage message, void* param) {
	switch (message)
	{
	case EventMessage::PLAYER_CRUSH:
		change(EnemyStateName::Crush);
		p_Enemy.lock()->GetHitPoint().Decrease(1 + (int)param);
		break;

	case EventMessage::PLAYER_RELEASE:
		change(EnemyStateName::Stop);
		break;
	}
}