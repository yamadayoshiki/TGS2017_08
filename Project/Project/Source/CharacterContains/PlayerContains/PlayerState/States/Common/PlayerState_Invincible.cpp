#include"PlayerState_Invincible.h"

//�R���X�g���N�^
PlayerState_Invincible::PlayerState_Invincible(const PlayerPtr& player, IGameManagerPtr gameManager)
	:PlayerState(player,gameManager)
{

}
//�e��ԓƎ��̏�����
void PlayerState_Invincible::unique_init()
{
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