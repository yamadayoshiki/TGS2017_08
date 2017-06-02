#include "EnemyStateCrush.h"
#include "../../../Enemys/Base/EnemyBase.h"
#include "../../../../../WorldContains/IWorld.h"
#include "../../../../../WorldContains/EventMessage/EventMessage.h"


//�R���X�g���N�^
EnemyStateCrush::EnemyStateCrush(
	const EnemyBasePtr& enemy)
	:EnemyStateBase(enemy) {
}

// �e��ԓƎ��̏�����
void EnemyStateCrush::unique_init() {
	//���[�V�����̕ύX

	//�_���[�W���󂯂�
	p_Enemy.lock()->GetHitPoint().Decrease(1);
}

// �X�V����
void EnemyStateCrush::update(float deltaTime) {
	if (p_Enemy.lock()->GetHitPoint().IsDead() == true)
		change(EnemyStateName::Dead);

	else
		change(EnemyStateName::Caught);
}

// �Փ˔���
void EnemyStateCrush::collide(const Actor & other) {
}

// �I�����̏���
void EnemyStateCrush::end() {
}

