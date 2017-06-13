#include"PlayerState_Invincible.h"

//�R���X�g���N�^
PlayerState_Invincible::PlayerState_Invincible(const Player_WPtr& player, IGameManagerPtr gameManager)
	:PlayerState(player,gameManager)
{

}
//�e��ԓƎ��̏�����
void PlayerState_Invincible::unique_init()
{
	TextureName_Change("Player_Invincble");
	gsPlaySE(SE_PLAYER_RESPAWN);
	m_FramConter = 0.0f;
}
//�X�V����
void PlayerState_Invincible::update(float deltaTaime)
{
	if (m_FramConter >= 30) {
		change(PlayerStateName::Walk);
	}
	move(deltaTaime, 8.0f);
	m_FramConter += deltaTaime;
}
//�Փ˔���
void PlayerState_Invincible::collide(const Actor& other)
{

}

//���͏���
void PlayerState_Invincible::input()
{
	//�A�[�����J��
	if (p_Input->IsPadStateTrigger(GS_XBOX_PAD_B))
		change(PlayerStateName::Open);
	//�_�b�V��
	if (p_Input->IsPadStateTrigger(GS_XBOX_PAD_A) ||
		gsGetKeyState(GKEY_Z)) {
		change(PlayerStateName::Dash);
	}
}