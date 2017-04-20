#include"PlayerState.h"

//�R���X�g���N�^
PlayerState::PlayerState(GSvector2& position,GSmatrix4& matrix, GameManager* gameManager)
	:mPosition(position)
	,mMatrix(matrix)
	,mVelocity(GSvector2(0.0f,0.0f))
	,mAngle(0)
	,p_GameManager(gameManager)
	{
		p_Input = p_GameManager->GetInputState();
}

//�p�b�h����
void PlayerState::input() {}

////���[�V�����ύX
//void PlayerState::motion_change(Actor& actor, const PlayerStateID)
//{
//
//}
//�ړ�����
void PlayerState::move(Actor& actor, float deltaTime, float speed)
{
    mPosition += p_Input->PadVelocity() * speed;
}