#include "PlayerState_Crush.h"
#include"../../../../../WorldContains/EventMessage/EventMessage.h"

PlayerState_Crush::PlayerState_Crush(const PlayerPtr& player, IGameManagerPtr gameManager)
	:PlayerState(player, gameManager)
{
}
//各状態独自の初期化
void PlayerState_Crush::unique_init()
{
	p_Player->getWorld()->sendMessage(EventMessage::PLAYER_CRUSH);
}
//更新処理
void PlayerState_Crush::update(float deltaTime)
{
	p_Player->getWorld()->sendMessage(EventMessage::PLAYER_ROUNDS);
}
//衝突判定
void PlayerState_Crush::collide(const Actor& other)
{
	//自分の方向ベクトル
	GSvector2 myVec = p_Player->getBody()->forward();
	myVec.normalize();

	//相手のベクトル
	GSvector2 targetVec = other.getPosition() - p_Player->getPosition();
	targetVec.normalize();
	//アームに当たっているかつ視野角内なら返す
	if (m_Children[ActorName::Player_Arm]->isCollide(other) && is_Scorp_Angle(myVec, targetVec))return;

	if (other.getName() == ActorName::Enemy_01) change(PlayerStateName::Damage);
}

//メッセージ処理
void PlayerState_Crush::handleMessage(EventMessage massege, void* param)
{
	switch (massege)
	{
	case EventMessage::PLAYER_ROUNDS:
		change(PlayerStateName::Rounds);
		break;

	case EventMessage::PLAYER_ROUNDSLOST:
		change(PlayerStateName::Close);
		break;
	}
}