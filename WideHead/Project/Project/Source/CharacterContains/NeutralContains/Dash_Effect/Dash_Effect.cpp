#include "Dash_Effect.h"

#include"../../../Base/GameManagerContains/GameManager/GameManager.h"
#include"../../../Map/Map.h"
#include"../../../Map/MapType.h"
#include"../../../Utility/Rederer2D/Renderer2D.h"
#include"../../../ActorContains/Transform/Transform.h"
#include"../../../ActorContains/BodyContains/Elements/ContactSet/ContactSet.h"
#include"../../PlayerContains/Player/Player.h"
#include"../../../TextureContains/Texture/Texture.h"
#include "../../../Utility/Texture2DParameter/Texture2DParameter.h"
#include"../../../Utility/FourDirection/FourDirection.h"
#include"../../../Utility/MathSupport/MathSupport.h"

//コンストラクタ
Dash_Effect::Dash_Effect(IWorld * world, const GSvector2 & position, const GSvector2 & endposition, IGameManagerPtr gameManager, const Player_WPtr& player)
	:Actor(world, ActorName::AfterImage, position, gameManager, std::make_shared<Texture>("Player_AfterImage", gameManager->GetDrawManager(), DrawOrder::Effect_Back)) ,
	m_EndPosition(endposition),
	p_Player(player){
}

//デストラクタ
Dash_Effect::~Dash_Effect() {
}

//初期化
void Dash_Effect::onInitialize() {
	p_Texture->GetParameter()->m_Center = { 32.0f,32.0f };
	p_Transform->m_Angle = MathSupport::GetVec2ToVec2Angle(p_Player.lock()->getTransform()->GetForward());
	//スピード初期化
	m_Speed = 10.0f;
}

//更新処理
void Dash_Effect::onUpdate(float deltaTime)
{
	ResultPushDirection resultPush;
	GSvector2 setPos = p_Transform->m_Position += p_Player.lock()->getTransform()->GetForward() * m_Speed * deltaTime;

	/******************************************************************************************************************************/
	/*追し出し処理*/
	resultPush = p_World->GetMap()->PushForPlayer(p_Player.lock()->getPosition(), setPos, MapType::Double, TerrainName::Wall);
	/*******************************************************************************************************************************/

	setPosition(resultPush.position);

	//ダッシュ開始地点
	GSvector2 stratPos = getPosition();
	//開始地点から終点地点の距離を求める
	float result = stratPos.distance(m_EndPosition);

	if (p_World->GetMap()->IsInFrontOfTheWall(getPosition(), FourDirection(p_Player.lock()->getTransform()->GetForward()), MapType::Double)) {
		dead();
	}
	//結果
	if (result <= 10.0f) {
		p_Transform->m_Position = p_Player.lock()->getPosition();
		dead();
	}
}

//描画処理
void Dash_Effect::onDraw()const {
}
//衝突判定
void Dash_Effect::onCollide(Actor & other, const Body::ContactSet & contactSet){
	if (other.getName() == ActorName::BreakWall)
		p_Transform->m_Position += contactSet.m_SumVec;
	dead();
}
