#include"PlayerState_Idol.h"

//�R���X�g���N�^
PlayerState_Idol::PlayerState_Idol(GSvector2& position,GSmatrix4& matrix, const PlayerPtr& player, IGameManagerPtr gameManager)
	:PlayerState_MoveBase(position,matrix,player,gameManager){
}

//�e��ԓƎ��̏�����
void PlayerState_Idol::onUniqueInit()
{

}