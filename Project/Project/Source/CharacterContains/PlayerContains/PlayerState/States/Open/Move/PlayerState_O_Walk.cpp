#include"PlayerState_O_Walk.h"

//�R���X�g���N�^
PlayerState_O_Walk::PlayerState_O_Walk(const Player_WPtr& player, IGameManagerPtr gameManager)
	:PlayerState_O_MoveBase(player,gameManager)
{

}
//�e��ԓƎ��̏�����
void PlayerState_O_Walk::onUniqueInit()
{

}
//�X�V����
void PlayerState_O_Walk::onUpdate(float deltaTime)
{
	//�ړ�����
	PlayerState::move(deltaTime, 8.0f);
	//�A�[���̍X�V
	PlayerState::armUpdate();
}