#include"PlayerState_Release.h"

//�R���X�g���N�^
PlayerState_Release::PlayerState_Release(const PlayerPtr& player, IGameManagerPtr gameManager)
	:PlayerState(player,gameManager)
{

}
//�e��ԓƎ��̏�����
void PlayerState_Release::unique_init()
{
	change(PlayerStateName::Close);
}
//�X�V����
void PlayerState_Release::update(float deltaTaime)
{

}
//�Փ˔���
void PlayerState_Release::collide(const Actor& other)
{

}