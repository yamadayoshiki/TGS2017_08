#include"PlayerState_Idol.h"

//�R���X�g���N�^
PlayerState_Idol::PlayerState_Idol(GSvector2& position,GSmatrix4& matrix, IGameManager* gameManager)
	:PlayerState_MoveBase(position,matrix,gameManager){
}

//�e��ԓƎ��̏�����
void PlayerState_Idol::onUniqueInit(Actor& actor)
{

}