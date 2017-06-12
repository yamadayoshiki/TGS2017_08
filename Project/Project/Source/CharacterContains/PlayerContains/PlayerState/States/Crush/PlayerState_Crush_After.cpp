#include "PlayerState_Crush_After.h"
#include"../../../../../Utility/Score/Score.h"

//コンストラクタ
PlayerState_Crush_After::PlayerState_Crush_After(const Player_WPtr & player, IGameManagerPtr gameManager)
:PlayerState(player,gameManager){
}

//初期化
void PlayerState_Crush_After::unique_init()
{
	TextureName_Change("Player_Close");
	p_GameManager->GetScore()->AddScore(100 + m_Parameter.addBonus());
	m_FrameCounter = 0.0f;
}

//更新
void PlayerState_Crush_After::update(float deltaTime)
{
	if (m_FrameCounter >= 10) {
		change(PlayerStateName::Idle);
	}
	m_FrameCounter += deltaTime;
}
