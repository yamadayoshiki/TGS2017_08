#include"PlayerState_Idle.h"

//�R���X�g���N�^
PlayerState_Idle::PlayerState_Idle(const PlayerPtr& player, IGameManagerPtr gameManager)
	:PlayerState_MoveBase(player,gameManager){
}

//�e��ԓƎ��̏�����
void PlayerState_Idle::onUniqueInit()
{
	TextureName_Change("Player_Close");
}