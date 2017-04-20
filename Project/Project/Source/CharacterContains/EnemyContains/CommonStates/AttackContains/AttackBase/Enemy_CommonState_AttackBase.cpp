#include "Enemy_CommonState_AttackBase.h"

// �R���X�g���N�^
Enemy_CommonState_AttackBase::Enemy_CommonState_AttackBase(GSvector2& pos, GSmatrix4& mat)
	:Enemy_BaseState(pos, mat) {
}

// �e��ԓƎ��̏�����
void Enemy_CommonState_AttackBase::unique_init(Actor & actor) {
	// �p����̊e��ԓƎ��̏�����
	onUniqueInit(actor);
}

// �X�V����
void Enemy_CommonState_AttackBase::update(Actor & actor, float deltaTime) {
	//�A�j���[�V�������I�������ꍇIDLE�ɑJ��


	//�p����̍X�V����
	onUpdate(actor, deltaTime);
}

// �Փ˔���
void Enemy_CommonState_AttackBase::collide(const Actor & other) {
	// �p����̏Փ˔���
	onCollide(other);
}

// �I�����̏���
void Enemy_CommonState_AttackBase::end() {
	//�p����̏I������
	onEnd();
}

// ���͏���
void Enemy_CommonState_AttackBase::input() {
	//�p����̓��͏���
	onInput();
}