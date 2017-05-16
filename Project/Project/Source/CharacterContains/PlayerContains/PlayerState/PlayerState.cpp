#include"PlayerState.h"
#include <algorithm>
#include<GSmath.h>
#include"../../../Utility/MathSupport/MathSupport.h"


//コンストラクタ
PlayerState::PlayerState(const PlayerPtr& player, const IGameManagerPtr& gameManager)
	: p_Player(player)
	, p_GameManager(gameManager)
	, m_TransForm(player->getTransform())
	, m_Parameter(player->getParameter())
{
	p_Input = gameManager->GetInputState();
}

//パッド入力
void PlayerState::input() {}

////モーション変更
//void PlayerState::motion_change(Actor& other, const PlayerStateID)
//{
//
//}

//アーム更新
void PlayerState::armUpdate()
{
	//アームの回転処理
	m_Children[ActorName::Player_Arm]->setAngle(m_TransForm.m_Angle);
	//アームの座標更新処理
	m_Children[ActorName::Player_Arm]->setPosition(m_TransForm.m_Position + p_Player->getBody()->forward() * 16);
}
//移動処理
void PlayerState::move(float deltaTime, float speed)
{
	if (p_Input->PadVelocity().length() > 0.0f)
	{
		//入力ベクトル
		inputVelocity = p_Input->PadVelocity();

		//角度設定
		p_Player->setAngle(MathSupport::GetAngle(inputVelocity));

		//座標移動
		m_Position = m_TransForm.m_Position + p_Input->PadVelocity() * speed * deltaTime;
		p_Player->setPosition(m_Position);
	}
	//armUpdate();
}