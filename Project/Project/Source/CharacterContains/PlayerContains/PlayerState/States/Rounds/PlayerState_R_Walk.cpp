#include"PlayerState_R_Walk.h"

//�R���X�g���N�^
PlayerState_R_Walk::PlayerState_R_Walk(GSvector2& position, GSmatrix4& matrix, IGameManagerPtr gameManager)
	:PlayerState_R_MoveBase(position, matrix, gameManager)
{

}
//�e��ԓƎ��̏�����
void PlayerState_R_Walk::onUniqueInit(Actor& actor)
{

}
//�X�V����
void PlayerState_R_Walk::onUpdate(Actor& actor, float deltaTime)
{
	move(actor, deltaTime, 1.0f);
}