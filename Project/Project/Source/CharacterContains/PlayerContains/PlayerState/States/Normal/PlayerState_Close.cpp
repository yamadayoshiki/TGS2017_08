#include"PlayerState_Close.h"

//�R���X�g���N�^
PlayerState_Close::PlayerState_Close(GSvector2& position, GSmatrix4& matrix, const PlayerPtr& player, IGameManagerPtr gameManager)
	:PlayerState(position, matrix, player, gameManager)
{

}

//�e��ԓƎ��̏�����
void PlayerState_Close::unique_init()
{

}

//�X�V����
void PlayerState_Close::update(float deltaTaime)
{
	change(PlayerStateName::Idol);
}

//�Փ˔���
void PlayerState_Close::collide(const Actor& other)
{

}

//�I������
void PlayerState_Close::end()
{

}