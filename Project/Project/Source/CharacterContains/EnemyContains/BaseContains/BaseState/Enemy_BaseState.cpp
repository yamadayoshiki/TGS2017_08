#include "Enemy_BaseState.h"

#include "../../../../WorldContains/World/World.h"

//�R���X�g���N�^
Enemy_BaseState::Enemy_BaseState(GSvector2& position, GSmatrix4& rotate)
	: m_Position(position)
	, m_Rotate(rotate)
	, m_Velocity(GSvector2(0.0f, 0.0f))
	, m_Angle(0.0f)
{
}

//�ړ�����(������)
void Enemy_BaseState::Move(Actor& actor, float deltaTime, float speed)
{
	//���x�����W�ɉ��Z
	m_Position += m_Velocity * speed;
}