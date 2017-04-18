#include "Enemy_BaseState.h"

#include "../../../../WorldContains/World/World.h"

//コンストラクタ
Enemy_BaseState::Enemy_BaseState(GSvector2& position, GSmatrix4& rotate)
	: m_Position(position)
	, m_Rotate(rotate)
	, m_Velocity(GSvector2(0.0f, 0.0f))
	, m_Angle(0.0f)
{
}

//移動処理(未実装)
void Enemy_BaseState::Move(Actor& actor, float deltaTime, float speed)
{
	//速度を座標に加算
	m_Position += m_Velocity * speed;
}