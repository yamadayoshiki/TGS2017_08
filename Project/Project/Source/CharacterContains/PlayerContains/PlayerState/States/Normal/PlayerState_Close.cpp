#include"PlayerState_Close.h"

//コンストラクタ
PlayerState_Close::PlayerState_Close(const Player_WPtr& player, IGameManagerPtr gameManager)
	:PlayerState(player, gameManager)
{

}

//各状態独自の初期化
void PlayerState_Close::unique_init()
{
	m_Parameter.m_ChargeConter = 0.0f;
	TextureName_Change("Player_Close");
	gsPlaySE(SE_PLAYER_ARM);
}

//更新処理
void PlayerState_Close::update(float deltaTaime)
{
	if (p_Player.lock()->GetLoopCount() > 0)
		change(PlayerStateName::Walk);
	move(deltaTaime);
}

//衝突判定
void PlayerState_Close::collide(const Actor& other)
{
	Collide(other);
}

//終了処理
void PlayerState_Close::end()
{

}