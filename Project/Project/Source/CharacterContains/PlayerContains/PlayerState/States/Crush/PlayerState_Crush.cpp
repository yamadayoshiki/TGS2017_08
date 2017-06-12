#include "PlayerState_Crush.h"
#include"../../../../../WorldContains/EventMessage/EventMessage.h"

PlayerState_Crush::PlayerState_Crush(const Player_WPtr& player, IGameManagerPtr gameManager)
	:PlayerState(player, gameManager)
{
}
//各状態独自の初期化
void PlayerState_Crush::unique_init()
{
	gsPlaySE(SE_PLAYER_CRUSH);
	p_Player.lock()->getWorld()->sendMessage(EventMessage::PLAYER_CRUSH,(void*)m_Parameter.getChargePower());
	p_GameManager->GetPlayerParameter().addCombo();
}
//更新処理
void PlayerState_Crush::update(float deltaTime)
{
	change(PlayerStateName::Rounds);
}
//衝突判定
void PlayerState_Crush::collide(const Actor& other)
{
	//アームに当たっているかつ視野角内なら返す
	if (m_Children[ActorName::Player_Arm]->isCollide(other) && is_Scorp_Angle(other))return;
	//敵との衝突処理
	Collide(other);
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
		change(PlayerStateName::Crush_After);
		break;

	case EventMessage::ENEMY_REPEL:
		change(PlayerStateName::Idle);
		break;
	}
}