#include"PlayerState_Idle.h"

//�R���X�g���N�^
PlayerState_Idle::PlayerState_Idle(GSvector2& position,GSmatrix4& matrix, const PlayerPtr& player, IGameManagerPtr gameManager)
	:PlayerState_MoveBase(position,matrix,player,gameManager){
}

//�e��ԓƎ��̏�����
void PlayerState_Idle::onUniqueInit()
{

}