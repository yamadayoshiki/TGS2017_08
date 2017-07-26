#include"PlayerState_Round.h"
#include"../../../../../WorldContains/EventMessage/EventMessage.h"
#include"../../../../../ActorContains/ActorGroup.h"
#include"../../../../NeutralContains/Repel_Effect/Repel_Effect.h"
#include "../../../../../ActorContains/BodyContains/Elements/ContactSet/ContactSet.h"
#include"../../../../../ActorContains/BodyContains/Factory/BodyFactory.h"
#include"../../../../../ActorContains/Transform/Transform.h"
//コンストラクタ
PlayerState_Round::PlayerState_Round(const Player_WPtr& player, IGameManagerPtr gameManager)
	:PlayerState(player, gameManager)
{

}
//各状態独自の初期化
void PlayerState_Round::unique_init()
{
	TextureName_Change("Player_Clip");
	gsPlaySE(SE_PLAYER_CLIP);
	p_Player.lock()->getWorld()->GetBodyFactory()->Transform(p_Player.lock()->getBody(), Body::BodyDataName::Player_Clip);
}
//更新処理
void PlayerState_Round::update(float deltaTime)
{

}
//衝突判定
void PlayerState_Round::collide(const Actor& other, const Body::ContactSet& contactSet)
{
	if (m_Children[ActorName::Player_Arm]->isCollide(other).m_IsCollide && other.getName() != ActorName::Enemy_01) {
		GSvector2 enePos = other.getPosition();
		GSvector2 playPos = m_Children[ActorName::Player_Arm]->getPosition();
		float distance = playPos.distance(enePos);
		if (distance >= 8.0f && p_Player.lock()->getParameter().getClipFlag() == true) {
			GSvector2 pos = p_Player.lock()->getPosition() + contactSet.m_SumVec;
			p_Player.lock()->setPosition(pos);
		}
		return;
	}

	p_Player.lock()->getWorld()->sendMessage(EventMessage::PLAYER_RELEASE);

	//敵との衝突処理
	Collide(other, contactSet);
}
//終了処理
void PlayerState_Round::end()
{

}
//入力処理
void PlayerState_Round::input()
{
	//潰す状態に遷移
	if (p_Input->IsPadStateTrigger(GS_XBOX_PAD_Y)) {
		change(PlayerStateName::Crush);
	}
	//離す状態に遷移
	if (p_Input->IsPadStateTrigger(GS_XBOX_PAD_B)) {
		p_Player.lock()->getWorld()->sendMessage(EventMessage::PLAYER_RELEASE);
		change(PlayerStateName::Release);
	}
}

//メッセージ処理
void PlayerState_Round::handleMessage(EventMessage massege, void * param)
{
	switch (massege)
	{
	case EventMessage::PLAYER_ROUNDSLOST:
		change(PlayerStateName::Close);
		p_Player.lock()->getParameter().m_ClipFlag = false;
		break;
	case EventMessage::ENEMY_REPEL:
		p_Player.lock()->getWorld()->addActor(ActorGroup::Effect,
			std::make_shared<Repel_Effect>(
				p_Player.lock()->getWorld(), p_Player.lock()->getPosition(), p_GameManager));
		p_Player.lock()->getParameter().m_ClipFlag = false;
		change(PlayerStateName::Idle);
		break;
	}
}

