#include"PlayerState_O_MoveBase.h"
#include"../../../PlayerStateName.h"

//�R���X�g���N�^
PlayerState_O_MoveBase::PlayerState_O_MoveBase(const PlayerPtr& player, IGameManagerPtr gameManager)
	:PlayerState(player,gameManager){}

//�e��ԓƎ��̏�����
void PlayerState_O_MoveBase::unique_init()
{
	// �p����̊e��ԓƎ��̏�����
	onUniqueInit();
}
//�X�V����
void PlayerState_O_MoveBase::update(float deltaTaime)
{
	if (p_Input->PadVelocity().length() >= 0.5f) {
		change(PlayerStateName::O_Walk);
	}
	else if (p_Input->PadVelocity().length() <= 0.0f) {
		change(PlayerStateName::O_Idle);
	}

	//�p����̍X�V����
	onUpdate(deltaTaime);
}
//�Փ˔���
void PlayerState_O_MoveBase::collide(const Actor& other)
{
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
	if (p_Input->IsPadStatesDetach(GS_XBOX_PAD_B)) {
		change(PlayerStateName::Swich);
	}
	//�p����̓��͏���
	onInput();
}