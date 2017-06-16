#include"PlayerState_O_MoveBase.h"
#include"../../../PlayerStateName.h"

//�R���X�g���N�^
PlayerState_O_MoveBase::PlayerState_O_MoveBase(const Player_WPtr& player, IGameManagerPtr gameManager)
	:PlayerState(player,gameManager){}

//�e��ԓƎ��̏�����
void PlayerState_O_MoveBase::unique_init()
{
	TextureName_Change("Player_Open");
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

	//�`���[�W
	m_Parameter.Charge(deltaTaime);

	//�p����̍X�V����
	onUpdate(deltaTaime);
}
//�Փ˔���
void PlayerState_O_MoveBase::collide(const Actor& other)
{
	//�A�[���ɓ������Ă�����Ԃ�
	if (m_Children[ActorName::Player_Arm]->isCollide(other) && is_Scorp_Angle(other)) return;

	//�G�Ƃ̏Փˏ���
	Collide(other);

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
	if (!p_Input->IsPadState(GS_XBOX_PAD_B)) {
		change(PlayerStateName::Swich);
	}
	//�_�b�V��
	if (p_Input->IsPadStateTrigger(GS_XBOX_PAD_A) ||
		gsGetKeyState(GKEY_Z)) {
		change(PlayerStateName::Dash);
	}
	//�p����̓��͏���
	onInput();
}