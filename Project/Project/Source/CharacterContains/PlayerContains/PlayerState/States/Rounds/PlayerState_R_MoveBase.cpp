#include"PlayerState_R_MoveBase.h"

//�R���X�g���N�^
PlayerState_R_MoveBase::PlayerState_R_MoveBase(GSvector2& position, GSmatrix4& matrix, IGameManagerPtr gameManager)
	:PlayerState(position, matrix, gameManager) {}

//�e��ԓƎ��̏�����
void PlayerState_R_MoveBase::unique_init(Actor& actor)
{
	//�A�[���̎擾
	getArm(actor);

	// �p����̊e��ԓƎ��̏�����
	onUniqueInit(actor);
}
//�X�V����
void PlayerState_R_MoveBase::update(Actor& actor, float deltaTaime)
{
	//�ړ��̓��͏�Ԃɂ���ď�Ԃ�ύX(�ҋ@�A����)
	if (p_Input->IsPadState(GS_XBOX_PAD_A)) {
		change(PlayerStateName::R_Run);
	}
	else if (p_Input->PadVelocity().length() >= 0.5f) {
		change(PlayerStateName::R_Walk);
	}
	else if (p_Input->PadVelocity().length() <= 0.0f) {
		change(PlayerStateName::R_Idol);
	}

	//�p����̍X�V����
	onUpdate(actor, deltaTaime);
}
//�Փ˔���
void PlayerState_R_MoveBase::collide(const Actor& other)
{

	//�p����̏Փˏ���
	onCollide(other);
}
//�I������
void PlayerState_R_MoveBase::end()
{
	//�p����̏I������
	onEnd();
}
//���͏���
void PlayerState_R_MoveBase::input()
{

	//�p����̓��͏���
	onInput();
}