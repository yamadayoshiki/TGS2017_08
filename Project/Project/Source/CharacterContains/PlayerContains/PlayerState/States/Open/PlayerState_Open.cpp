#include"PlayerState_Open.h"
#include"../../PlayerStateName.h"

//�R���X�g���N�^
PlayerState_Open::PlayerState_Open(GSvector2& position, GSmatrix4& matrix, const PlayerPtr& player, IGameManagerPtr gameManager)
	:PlayerState(position, matrix, player, gameManager)
{

}

//�e��ԓƎ��̏�����
void PlayerState_Open::unique_init()
{

}

//�X�V����
void PlayerState_Open::update(float deltaTaime)
{
	change(PlayerStateName::O_Idol);
}

//�Փ˔���
void PlayerState_Open::collide(const Actor& other)
{

}

//�I������
void PlayerState_Open::end()
{

}