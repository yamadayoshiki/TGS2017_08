#include"PlayerState_Close.h"

//�R���X�g���N�^
PlayerState_Close::PlayerState_Close(GSvector2& position, GSmatrix4& matrix, IGameManagerPtr gameManager)
	:PlayerState(position, matrix, gameManager)
{

}

//�e��ԓƎ��̏�����
void PlayerState_Close::unique_init(Actor& actor)
{

}

//�X�V����
void PlayerState_Close::update(Actor& actor, float deltaTaime)
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