#include"PlayerState_MoveBase.h"

//�R���X�g���N�^
PlayerState_MoveBase::PlayerState_MoveBase(GSvector2& pos)
	:PlayerState(pos) {}

//�e��ԓƎ��̏�����
void PlayerState_MoveBase::unique_init(Actor& actor)
{
	// �p����̊e��ԓƎ��̏�����
	onUniqueInit(actor);
}
//�X�V����
void PlayerState_MoveBase::update(Actor& actor, float deltaTaime)
{

}
//�Փ˔���
void PlayerState_MoveBase::collide(const Actor& other)
{

}
//�I������
void PlayerState_MoveBase::end()
{

}
//���͏���
void PlayerState_MoveBase::input()
{

}