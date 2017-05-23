#include"PlayerState_MoveBase.h"


//�R���X�g���N�^
PlayerState_MoveBase::PlayerState_MoveBase(const PlayerPtr& player, IGameManagerPtr gameManager)
	:PlayerState(player, gameManager) {
	//�t���[�����̏�����
	m_FramConter = 120;

}

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
	if (p_Input->PadVelocity().length() >= 0.5f) {
		change(PlayerStateName::Walk);
	}
	else if (p_Input->PadVelocity().length() <= 0.0f) {
		change(PlayerStateName::Idle);
	}
	//�p����̍X�V����
	onUpdate(deltaTaime);

	//�t���[���̉��Z
	m_FramConter += deltaTaime;
}
//�Փ˔���
void PlayerState_MoveBase::collide(const Actor& other)
{
	if (m_FramConter <= 20) return;
	if (other.getName() == ActorName::Enemy_01 || other.getName() == ActorName::Enemy_03)
	{
		change(PlayerStateName::Damage);
		m_FramConter = 0;
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
	//�_�b�V��
	if (p_Input->IsPadStateTrigger(GS_XBOX_PAD_A ) ||
		gsGetKeyState(GKEY_Z)) {
		change(PlayerStateName::Dash);
	}

	//�p����̓��͏���
	onInput();
}