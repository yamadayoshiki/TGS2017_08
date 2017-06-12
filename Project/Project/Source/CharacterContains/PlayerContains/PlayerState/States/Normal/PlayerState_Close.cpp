#include"PlayerState_Close.h"

//�R���X�g���N�^
PlayerState_Close::PlayerState_Close(const Player_WPtr& player, IGameManagerPtr gameManager)
	:PlayerState(player, gameManager)
{

}

//�e��ԓƎ��̏�����
void PlayerState_Close::unique_init()
{
	m_Parameter.m_ChargeConter = 0.0f;
	TextureName_Change("Player_Close");
	gsPlaySE(SE_PLAYER_ARM);
}

//�X�V����
void PlayerState_Close::update(float deltaTaime)
{
	if (p_Player.lock()->GetLoopCount() > 0)
		change(PlayerStateName::Walk);
	move(deltaTaime);
}

//�Փ˔���
void PlayerState_Close::collide(const Actor& other)
{
	Collide(other);
}

//�I������
void PlayerState_Close::end()
{

}