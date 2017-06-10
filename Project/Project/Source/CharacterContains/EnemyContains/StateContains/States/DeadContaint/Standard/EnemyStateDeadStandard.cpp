#include "EnemyStateDeadStandard.h"
#include "../../../../Entity/Enemys/Base/EnemyBase.h"
#include "../../../../../../WorldContains/IWorld.h"
#include "../../../../../../WorldContains/EventMessage/EventMessage.h"

//�R���X�g���N�^
EnemyStateDeadStandard::EnemyStateDeadStandard(
	const EnemyBasePtr& enemy)
	:EnemyStateBase(enemy) {

}
// �e��ԓƎ��̏�����
void EnemyStateDeadStandard::unique_init() {
	p_Enemy.lock()->getWorld()->sendMessage(EventMessage::PLAYER_ROUNDSLOST);

	//�A�j���[�V�����̕ύX

}

// �X�V����
void EnemyStateDeadStandard::update(float deltaTime) {
	//�A�j���[�V�������I��������Actor����폜
	p_Enemy.lock()->dead();
}

// �Փ˔���
void EnemyStateDeadStandard::collide(const Actor & other) {

}

// �I�����̏���
void EnemyStateDeadStandard::end() {

}