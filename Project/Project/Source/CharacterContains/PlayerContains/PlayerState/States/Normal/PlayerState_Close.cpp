#include"PlayerState_Close.h"

//コンストラクタ
PlayerState_Close::PlayerState_Close(const Player_WPtr& player, IGameManagerPtr gameManager)
	:PlayerState(player, gameManager)
{

}

//各状態独自の初期化
void PlayerState_Close::unique_init()
{
	TextureName_Change("Player2");
}

//更新処理
void PlayerState_Close::update(float deltaTaime)
{
	if (p_Player.lock()->GetLoopCount() < 1)
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