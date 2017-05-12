#include "EnemyStateMoveBase.h"
#include "../../../../Enemys/Base/EnemyBase.h"

// �R���X�g���N�^
EnemyStateMoveBase::EnemyStateMoveBase(const EnemyBasePtr& enemy)
	:EnemyStateBase(enemy) {
}

// �e��ԓƎ��̏�����
void EnemyStateMoveBase::unique_init() {
	//�p����̊e��ԓƎ��̏�����
	onUniqueInit();
}

// �X�V����
void EnemyStateMoveBase::update(float deltaTime) {
	//�ړ��x�N�g��
	GSvector2 velocity = p_Enemy->GetCommandManager()->GetCommandVector();

	//�ړ��̑��x�ɂ���ď�Ԃ�ύX�i�ҋ@�A�����j
	if (velocity.length() <= 0)
		change(EnemyStateName::Idle);
	else
		change(EnemyStateName::Move);

	//�p����̍X�V����
	onUpdate(deltaTime);
}

// �Փ˔���(������)
void EnemyStateMoveBase::collide(const Actor & other) {
	// �p����̏Փ˔���
	onCollide(other);
}

// �I�����̏���
void EnemyStateMoveBase::end() {
	//�p����̏I������
	onEnd();
}

// ���͏���
void EnemyStateMoveBase::input() {
	// �R�}���h�w���State
	EnemyStateName name = p_Enemy->GetCommandManager()->GetCommandState();
	if (name != EnemyStateName::None)
		change(name);

	// �p����̓��͏���
	onInput();
}