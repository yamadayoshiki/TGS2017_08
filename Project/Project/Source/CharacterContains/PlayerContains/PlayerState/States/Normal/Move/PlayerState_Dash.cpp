#include"PlayerState_Dash.h"


//コンストラクタ
PlayerState_Dash::PlayerState_Dash(const PlayerPtr& player, IGameManagerPtr gameManager)
	:PlayerState(player, gameManager)
{

}
//各状態独自の初期化
void PlayerState_Dash::unique_init()
{
	//フレームカウンターの初期化
	m_FrameCounter = 0.0f;
	//スピード初期化
	speed = 32.0f;
	//Playerの方向ベクトル
	m_Direction = p_Player->getBody()->forward();
	//スタート地点の設定
	startPos = p_Player->getTransform().m_Position;;
	//エンド地点の設定
	endPos	 = p_Player->getTransform().m_Position + m_Direction * (64 * 4);
	//2点間の距離
	m_Distance = startPos.distance(endPos);
}
//更新処理
void PlayerState_Dash::update(float deltaTime)
{
	GSvector2 setPos = p_Player->getTransform().m_Position += m_Direction * speed * deltaTime;
	p_Player->setPosition(setPos);
	if (speed >= 8.0f && m_FrameCounter > 3) {
		speed = speed / 2.0f;
	}
	armUpdate();
	GSvector2 pos = p_Player->getPosition();
	float result = pos.distance(endPos);
	if (result <= 1.0f) {
		change(PlayerStateName::Walk);
	}
	else if (m_FrameCounter > 30) {
		change(PlayerStateName::Walk);
	}
	m_FrameCounter += deltaTime;
}
//衝突処理
void PlayerState_Dash::collide(const Actor& other)
{
	if (m_FrameCounter > 8) {
		//敵との衝突処理
		change(PlayerStateName::Idle);
	}
}