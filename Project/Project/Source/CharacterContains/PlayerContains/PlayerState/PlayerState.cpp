#include"PlayerState.h"

//�R���X�g���N�^
PlayerState::PlayerState(GSvector2& pos)
	:mPosition(pos),mVelocity(GSvector2(0.0f,0.0f)),mAngle(0)
{}
//�p�b�h����
void PlayerState::input() {}

//���[�V�����ύX
void PlayerState::motion_change(Actor& actor, const PlayerStateID)
{

}
//�ړ�����
void PlayerState::move(Actor& actor, float deltaTime, float speed = 1.0f)
{
	mPosition += mVelocity * speed;
}
//�o������(�p�b�h)
bool PlayerState::aweke_pad()
{

}