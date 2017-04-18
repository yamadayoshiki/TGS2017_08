#include "Enemy_Base_State.h"

#include "../../../../WorldContains/World/World.h"

//コンストラクタ
Enemy_Base_State::Enemy_Base_State(GSvector2& position)
	:m_Position(position)
	, m_Velocity(GSvector2(0.0f, 0.0f))
	, m_Angle(0.0f)
{
}

//移動処理
void Enemy_Base_State::Move(Actor& actor, float deltaTime, float speed)
{
	//速度を座標に加算
	m_Position += m_Velocity * speed;
}