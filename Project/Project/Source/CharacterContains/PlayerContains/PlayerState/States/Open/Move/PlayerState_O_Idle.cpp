#include"PlayerState_O_Idle.h"

//�R���X�g���N�^
PlayerState_O_Idle::PlayerState_O_Idle(const PlayerPtr& player, IGameManagerPtr gameManager)
	:PlayerState_O_MoveBase(player,gameManager)
{

}

//�e��ԓƎ��̏�����
void PlayerState_O_Idle::onUniqueInit()
{

}