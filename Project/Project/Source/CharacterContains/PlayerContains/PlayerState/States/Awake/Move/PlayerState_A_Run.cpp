#include"PlayerState_A_Run.h"

//�R���X�g���N�^
PlayerState_A_Run::PlayerState_A_Run(GSvector2& position, GSmatrix4& matrix, IGameManager* gameManager)
	:PlayerState_A_MoveBase(position,matrix,gameManager)
{

}
//�e��ԓƎ��̏�����
void PlayerState_A_Run::onUniqueInit(Actor& actor)
{

}
//�X�V����
void PlayerState_A_Run::onUpdate(Actor& actor, float deltaTime)
{
	move(actor, deltaTime, 1.5);
}