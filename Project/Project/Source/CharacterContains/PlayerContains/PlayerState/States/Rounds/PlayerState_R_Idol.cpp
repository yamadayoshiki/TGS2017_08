#include"PlayerState_R_Idol.h"

//�R���X�g���N�^
PlayerState_R_Idol::PlayerState_R_Idol(GSvector2& position, GSmatrix4& matrix, const PlayerPtr& player, IGameManagerPtr gameManager)
	:PlayerState_R_MoveBase(position, matrix,player, gameManager)
{

}

//�e��ԓƎ��̏�����
void PlayerState_R_Idol::onUniqueInit()
{

}