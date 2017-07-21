#include"PlayerState_Swich.h"
#include"../../../../../WorldContains/EventMessage/EventMessage.h"
#include"../../../../../Utility/MathSupport/MathSupport.h"
#include "../../../../../ActorContains/Transform/Transform.h"
#include "../../../../../ActorContains/BodyContains/Elements/ContactSet/ContactSet.h"
//コンストラクタ
PlayerState_Swich::PlayerState_Swich(const Player_WPtr& player, IGameManagerPtr gameManager)
	:PlayerState(player, gameManager)
	, m_Flag(false) {
}

//各状態独自の初期化
void PlayerState_Swich::unique_init()
{
	m_Flag = false;
}

//更新処理
void PlayerState_Swich::update(float deltaTaime)
{
	if (p_Player.lock()->getParameter().getClipFlag() == true) {
		change(PlayerStateName::Rounds);
	}
	else {
		change(PlayerStateName::Close);
	}
}

//衝突判定
void PlayerState_Swich::collide(const Actor& other, const Body::ContactSet& contactSet){
}

//メッセージ処理
void PlayerState_Swich::handleMessage(EventMessage message, void * param)
{
	switch (message)
	{
	case EventMessage::ENEMY_REPEL:
		change(PlayerStateName::Idle);
		break;
	}
}