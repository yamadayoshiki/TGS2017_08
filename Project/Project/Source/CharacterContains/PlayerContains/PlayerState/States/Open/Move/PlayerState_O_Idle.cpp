#include"PlayerState_O_Idle.h"

//�R���X�g���N�^
PlayerState_O_Idle::PlayerState_O_Idle(GSvector2& position, GSmatrix4& matrix, const PlayerPtr& player, IGameManagerPtr gameManager)
	:PlayerState_O_MoveBase(position,matrix,player,gameManager)
{

}

//�e��ԓƎ��̏�����
void PlayerState_O_Idle::onUniqueInit()
{

}