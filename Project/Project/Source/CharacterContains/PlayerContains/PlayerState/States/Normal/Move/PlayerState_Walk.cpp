#include"PlayerState_Walk.h"

//�R���X�g���N�^
PlayerState_Walk::PlayerState_Walk(GSvector2& position,GSmatrix4& matrix, GameManager* gameManager)
	:PlayerState_MoveBase(position,matrix,gameManager){

}
//�e��ԓƎ��̏�����
void PlayerState_Walk::onUniqueInit(Actor& actor) {

}
//�X�V����
void PlayerState_Walk::onUpdate(Actor& actor, float deltaTime)
{
	//if (p_Input->IsPadState(GS_XBOX_PAD_A)) {
	//	change(PlayerStateName::Run);
	//}
	//�ړ�����
	move(actor, deltaTime, 1.0f);
}