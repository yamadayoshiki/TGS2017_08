#include"PlayerState_A_MoveBase.h"
#include"../../../PlayerStateName.h"

//�R���X�g���N�^
PlayerState_A_MoveBase::PlayerState_A_MoveBase(GSvector2& pos)
	:PlayerState(pos){}

//�e��ԓƎ��̏�����
void PlayerState_A_MoveBase::unique_init(Actor& actor)
{
	// �p����̊e��ԓƎ��̏�����
	onUniqueInit(actor);
}
//�X�V����
void PlayerState_A_MoveBase::update(Actor& actor, float deltaTaime)
{
	//�ړ��̓��͏�Ԃɂ���ď�Ԃ�ύX(�ҋ@�A����)
	if (mInput->PadVelocity().length() <= 0.0f) {
		change(PlayerStateName::Idol);
	}
	else if (mInput->PadVelocity().length() <= 1.0f) {
		change(PlayerStateName::Walk);
	}

	//�p����̍X�V����
	onUpdate(actor, deltaTaime);
}
//�Փ˔���
void PlayerState_A_MoveBase::collide(const Actor& other)
{
	//�p����̏Փˏ���
	onCollide(other);
}
//�I������
void PlayerState_A_MoveBase::end()
{
	//�p����̏I������
	onEnd();
}
//���͏���
void PlayerState_A_MoveBase::input()
{
	//�_�b�V��
	if (mInput->IsPadState(GS_XBOX_PAD_A) && (mInput->PadVelocity().length() >= 1.0f)) change(PlayerStateName::Run);
	//


	//�p����̓��͏���
	onInput();
}