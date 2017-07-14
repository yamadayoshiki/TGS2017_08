#include "PlayerState_Respawn.h"
#include"../../../../../ActorContains/ActorGroup.h"
#include"../../../../NeutralContains/Respawn_Effect/Respawn.h"

//コンストラクタ
PlayerState_Respawn::PlayerState_Respawn(const Player_WPtr & player, IGameManagerPtr gameManager)
	:PlayerState(player,gameManager)
{
}
//各状態独自の初期化
void PlayerState_Respawn::unique_init()
{
	m_FrameCounter = 0.0f;
	//TextureName_Change("Player_Invincible");
	p_Player.lock()->setPosition(m_Parameter.m_StratPosition);
	p_Player.lock()->getWorld()->addActor(ActorGroup::Effect, std::make_shared<Respawn>(p_Player.lock()->getWorld(), p_Player.lock()->getPosition(), p_GameManager));
}
//更新処理
void PlayerState_Respawn::update(float deltaTaime)
{
	if (m_FrameCounter >= 10) {
		change(PlayerStateName::Invincible);
	}
	m_FrameCounter += deltaTaime;
}

//入力処理
void PlayerState_Respawn::input(){
}