#include"PlayerState_Close.h"

//�R���X�g���N�^
PlayerState_Close::PlayerState_Close(const Player_WPtr& player, IGameManagerPtr gameManager)
	:PlayerState(player, gameManager)
{

}

//�e��ԓƎ��̏�����
void PlayerState_Close::unique_init()
{
	TextureName_Change("Player2");
}

//�X�V����
void PlayerState_Close::update(float deltaTaime)
{
	if (p_Player.lock()->GetLoopCount() < 1)
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