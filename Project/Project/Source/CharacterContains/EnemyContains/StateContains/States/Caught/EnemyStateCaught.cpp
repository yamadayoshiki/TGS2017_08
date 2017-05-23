#include "EnemyStateCaught.h"
#include "../../../Enemys/Base/EnemyBase.h"
#include "../../../../../WorldContains/IWorld.h"
#include "../../../../PlayerContains/PlayerState/PlayerStateName.h"
#include "../../../../../WorldContains/EventMessage/EventMessage.h"

//�R���X�g���N�^
EnemyStateCaught::EnemyStateCaught(
	const EnemyBasePtr& enemy)
	:EnemyStateBase(enemy) {
}

// �e��ԓƎ��̏�����
void EnemyStateCaught::unique_init() {
	// �v���C���[�̎擾
	ActorPtr player = p_Enemy->getWorld()->findActor(ActorName::Player);
	// �v���C���[�̍��W+�O��
	p_Enemy->setPosition(player->getPosition() + player->getBody()->forward()*20.0f);
}

// �X�V����
void EnemyStateCaught::update(float deltaTime) {
}

// �Փ˔���
void EnemyStateCaught::collide(const Actor & other) {

}

// �I�����̏���
void EnemyStateCaught::end() {
}

// ���b�Z�[�W����
void EnemyStateCaught::handleMessage(EventMessage message, void* param) {
	switch (message)
	{
	case EventMessage::PLAYER_CRUSH:
		change(EnemyStateName::Crush);
		break;

	case EventMessage::PLAYER_RELEASE:
		change(EnemyStateName::Stop);
		break;
	}
}