#include"Arm.h"
#include "../../../Define/Def_Nakayama.h"
#include "../../../ActorContains/Transform/Transform.h"
#include "../../../ActorContains/BodyContains/Elements/ContactSet/ContactSet.h"
#include"../../../WorldContains/EventMessage/EventMessage.h"
#include"../../../Base/GameManagerContains/GameManager/GameManager.h"
#include"../../../Utility/InputState/InputState.h"
#include"../Player/Player_Parameter.h"

//コンストラクタ
Arm::Arm(IWorld* world, GSvector2& position, IGameManagerPtr gameManager)
	:Actor(world
		, ActorName::Player_Arm
		, position
		, gameManager
		, std::make_shared<NullTexture>()
		, Body::MotionType::Player
		, Body::BodyDataName::PlayerAttackRange)
	, m_Angle(0.0f)
	, mHitFlag(false)
{

}
//デストラクタ
Arm::~Arm()
{

}
//更新処理
void Arm::onUpdate(float deltaTime) {
	//p_Transform->m_Position = getPosition().clamp(GSvector2(16.0f, 16.0f), GSvector2(1280 - 16, 960 - 16));
}
//描画処理
void Arm::onDraw()const
{
	//Actor::onDraw();
}
//衝突判定
void Arm::onCollide(Actor& other, const Body::ContactSet& contactSet)
{
	if (p_GameManager->GetInputState()->IsPadState(GS_XBOX_PAD_B))return;
	GSvector2 ArmPos = getPosition();
	GSvector2 EnePos = other.getPosition();
	float distance = ArmPos.distance(EnePos);
	if (isCollide(other).m_IsCollide && is_Scorp_Angle(other) && distance <= 8.0f) {
		//相手に挟んだ情報を送る
		p_World->sendMessageOne(EventMessage::PLAYER_ROUNDS, const_cast<Actor&>(other));
		p_World->sendMessage(EventMessage::PLAYER_ROUNDS, *(p_World->findActor(ActorName::UI_ALL).get()));
		//距離ベクトルを取得
		GSvector2 dis = other.getPosition() - p_GameManager->GetPlayerParameter().getPosition();
		//X軸を合わせる
		if (fabs(dis.x) > fabs(dis.y))
			p_GameManager->GetPlayerParameter().setPosition(GSvector2(p_GameManager->GetPlayerParameter().getPosition().x, other.getPosition().y));
		//Y軸を合わせる
		else
			p_GameManager->GetPlayerParameter().setPosition(GSvector2(other.getPosition().x, p_GameManager->GetPlayerParameter().getPosition().y));
		p_GameManager->GetPlayerParameter().m_ClipFlag = true;
	}
}

//視野角内にいるか
bool Arm::is_Scorp_Angle(const Actor& other)
{
	//自分の方向ベクトル
	GSvector2 myVector = p_Transform->GetForward();
	myVector.normalize();

	//相手のベクトル
	GSvector2 targetVector = other.getPosition() - (p_GameManager->GetPlayerParameter().getPosition() - p_Transform->GetForward() * 32);
	targetVector.normalize();

	//自分と相手のベクトルからなす角を取る
	float result = myVector.innerDegree(targetVector);

	//視野角内(30度)にいるか？
	if (result <= 45.0f) {
		return true;
	}
	return false;
}