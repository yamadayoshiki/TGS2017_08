#include"PlayerState_O_Run.h"

//�R���X�g���N�^
PlayerState_O_Run::PlayerState_O_Run(GSvector2& position, GSmatrix4& matrix, IGameManagerPtr gameManager)
	:PlayerState_O_MoveBase(position,matrix,gameManager)
{

}
//�e��ԓƎ��̏�����
void PlayerState_O_Run::onUniqueInit(Actor& actor)
{

}
//�X�V����
void PlayerState_O_Run::onUpdate(Actor& actor, float deltaTime)
{
	move(actor, deltaTime, 1.5);
}