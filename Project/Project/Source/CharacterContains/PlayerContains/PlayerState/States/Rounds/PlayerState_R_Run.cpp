#include"PlayterState_R_Run.h"

//�R���X�g���N�^
PlayerState_R_Run::PlayerState_R_Run(GSvector2& position, GSmatrix4& matrix, const PlayerPtr& player, IGameManagerPtr gameManager)
	:PlayerState_R_MoveBase(position, matrix,player, gameManager)
{

}
//�e��ԓƎ��̏�����
void PlayerState_R_Run::onUniqueInit()
{

}
//�X�V����
void PlayerState_R_Run::onUpdate(float deltaTime)
{
	move(deltaTime, 3.5);
}