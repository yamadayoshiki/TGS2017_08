#include"PlayerState.h"
#include <algorithm>
#include<GSmath.h>


//�R���X�g���N�^
PlayerState::PlayerState(GSvector2& position, GSmatrix4& matrix, IGameManagerPtr gameManager)
	:mPosition(position)
	, mMatrix(matrix)
	, mVelocity(GSvector2(0.0f, 0.0f))
	, mAngle(0)
	, p_GameManager(gameManager)
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
	GSvector2 v1;
	GSvector2 v2;
	GSvector2 v;
	if (p_Input->PadVelocity().length() > 0.0f)
	{
		//���̓x�N�g��
		v2 = p_Input->PadVelocity();
		//��x�N�g��
		v1 = GSvector2(0.0f, -1.0f);
		//�O�ς����߂�
		float cross = v1.CCW(v2);
		//����
		float result = v1.normalize().dot(v2.normalize());
		//�x�N�g�����p�x�ɒu������
		mAngle = acosf(result);
		mAngle = mAngle * 180 / 3.14;

		//��������ւ�
		if (cross < 0)
			mAngle = -mAngle;
		//�p�x�ݒ�
		mMatrix.setRotationZ(mAngle);
		//���W�ړ�
		mPosition += p_Input->PadVelocity() * speed;
	}
	m_Children[ActorName::Player_Arm]->setMatrix(mMatrix);
	m_Children[ActorName::Player_Arm]->setPosition(mPosition - GSvector2(mMatrix.getAxisY()) * 16);
}

//�A�[���̎擾
void PlayerState::getArm(Actor& actor)
{
	//p_Arm = std::dynamic_pointer_cast<ArmPtr>(actor.findChildren(ActorName::Player_Arm));
}