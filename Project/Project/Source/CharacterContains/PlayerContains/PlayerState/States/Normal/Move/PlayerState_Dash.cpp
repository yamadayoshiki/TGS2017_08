#include"PlayerState_Dash.h"

#include "../../../../../../Define/Def_Nakayama.h"

//コンストラクタ
PlayerState_Dash::PlayerState_Dash(const Player_WPtr& player, IGameManagerPtr gameManager)
	:PlayerState(player, gameManager)
{

}
//各状態独自の初期化
void PlayerState_Dash::unique_init()
{
	//アニメーション画像の変更
	TextureName_Change("Player_Close");
	//フレームカウンターの初期化
	m_FramConter = 0.0f;
	//スピード初期化
	speed = 32.0f;
	//Playerの方向ベクトル
	m_Direction = p_Player.lock()->getBody()->forward();
	//エンド地点の設定
	endPos = p_Player.lock()->getTransform().m_Position + m_Direction * (64 * 4);
	
	m_Flag = false;
}
//更新処理
void PlayerState_Dash::update(float deltaTime)
{
	GSvector2 setPos = p_Player.lock()->getTransform().m_Position += m_Direction * speed * deltaTime;

	/******************************************************************************************************************************/
	/*追し出し処理*/
	setPos = p_Map.lock()->PushForPlayer(p_Player.lock()->getPosition(), setPos);
	/*******************************************************************************************************************************/

	p_Player.lock()->setPosition(setPos);
	//if (speed >= 8.0f && m_FramConter > 3) {
	//	speed = speed / 2.0f;
	//}
	armUpdate();
	GSvector2 pos = p_Player.lock()->getPosition();
	float result = pos.distance(endPos);
	if (result <= 1.0f) {
		change(PlayerStateName::Walk);
	}
	if (p_Map.lock()->IsInFrontOfTheWall(p_Player.lock()->getPosition(), FourDirection(p_Player.lock()->getBody()->forward()), MapType::Double)
		|| m_FramConter >= 30) {
		change(PlayerStateName::Walk);
	}

	m_FramConter += deltaTime;
}
//衝突処理
void PlayerState_Dash::collide(const Actor& other)
{
	//アームに当たっていたら返す
	if (m_Children[ActorName::Player_Arm]->isCollide(other) &&
		is_Scorp_Angle(other)&&
		m_Flag == true) return;

	//敵との衝突処理
	Collide(other);
}
//入力処理
void PlayerState_Dash::input()
{
	if (p_Input->IsPadStateTrigger(GS_XBOX_PAD_B)) {
		TextureName_Change("Player_Open");
		m_Flag = true;
	}
	if (p_Input->IsPadStatesDetach(GS_XBOX_PAD_B) && m_Flag == true) {
		change(PlayerStateName::Swich);
	}
}
