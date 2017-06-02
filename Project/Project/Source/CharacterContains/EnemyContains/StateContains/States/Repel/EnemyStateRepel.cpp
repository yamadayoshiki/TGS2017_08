#include "EnemyStateRepel.h"
#include "../../../Enemys/Base/EnemyBase.h"
#include "../../../../../WorldContains/IWorld.h"
#include "../../../../../WorldContains/EventMessage/EventMessage.h"

//�R���X�g���N�^
EnemyStateRepel::EnemyStateRepel(const EnemyBasePtr& enemy)
	:EnemyStateBase(enemy) {
}
// �e��ԓƎ��̏�����
void EnemyStateRepel::unique_init() {
	//�e��
	p_Enemy.lock()->getWorld()->sendMessage(EventMessage::ENEMY_REPEL);
}

// �X�V����
void EnemyStateRepel::update(float deltaTime) {
	change(EnemyStateName::Idle);
}

// �Փ˔���
void EnemyStateRepel::collide(const Actor & other) {
}

// �I�����̏���
void EnemyStateRepel::end() {
}