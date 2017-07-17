#include"PlayerState.h"
#include <algorithm>
#include<GSmath.h>
#include"../../../Utility/MathSupport/MathSupport.h"
#include "../../../Map/Map.h"
#include"../../../Utility/FourDirection/FourDirection.h"
#include "../../../Define/Def_Nakayama.h"
#include"../../../Map/MapType.h"
#include "../../../ActorContains/Transform/Transform.h"

//コンストラクタ
PlayerState::PlayerState(const Player_WPtr& player, const IGameManagerPtr& gameManager)
	: p_Player(player)
	, p_GameManager(gameManager)
	, m_TransForm(*player.lock()->getTransform().get())
	, m_Parameter(player.lock()->getParameter())
	, p_Map(player.lock()->getWorld()->GetMap())
{
	p_Input = gameManager->GetInputState();
}

//パッド入力
void PlayerState::input() {}

//アーム更新
void PlayerState::armUpdate()
{
	//アームの回転処理
	m_Children[ActorName::Player_Arm]->setAngle(p_Player.lock()->getTransform()->m_Angle);
	//アームの座標更新処理
	m_Children[ActorName::Player_Arm]->setPosition(p_Player.lock()->getPosition() + p_Player.lock()->getTransform()->GetForward() * 16);
}
//移動処理
void PlayerState::move(float deltaTime, float speed)
{
	ResultPushDirection result;
	if (p_Input->PadVelocity().length() > 0.0f  && deltaTime > 0)
	{
		//入力ベクトル
		inputVelocity = p_Input->PadVelocity();
		if (inputVelocity.length() <= 0) return;

		FourDirection velocity = FourDirection(inputVelocity);

		//角度設定
		p_Player.lock()->setAngle(MathSupport::GetVec2ToVec2Angle(inputVelocity));

		//座標移動
		m_Position = p_Player.lock()->getPosition() + p_Input->PadVelocity() * speed * deltaTime;

		result = p_Map.lock()->PushForPlayer(p_Player.lock()->getPosition(), m_Position, MapType::Double, TerrainName::Wall);

		/******************************************************************************************************************************/
		/*追し出し処理*/
		m_Position = result.position;
		/*******************************************************************************************************************************/

		p_Player.lock()->setPosition(m_Position);
	}
}

//視野角内にいるか
bool PlayerState::is_Scorp_Angle(const Actor& other)
{
	//自分の方向ベクトル
	GSvector2 myVector = p_Player.lock()->getTransform()->GetForward();
	myVector.normalize();

	//相手のベクトル
	GSvector2 targetVector = other.getPosition() - (p_Player.lock()->getPosition() - p_Player.lock()->getTransform()->GetForward() * 16);
	targetVector.normalize();

	//自分と相手のベクトルからなす角を取る
	float result = myVector.innerDegree(targetVector);

	//視野角内(30度)にいるか？
	if (result <= 45.0f) {
		return true;
	}
	return false;
}

//テクスチャ名前変更
void PlayerState::TextureName_Change(const std::string& name)
{
	p_Player.lock()->setName_Animation(name);
}

//敵との衝突処理
void PlayerState::Collide(const Actor& other, const Body::ContactSet& contactSet)
{
	if (static_cast<int>(other.getName()) >= 101) {
		change(PlayerStateName::Damage);
	}
}

//
void PlayerState::Center_Adjustment()
{
	GSvector2 texCenter = GSvector2(14, 20);
	GSvector2 center = GSvector2(32, 32);
}