#include"PlayerState_Run.h"

//�R���X�g���N�^
PlayerState_Run::PlayerState_Run(GSvector2& pos)
	:PlayerState_MoveBase(pos){

}
//�e��ԓƎ��̏�����
void PlayerState_Run::onUniqueInit(Actor& actor)
{

}
//�X�V����
void PlayerState_Run::onUpdate(Actor& actor, float deltaTime)
{
	//�ړ�����
	move(actor, deltaTime, 1.5f);
}