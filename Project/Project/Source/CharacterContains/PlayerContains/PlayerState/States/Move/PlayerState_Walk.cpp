#include"PlayerState_Walk.h"

//�R���X�g���N�^
PlayerState_Walk::PlayerState_Walk(GSvector2& pos)
	:PlayerState_MoveBase(pos){

}
//�e��ԓƎ��̏�����
void PlayerState_Walk::onUniqueInit(Actor& actor) {

}
//�X�V����
void PlayerState_Walk::onUpdate(Actor& actor, float deltaTime)
{
	//�ړ�����
	move(actor, deltaTime, 1.0f);
}