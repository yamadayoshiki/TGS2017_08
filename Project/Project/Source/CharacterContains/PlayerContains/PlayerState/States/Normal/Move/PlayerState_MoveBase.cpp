#include"PlayerState_MoveBase.h"


//�R���X�g���N�^
PlayerState_MoveBase::PlayerState_MoveBase(GSvector2& position, GSmatrix4& matrix, const PlayerPtr& player, IGameManagerPtr gameManager)
	:PlayerState(position, matrix, player, gameManager) {}

//�e��ԓƎ��̏�����
void PlayerState_MoveBase::unique_init()
{
	// �p����̊e��ԓƎ��̏�����
	onUniqueInit();
}
//�X�V����
void PlayerState_MoveBase::update(float deltaTaime)
{
	//�ړ��̓��͏�Ԃɂ���ď�Ԃ�ύX(�ҋ@�A����)
	if (p_Input->IsPadState(GS_XBOX_PAD_A)) {
		change(PlayerStateName::Run);
	}
	else if (p_Input->PadVelocity().length() >= 0.5f) {
		change(PlayerStateName::Walk);
	}
	else if (p_Input->PadVelocity().length() <= 0.0f) {
		change(PlayerStateName::Idle);
	}

	//�p����̍X�V����
	onUpdate(deltaTaime);
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
	if (p_Input->IsPadStateTrigger(GS_XBOX_PAD_B))
		change(PlayerStateName::Open);

	//if (p_Input->IsPadStatesDetach(GS_XBOX_PAD_B)) {
	//	change(PlayerStateName::Swich);
	//}

	//�p����̓��͏���
	onInput();
}