#include"PlayerState_Release.h"

//�R���X�g���N�^
PlayerState_Release::PlayerState_Release(GSvector2& position, GSmatrix4& matrix, const PlayerPtr& player, IGameManagerPtr gameManager)
	:PlayerState(position,matrix,player,gameManager)
{

}
//�e��ԓƎ��̏�����
void PlayerState_Release::unique_init()
{
	change(PlayerStateName::Close);
}
//�X�V����
void PlayerState_Release::update(float deltaTaime)
{

}
//�Փ˔���
void PlayerState_Release::collide(const Actor& other)
{

}