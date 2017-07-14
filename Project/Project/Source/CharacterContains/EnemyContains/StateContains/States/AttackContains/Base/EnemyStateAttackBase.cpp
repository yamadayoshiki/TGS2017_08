#include "EnemyStateAttackBase.h"

// �R���X�g���N�^
EnemyStateAttackBase::EnemyStateAttackBase(
	const EnemyBasePtr& enemy)
	:EnemyStateBase(enemy) {
}

// �e��ԓƎ��̏�����
void EnemyStateAttackBase::unique_init() {
	// �p����̊e��ԓƎ��̏�����
	onUniqueInit();
}

// �X�V����
void EnemyStateAttackBase::update(float deltaTime) {
	//�A�j���[�V�������I�������ꍇIDLE�ɑJ��


	//�p����̍X�V����
	onUpdate(deltaTime);
}

// �Փ˔���
void EnemyStateAttackBase::collide(const Actor & other, const Body::ContactSet& contactSet) {
	// �p����̏Փ˔���
	onCollide(other, contactSet);
}

// �I�����̏���
void EnemyStateAttackBase::end() {
	//�p����̏I������
	onEnd();
}

// ���͏���
void EnemyStateAttackBase::input() {
	//�p����̓��͏���
	onInput();
}