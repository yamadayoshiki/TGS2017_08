#include"PlayerState_O_Walk.h"

//�R���X�g���N�^
PlayerState_O_Walk::PlayerState_O_Walk(GSvector2& position, GSmatrix4& matrix, IGameManagerPtr gameManager)
	:PlayerState_O_MoveBase(position,matrix,gameManager)
{

}
//�e��ԓƎ��̏�����
void PlayerState_O_Walk::onUniqueInit(Actor& actor)
{

}
//�X�V����
void PlayerState_O_Walk::onUpdate(Actor& actor, float deltaTime)
{
	move(actor, deltaTime, 1.0f);
}