#include"PlayerState_Walk.h"

//�R���X�g���N�^
PlayerState_Walk::PlayerState_Walk(const PlayerPtr& player, IGameManagerPtr gameManager)
	:PlayerState_MoveBase(player, gameManager) {

}
//�e��ԓƎ��̏�����
void PlayerState_Walk::onUniqueInit() {

}
//�X�V����
void PlayerState_Walk::onUpdate(float deltaTime)
{
	//�ړ�����
	move(deltaTime, 8.0f);
	//�A�[���̍X�V
	armUpdate();
}