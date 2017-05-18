#include"PlayerState.h"
#include <algorithm>
#include<GSmath.h>
#include"../../../Utility/MathSupport/MathSupport.h"
#include "../../../Map/Map.h"
#include"../../../Utility/FourDirection/FourDirection.h"
#include "../../../Define/Def_Nakayama.h"

//コンストラクタ
PlayerState::PlayerState(const PlayerPtr& player, const IGameManagerPtr& gameManager)
	: p_Player(player)
	, p_GameManager(gameManager)
	, m_TransForm(player->getTransform())
	, m_Parameter(player->getParameter())
	, m_Map(player->getWorld()->GetMap()) 
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
	m_Children[ActorName::Player_Arm]->setAngle(p_Player->getTransform().m_Angle);
	//アームの座標更新処理
	m_Children[ActorName::Player_Arm]->setPosition(p_Player->getTransform().m_Position + p_Player->getBody()->forward() * 16);
}
//移動処理
void PlayerState::move(float deltaTime, float speed)
{
	if (p_Input->PadVelocity().length() > 0.0f)
	{
		//入力ベクトル
		inputVelocity = p_Input->PadVelocity();
		if (inputVelocity.length() <= 0) return;

		FourDirection velocity = FourDirection(inputVelocity);


		//if (frontWall.Flag() == 1) {
		//	return;
		//}

		//角度設定
		p_Player->setAngle(MathSupport::GetVec2ToVec2Angle(inputVelocity));

		//座標移動
		m_Position = p_Player->getTransform().m_Position + p_Input->PadVelocity() * speed * deltaTime;
		
		/******************************************************************************************************************************/
		/*追し出し処理*/
		m_Position = m_Map.PushForPlayer(p_Player->getPosition(), m_Position);
		/*******************************************************************************************************************************/

		p_Player->setPosition(m_Position);
	}
	//armUpdate();
}