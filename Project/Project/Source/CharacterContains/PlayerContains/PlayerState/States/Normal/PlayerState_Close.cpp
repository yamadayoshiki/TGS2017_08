#include"PlayerState_Close.h"

//�R���X�g���N�^
PlayerState_Close::PlayerState_Close(const PlayerPtr& player, IGameManagerPtr gameManager)
	:PlayerState(player, gameManager)
{

}

//�e��ԓƎ��̏�����
void PlayerState_Close::unique_init()
{

}

//�X�V����
void PlayerState_Close::update(float deltaTaime)
{
	change(PlayerStateName::Idle);
}

//�Փ˔���
void PlayerState_Close::collide(const Actor& other)
{

}

//�I������
void PlayerState_Close::end()
{

}