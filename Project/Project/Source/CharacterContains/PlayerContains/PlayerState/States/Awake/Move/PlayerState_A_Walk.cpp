#include"PlayerState_A_Walk.h"

//�R���X�g���N�^
PlayerState_A_Walk::PlayerState_A_Walk(GSvector2& position, GSmatrix4& matrix, IGameManager* gameManager)
	:PlayerState_A_MoveBase(position,matrix,gameManager)
{

}
//�e��ԓƎ��̏�����
void PlayerState_A_Walk::onUniqueInit(Actor& actor)
{

}
//�X�V����
void PlayerState_A_Walk::onUpdate(Actor& actor, float deltaTime)
{
	move(actor, deltaTime, 1.0f);
}