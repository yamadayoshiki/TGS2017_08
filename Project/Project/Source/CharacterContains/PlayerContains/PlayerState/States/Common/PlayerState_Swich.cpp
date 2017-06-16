#include"PlayerState_Swich.h"
#include"../../../../../WorldContains/EventMessage/EventMessage.h"
#include"../../../../../Utility/MathSupport/MathSupport.h"
#include "../../../../../ActorContains/Transform/Transform.h"

//コンストラクタ
PlayerState_Swich::PlayerState_Swich(const Player_WPtr& player, IGameManagerPtr gameManager)
	:PlayerState(player, gameManager)
	,m_Flag(false){
}

//各状態独自の初期化
void PlayerState_Swich::unique_init()
{
	m_Flag = false;
}

//更新処理
void PlayerState_Swich::update(float deltaTaime)
{
	if (m_Flag == true) {
		change(PlayerStateName::Rounds);
	}
	else {
		change(PlayerStateName::Close);
	}
}

//衝突判定
void PlayerState_Swich::collide(const Actor& other)
{
	//自分の方向ベクトル
	GSvector2 myVec = p_Player.lock()->getTransform()->GetForward();
	myVec.normalize();

	//相手のベクトル
	GSvector2 targetVec = other.getPosition() - p_Player.lock()->getPosition();
	targetVec.normalize();
	
	if (m_Children[ActorName::Player_Arm]->isCollide(other) && is_Scorp_Angle(other)) {
		m_Flag = true;
		//相手に挟んだ情報を送る
		p_Player.lock()->getWorld()->sendMessage(EventMessage::PLAYER_ROUNDS, const_cast<Actor&>(other));
	}
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