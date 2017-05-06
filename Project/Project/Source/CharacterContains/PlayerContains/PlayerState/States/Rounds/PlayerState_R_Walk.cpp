#include"PlayerState_R_Walk.h"

//�R���X�g���N�^
PlayerState_R_Walk::PlayerState_R_Walk(GSvector2& position, GSmatrix4& matrix, const PlayerPtr& player, IGameManagerPtr gameManager)
	:PlayerState_R_MoveBase(position, matrix,player, gameManager)
{

}
//�e��ԓƎ��̏�����
void PlayerState_R_Walk::onUniqueInit()
{

}
//�X�V����
void PlayerState_R_Walk::onUpdate(float deltaTime)
{
	move(deltaTime, 1.0f);
}