#include "Enemy_CommonState_MoveBase.h"

// �R���X�g���N�^
Enemy_CommonState_MoveBase::Enemy_CommonState_MoveBase(GSvector2& pos, GSmatrix4& mat)
	:Enemy_BaseState(pos, mat)
{
}

// �e��ԓƎ��̏�����
void Enemy_CommonState_MoveBase::unique_init(Actor & actor)
{
	//�p����̊e��ԓƎ��̏�����
	onUniqueInit(actor);
}

// �X�V����
void Enemy_CommonState_MoveBase::update(Actor & actor, float deltaTime)
{
	//�ړ��̑��x�ɂ���ď�Ԃ�ύX�i�ҋ@�A�����A����j

	//�p����̍X�V����
	onUpdate(actor, deltaTime);
}

// �Փ˔���(������)
void Enemy_CommonState_MoveBase::collide(const Actor & other)
{
	/* �U�����ɑ΂��郊�A�N�V���� */
	if (other.getName() == ActorName::None) {
		change(EnemyStateName::None);
	}

	// �p����̏Փ˔���
	onCollide(other);
}

// �I�����̏���
void Enemy_CommonState_MoveBase::end()
{
	//�p����̏I������
	onEnd();
}