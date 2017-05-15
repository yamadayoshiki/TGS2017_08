#include"PlayerState_Open.h"
#include"../../PlayerStateName.h"

//�R���X�g���N�^
PlayerState_Open::PlayerState_Open(const PlayerPtr& player, IGameManagerPtr gameManager)
	:PlayerState(player, gameManager)
{

}

//�e��ԓƎ��̏�����
void PlayerState_Open::unique_init()
{

}

//�X�V����
void PlayerState_Open::update(float deltaTaime)
{
	change(PlayerStateName::O_Idle);
}

//�Փ˔���
void PlayerState_Open::collide(const Actor& other)
{

}

//�I������
void PlayerState_Open::end()
{

}