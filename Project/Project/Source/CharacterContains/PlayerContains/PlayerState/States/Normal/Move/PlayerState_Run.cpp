#include"PlayerState_Run.h"

//�R���X�g���N�^
PlayerState_Run::PlayerState_Run(GSvector2& position,GSmatrix4& matrix, const PlayerPtr& player, IGameManagerPtr gameManager)
	:PlayerState_MoveBase(position,matrix,player,gameManager){

}
//�e��ԓƎ��̏�����
void PlayerState_Run::onUniqueInit()
{

}
//�X�V����
void PlayerState_Run::onUpdate(float deltaTime)
{
	//�ړ�����
	move(deltaTime, 3.5f);
}