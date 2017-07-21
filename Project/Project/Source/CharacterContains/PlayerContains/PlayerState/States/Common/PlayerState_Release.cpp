#include"PlayerState_Release.h"

//�R���X�g���N�^
PlayerState_Release::PlayerState_Release(const Player_WPtr& player, IGameManagerPtr gameManager)
	:PlayerState(player,gameManager)
{

}
//�e��ԓƎ��̏�����
void PlayerState_Release::unique_init()
{
	TextureName_Change("Player_Open");
	p_GameManager->GetPlayerParameter().m_ClipFlag = false;
	m_FramConter = 0.0f;
}
//�X�V����
void PlayerState_Release::update(float deltaTaime)
{
	if (m_FramConter > 10)
	{
		change(PlayerStateName::O_Walk);
	}

	move(deltaTaime);
	m_FramConter += deltaTaime;
}