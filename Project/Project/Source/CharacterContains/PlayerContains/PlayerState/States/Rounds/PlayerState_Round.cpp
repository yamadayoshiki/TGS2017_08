#include"PlayerState_Round.h"
#include"../../../../../WorldContains/EventMessage/EventMessage.h"

//コンストラクタ
PlayerState_Round::PlayerState_Round(const Player_WPtr& player, IGameManagerPtr gameManager)
	:PlayerState(player, gameManager)
{

}
//各状態独自の初期化
void PlayerState_Round::unique_init()
{
	TextureName_Change("Player_Clip");
}
//更新処理
void PlayerState_Round::update(float deltaTime)
{

}
//衝突判定
void PlayerState_Round::collide(const Actor& other)
{
	if (m_Children[ActorName::Player_Arm]->isCollide(other))return;

	//敵との衝突処理
	Collide(other);
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
		break;
	case EventMessage::ENEMY_REPEL:
		change(PlayerStateName::Idle);
		break;
	}
}

