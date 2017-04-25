#include"PlayerState_O_MoveBase.h"
#include"../../../PlayerStateName.h"

//�R���X�g���N�^
PlayerState_O_MoveBase::PlayerState_O_MoveBase(GSvector2& position,GSmatrix4& matrix, IGameManagerPtr gameManager)
	:PlayerState(position,matrix,gameManager){}

//�e��ԓƎ��̏�����
void PlayerState_O_MoveBase::unique_init(Actor& actor)
{
	//�A�[���̎擾
	getArm(actor);

	// �p����̊e��ԓƎ��̏�����
	onUniqueInit(actor);
}
//�X�V����
void PlayerState_O_MoveBase::update(Actor& actor, float deltaTaime)
{
	//�ړ��̓��͏�Ԃɂ���ď�Ԃ�ύX(�ҋ@�A����)
	if (p_Input->IsPadState(GS_XBOX_PAD_A)) {
		change(PlayerStateName::O_Run);
	}
	else if (p_Input->PadVelocity().length() >= 0.5f) {
		change(PlayerStateName::O_Walk);
	}
	else if (p_Input->PadVelocity().length() <= 0.0f) {
		change(PlayerStateName::O_Idol);
	}

	//�p����̍X�V����
	onUpdate(actor, deltaTaime);
}
//�Փ˔���
void PlayerState_O_MoveBase::collide(const Actor& other)
{
	if (other.getName() == ActorName::Enemy)
	{

	}

	//�p����̏Փˏ���
	onCollide(other);
}
//�I������
void PlayerState_O_MoveBase::end()
{
	//�p����̏I������
	onEnd();
}
//���͏���
void PlayerState_O_MoveBase::input()
{

	//�p����̓��͏���
	onInput();
}