#include"PlayerState_MoveBase.h"


//�R���X�g���N�^
PlayerState_MoveBase::PlayerState_MoveBase(GSvector2& position,GSmatrix4& matrix, IGameManager* gameManager)
	:PlayerState(position,matrix,gameManager) {}

//�e��ԓƎ��̏�����
void PlayerState_MoveBase::unique_init(Actor& actor)
{
	// �p����̊e��ԓƎ��̏�����
	onUniqueInit(actor);
}
//�X�V����
void PlayerState_MoveBase::update(Actor& actor, float deltaTaime)
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
void PlayerState_MoveBase::collide(const Actor& other)
{
	if (other.getName() == ActorName::Enemy)
	{
		
	}
	//�p����̏Փˏ���
	onCollide(other);
}
//�I������
void PlayerState_MoveBase::end()
{
	//�p����̏I������
	onEnd();
}
//���͏���
void PlayerState_MoveBase::input()
{
	//�A�[�����J��
	if (p_Input->IsPadTrigger(GS_XBOX_PAD_B)) change(PlayerStateName::Open);

	//�p����̓��͏���
	onInput();
}