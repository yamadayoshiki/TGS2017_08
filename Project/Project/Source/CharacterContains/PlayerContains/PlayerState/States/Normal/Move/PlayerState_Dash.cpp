#include"PlayerState_Dash.h"


//コンストラクタ
PlayerState_Dash::PlayerState_Dash(GSvector2& position, GSmatrix4& matrix, const PlayerPtr& player, IGameManagerPtr gameManager)
	:PlayerState_MoveBase(position,matrix,player,gameManager)
{

}
//各状態独自の初期化
void PlayerState_Dash::onUniqueInit()
{
	//Playerの方向ベクトル
	m_Direction = m_TransForm.m_Position.createFromDirection(m_TransForm.m_Angle);
	m_distance = m_TransForm.m_Position + m_Direction * 64.0f;
}
//更新処理
void PlayerState_Dash::onUpdate(float deltaTime)
{
	m_TransForm.m_Position += m_Direction * 64;
	change(PlayerStateName::Idle);

}
//衝突処理
void PlayerState_Dash::onCollide(const Actor& other)
{

}