#include "EnemyStateDead.h"
#include "../../../Entity/Enemys/Base/EnemyBase.h"
#include "../../../../../WorldContains/IWorld.h"
#include "../../../../../WorldContains/EventMessage/EventMessage.h"

//�R���X�g���N�^
EnemyStateDead::EnemyStateDead(
	const EnemyBasePtr& enemy)
	:EnemyStateBase(enemy) {

}
// �e��ԓƎ��̏�����
void EnemyStateDead::unique_init() {
	p_Enemy.lock()->getWorld()->sendMessage(EventMessage::PLAYER_ROUNDSLOST);

	//�A�j���[�V�����̕ύX

}

// �X�V����
void EnemyStateDead::update(float deltaTime) {
	//�A�j���[�V�������I��������Actor����폜
	p_Enemy.lock()->dead();
}

// �Փ˔���
void EnemyStateDead::collide(const Actor & other) {

}

// �I�����̏���
void EnemyStateDead::end() {

}