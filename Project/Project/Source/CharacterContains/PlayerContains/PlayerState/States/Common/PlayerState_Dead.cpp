#include"PlayerState_Dead.h"

//�R���X�g���N�^
PlayerState_Dead::PlayerState_Dead(GSvector2& position, GSmatrix4& matrix, const PlayerPtr& player, IGameManagerPtr gameManager)
	:PlayerState(position,matrix,player,gameManager)
{

}
//�e��ԓƎ��̏�����
void PlayerState_Dead::unique_init()
{
	
}
//�X�V����
void PlayerState_Dead::update(float deltaTaime)
{

}

//�I������
void PlayerState_Dead::end()
{
	
}