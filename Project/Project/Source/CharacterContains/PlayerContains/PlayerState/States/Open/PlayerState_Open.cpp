#include"PlayerState_Open.h"
#include"../../PlayerStateName.h"

//�R���X�g���N�^
PlayerState_Open::PlayerState_Open(const Player_WPtr& player, IGameManagerPtr gameManager)
	:PlayerState(player, gameManager)
{

}

//�e��ԓƎ��̏�����
void PlayerState_Open::unique_init()
{
	TextureName_Change("Player1");
}

//�X�V����
void PlayerState_Open::update(float deltaTaime)
{
	if (p_Player.lock()->GetLoopCount() > 0)
		change(PlayerStateName::O_Walk);
	move(deltaTaime);
}

//�Փ˔���
void PlayerState_Open::collide(const Actor& other)
{
	Collide(other);
}

//�I������
void PlayerState_Open::end()
{

}