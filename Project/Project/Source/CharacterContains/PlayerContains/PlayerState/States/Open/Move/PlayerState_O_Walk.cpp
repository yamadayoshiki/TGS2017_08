#include"PlayerState_O_Walk.h"

//�R���X�g���N�^
PlayerState_O_Walk::PlayerState_O_Walk(GSvector2& position, GSmatrix4& matrix, const PlayerPtr& player, IGameManagerPtr gameManager)
	:PlayerState_O_MoveBase(position,matrix,player,gameManager)
{

}
//�e��ԓƎ��̏�����
void PlayerState_O_Walk::onUniqueInit()
{

}
//�X�V����
void PlayerState_O_Walk::onUpdate(float deltaTime)
{
	move(deltaTime, 1.0f);
}