#include"PlayerState_Walk.h"

//�R���X�g���N�^
PlayerState_Walk::PlayerState_Walk(GSvector2& position, GSmatrix4& matrix, const PlayerPtr& player, IGameManagerPtr gameManager)
	:PlayerState_MoveBase(position, matrix, player, gameManager) {

}
//�e��ԓƎ��̏�����
void PlayerState_Walk::onUniqueInit() {

}
//�X�V����
void PlayerState_Walk::onUpdate(float deltaTime)
{
	//if (p_Input->IsPadState(GS_XBOX_PAD_A)) {
	//	change(PlayerStateName::Run);
	//}
	//�ړ�����
	move(deltaTime, 1.0f);
}