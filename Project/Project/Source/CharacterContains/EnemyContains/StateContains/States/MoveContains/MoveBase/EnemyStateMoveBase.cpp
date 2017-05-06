#include "EnemyStateMoveBase.h"

// �R���X�g���N�^
EnemyStateMoveBase::EnemyStateMoveBase(const EnemyBasePtr& enemy)
	:EnemyStateBase(enemy)
{
}

// �e��ԓƎ��̏�����
void EnemyStateMoveBase::unique_init()
{
	//�p����̊e��ԓƎ��̏�����
	onUniqueInit();
}

// �X�V����
void EnemyStateMoveBase::update(float deltaTime)
{
	//�ړ��̑��x�ɂ���ď�Ԃ�ύX�i�ҋ@�A�����A����j


	//�p����̍X�V����
	onUpdate(deltaTime);
}

// �Փ˔���(������)
void EnemyStateMoveBase::collide(const Actor & other)
{
	/* �U�����ɑ΂��郊�A�N�V���� */
	if (other.getName() == ActorName::None) {
		change(EnemyStateName::None);
	}

	// �p����̏Փ˔���
	onCollide(other);
}

// �I�����̏���
void EnemyStateMoveBase::end()
{
	//�p����̏I������
	onEnd();
}

// ���͏���
void EnemyStateMoveBase::input() {
	//���߂ɉ������s��

	// �p����̓��͏���
	onInput();
}