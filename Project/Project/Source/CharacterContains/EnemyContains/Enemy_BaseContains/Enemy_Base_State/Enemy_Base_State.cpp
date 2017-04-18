#include "Enemy_Base_State.h"

#include "../../../../WorldContains/World/World.h"

//�R���X�g���N�^
Enemy_Base_State::Enemy_Base_State(GSvector2& position)
	:m_Position(position)
	, m_Velocity(GSvector2(0.0f, 0.0f))
	, m_Angle(0.0f)
{
}

//�ړ�����
void Enemy_Base_State::Move(Actor& actor, float deltaTime, float speed)
{
	//���x�����W�ɉ��Z
	m_Position += m_Velocity * speed;
}