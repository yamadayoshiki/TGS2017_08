#include"PlayerState_A_MoveBase.h"
#include"../../../PlayerStateName.h"

//�R���X�g���N�^
PlayerState_A_MoveBase::PlayerState_A_MoveBase(GSvector2& position,GSmatrix4& matrix,IGameManager* gameManager)
	:PlayerState(position,matrix,gameManager){}

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
	if (p_Input->IsPadState(GS_XBOX_PAD_A)) {
		change(PlayerStateName::Run);
	}
	else if (p_Input->PadVelocity().length() <= 1.0f) {
		change(PlayerStateName::Walk);
	}
	else if (p_Input->PadVelocity().length() <= 0.0f) {
		change(PlayerStateName::Idol);
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
	if (p_Input->IsPadState(GS_XBOX_PAD_A) && (p_Input->PadVelocity().length() >= 1.0f)) change(PlayerStateName::Run);
	//


	//�p����̓��͏���
	onInput();
}