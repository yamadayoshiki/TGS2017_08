#include"PlayterState_R_Run.h"

//�R���X�g���N�^
PlayerState_R_Run::PlayerState_R_Run(GSvector2& position, GSmatrix4& matrix, IGameManagerPtr gameManager)
	:PlayerState_R_MoveBase(position, matrix, gameManager)
{

}
//�e��ԓƎ��̏�����
void PlayerState_R_Run::onUniqueInit(Actor& actor)
{

}
//�X�V����
void PlayerState_R_Run::onUpdate(Actor& actor, float deltaTime)
{
	move(actor, deltaTime, 3.5);
}