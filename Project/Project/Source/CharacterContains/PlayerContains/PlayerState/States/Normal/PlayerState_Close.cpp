#include"PlayerState_Close.h"

//�R���X�g���N�^
PlayerState_Close::PlayerState_Close(const PlayerPtr& player, IGameManagerPtr gameManager)
	:PlayerState(player, gameManager)
{

}

//�e��ԓƎ��̏�����
void PlayerState_Close::unique_init()
{
	TextureName_Change("Player_Close");

	m_FramConter = 0;
}

//�X�V����
void PlayerState_Close::update(float deltaTaime)
{
	if (m_FramConter > 10)
		change(PlayerStateName::Walk);
	m_FramConter += deltaTaime;
}

//�Փ˔���
void PlayerState_Close::collide(const Actor& other)
{

}

//�I������
void PlayerState_Close::end()
{

}